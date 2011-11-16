// File:	BRepFill_SectionPlacement.cxx
// Created:	Wed Feb 11 16:23:18 1998
// Author:	Philippe MANGIN
//		<pmn@sgi29>


#include <BRepFill_SectionPlacement.ixx>

#include <TopExp_Explorer.hxx>
#include <TopExp.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS.hxx>
#include <BRep_Tool.hxx>
#include <BRepAdaptor_HCurve.hxx>
#include <BRepAdaptor_HCompCurve.hxx>
#include <BRepExtrema_DistShapeShape.hxx>
#include <BRepExtrema_SupportType.hxx>

#include <Geom_Curve.hxx>
#include <Geom_CartesianPoint.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Line.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomConvert_CompCurveToBSplineCurve.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <GeomFill_SectionPlacement.hxx>
#include <GeomFill_LocationLaw.hxx>

#include <Standard_ConstructionError.hxx>
#include <Standard_NotImplemented.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Precision.hxx>

#if DEB
static Standard_Boolean myDebug = Standard_False;
#endif

static Standard_Real SearchParam(const Handle(BRepFill_LocationLaw)& Law,
				 const Standard_Integer Ind,
				 const TopoDS_Vertex& TheV)
{
  Standard_Real t;
  TopoDS_Edge E;
  E = Law->Edge(Ind);
  t = BRep_Tool::Parameter(TheV, E);
  if (E.Orientation() == TopAbs_REVERSED) {
    Standard_Real f, l, Lf, Ll;
    Handle(Geom_Curve) C;
    C = BRep_Tool::Curve(E,f,l);
    Lf = Law->Law(Ind)->GetCurve()->FirstParameter();
    Ll = Law->Law(Ind)->GetCurve()->LastParameter();
    t = Ll - (t-f)*(Ll-Lf)/(l-f);
  }
  return t;
}
				 
				 

BRepFill_SectionPlacement::
BRepFill_SectionPlacement(const Handle(BRepFill_LocationLaw)& Law,
			  const TopoDS_Shape& Section,
			  const Standard_Boolean WithContact,
			  const Standard_Boolean WithCorrection) :
			  myLaw(Law), mySection(Section)
{
 TopoDS_Vertex VNull;
 VNull.Nullify();
 Perform(WithContact, WithCorrection, VNull);
}

BRepFill_SectionPlacement::
BRepFill_SectionPlacement(const Handle(BRepFill_LocationLaw)& Law,
			  const TopoDS_Shape& Section,
			  const TopoDS_Shape& Vertex,
			  const Standard_Boolean WithContact,
			  const Standard_Boolean WithCorrection) :
			  myLaw(Law), mySection(Section)
{
 Perform(WithContact, WithCorrection, Vertex);
}

 void BRepFill_SectionPlacement::Perform(const Standard_Boolean WithContact,
					 const Standard_Boolean WithCorrection,
					 const TopoDS_Shape& Vertex) 
{
  TopoDS_Vertex TheV; 
  TheV = TopoDS::Vertex(Vertex);
  Standard_Integer ii; 
  Standard_Integer Ind1 = 0, Ind2 = 0;
  Standard_Boolean Bof, isVertex = Standard_False;
  Standard_Real First = 0.0, Last = 0.0;
  TopExp_Explorer Ex;
  TopoDS_Edge E;
  TopoDS_Vertex V;
  Handle(Geom_Curve) C;
  Handle(Geom_TrimmedCurve) TC; 

  // modified by NIZHNY-OCC629  Thu Jul 24 14:11:45 2003
  Standard_Boolean isFound = Standard_False;
  Ex.Init(mySection, TopAbs_EDGE);
  for(; Ex.More(); Ex.Next()) {
    E = TopoDS::Edge(Ex.Current());
    // avoid null, degenerated edges
    if( E.IsNull() || BRep_Tool::Degenerated(E) ) continue;
    C = BRep_Tool::Curve(E, First, Last);
    if( C.IsNull() ) continue;
    isFound = Standard_True;
    break;
  }
  if( !isFound )
    isVertex = Standard_True;
  else
    {
      TC = new (Geom_TrimmedCurve)(C, First, Last);
      Ex.Next();
      
      if( Ex.More() ) {
	Standard_Real tolrac, epsV, tol = Precision::Confusion();
	GeomConvert_CompCurveToBSplineCurve Conv(TC);
	for (; Ex.More(); Ex.Next()) {
	  E = TopoDS::Edge(Ex.Current());
	  // avoid null, degenerated edges
	  if( E.IsNull() || BRep_Tool::Degenerated(E) ) continue;
	  TopoDS_Vertex VFirst, VLast;
	  TopExp::Vertices(E,VFirst, VLast);
	  epsV = Max(BRep_Tool::Tolerance(VFirst), BRep_Tool::Tolerance(VLast));
	  C = BRep_Tool::Curve(E, First, Last);
	  if( C.IsNull() ) continue;
	  TC = new (Geom_TrimmedCurve)(C, First, Last);
	  tolrac = Min(tol,epsV);
	  Bof = Conv.Add(TC, tolrac);
	  if (!Bof) {
	    tolrac = Max(tol,epsV);
	    Bof = Conv.Add(TC, tolrac);
	  }
	}
	C = Conv.BSplineCurve();
      }
      else C = TC; // On garde l'unique courbe
    }

  // modified by NIZHNY-629  Fri Jul 25 11:10:27 2003 b

//   // section ponctuelle
//  Ex.Init(mySection, TopAbs_EDGE);
//   Standard_Boolean isPonctual = Standard_False;
//  if (Ex.More()) {
//    E = TopoDS::Edge(Ex.Current());
//    isPonctual = BRep_Tool::Degenerated(E);
//  }

//   Ex.Init(mySection, TopAbs_EDGE);
//   if (Ex.More()&&!isPonctual) { 
//     E = TopoDS::Edge(Ex.Current());
//     C = BRep_Tool::Curve(E, First, Last);
//     TC = new (Geom_TrimmedCurve)(C, First, Last);
//     Ex.Next();
//     if (Ex.More()) { // On essai d'avoir un echantillon representatif
//       Standard_Real tolrac, epsV, tol = Precision::Confusion();
//       GeomConvert_CompCurveToBSplineCurve Conv(TC);
//       for (; Ex.More(); Ex.Next()) {
// 	E = TopoDS::Edge(Ex.Current());
// 	TopoDS_Vertex VFirst, VLast;
// 	TopExp::Vertices(E,VFirst, VLast);
// 	epsV = Max(BRep_Tool::Tolerance(VFirst), BRep_Tool::Tolerance(VLast));
// 	C = BRep_Tool::Curve(E, First, Last);
// 	TC = new (Geom_TrimmedCurve)(C, First, Last);
// 	tolrac = Min(tol,epsV);
// 	Bof = Conv.Add(TC, tolrac);
// 	if (!Bof) {
// 	  tolrac = Max(tol,epsV);
// 	  Bof = Conv.Add(TC, tolrac);
// 	}
//       }
//       C = Conv.BSplineCurve();
//     }
//     else C = TC; // On garde l'unique courbe
//   }
//   else {
//     // Localisation par distance Shape/Shape
//     Standard_Real Tpos;
//     BRepExtrema_DistShapeShape Ext(mySection, myLaw->Wire());
    
//     if (! Ext.IsDone()) 
//        Standard_ConstructionError::Raise("Distance Vertex/Spine");

//     if (Ext.SupportTypeShape2(1) == BRepExtrema_IsOnEdge) {
//       TopoDS_Shape sbis = Ext.SupportOnShape2(1);
//       E = TopoDS::Edge(sbis);
//       Ext.ParOnEdgeS2(1, Tpos); 
//     }
//     else {
//       TopoDS_Vertex Vf, Vl,V;
//       TopoDS_Shape sbis = Ext.SupportOnShape2(1);
//       V = TopoDS::Vertex(sbis);
//       for (ii=1, Ind1=0 ; ii<=myLaw->NbLaw(); ii++) {
// 	E = myLaw->Edge(ii);
// 	TopExp::Vertices(E, Vf, Vl);
// 	if ((V.IsSame(Vf)) || (V.IsSame(Vl))) {
// 	  if (Ind1 == 0) Ind1 = ii;
// 	  else Ind2 = ii;
// 	}
//       }
      
//       // On invente une section
//       gp_Dir D(0, 0, 1);
//       gp_Pnt Origine, PV;
//       Origine = BRep_Tool::Pnt(V);
//       Standard_Real length;

//       if (Ext.SupportTypeShape1(1) == BRepExtrema_IsVertex) {
// 	TopoDS_Shape aLocalShape = Ext.SupportOnShape1(1);
//         PV = BRep_Tool::Pnt(TopoDS::Vertex(aLocalShape));
// //        PV = BRep_Tool::Pnt(TopoDS::Vertex(Ext.SupportOnShape1(1)));
//       }
//       else {
//         PV = BRep_Tool::Pnt(TopoDS::Vertex(mySection));
//       }
//       length = Origine.Distance(PV);
//       if (length > Precision::Confusion()) {
// 	gp_Vec theVec(Origine, PV);
// 	D.SetXYZ(theVec.XYZ());
//       }
//       else length = 10*Precision::Confusion();
//       Handle(Geom_Line) CL = new (Geom_Line) (Origine, D);
//       TC = new (Geom_TrimmedCurve)(CL, 0., length);
//       C = TC; 
//       isVertex = Standard_True;
//     }
//   }

//   // Recherche du Vertex de positionnement
//   if (!TheV.IsNull()) {
//     Standard_Integer NbV = myLaw->NbLaw()+1;
//     for (ii=1, Ind1=0; ii<=NbV && (!Ind1); ii++)
//       if (TheV.IsSame(myLaw->Vertex(ii))) Ind1 = ii;
    
//     if (Ind1 != 0) {
//       Ind2 =0;
//       isVertex = Standard_True;
//       if (Ind1==1) {
// 	if (myLaw->IsClosed()) Ind2 =  NbV-1;
//       }
//       else {
// 	Ind1--;
// 	if (Ind1 < NbV-1)
// 	  Ind2 = Ind1+1;
//       }
//     }
//     else {
//       TheV.Nullify(); // On oublie cette option...
//     }
//   }

  // modified by NIZHNY-629  Fri Jul 25 11:11:06 2003 e


  // Construction
  Handle(Geom_Geometry) theSection = C;
  if (isVertex)
    {
      Ex.Init(mySection, TopAbs_VERTEX);
      TopoDS_Vertex theVertex = TopoDS::Vertex(Ex.Current());
      gp_Pnt thePoint = BRep_Tool::Pnt(theVertex);
      theSection = new Geom_CartesianPoint(thePoint);
    }

  GeomFill_SectionPlacement Place(myLaw->Law(1), theSection);

  // Dans le cas generale : Localisation via une concatenation de la spine
  TColStd_Array1OfReal SuperKnot(1, myLaw->NbLaw()+1); 
  TColStd_Array1OfInteger Index(1, myLaw->NbLaw()); 
  for (ii=1; ii<=myLaw->NbLaw(); ii++) {
    SuperKnot(ii+1) = Index(ii) = ii;
  }
  SuperKnot(1) = 0;
  
  Handle(BRepAdaptor_HCompCurve) adpPath = 
    new (BRepAdaptor_HCompCurve) (myLaw->Wire());
  
  Place.Perform(adpPath, Precision::Confusion());
  
  Standard_Real theParam = Place.ParameterOnPath(), 
                eps = Precision::PConfusion();

#if DEB
  if (myDebug) {
    gp_Pnt P_Path;
    P_Path = adpPath->Value(theParam);
    cout << "Point on Path" << P_Path.X() << ", " 
      <<  P_Path.Y() << ", " << P_Path.Z() << ", " << endl; 
  }
#endif
  
  for (ii=1, Bof=Standard_True; ii<=myLaw->NbLaw() && Bof; ii++) {
    Bof = !((SuperKnot(ii)-eps<=theParam) && 
	    (SuperKnot(ii+1)+eps>= theParam));
    if (!Bof) {
      Ind1 = ii;
      if ( (Abs(theParam-SuperKnot(ii))<eps) && (ii>1) ) Ind2 = ii-1;
	else if ((Abs(theParam-SuperKnot(ii+1))<eps) && 
		 (ii<myLaw->NbLaw()) ) Ind2 = ii+1;
    }
  }
  
  if (Bof) Standard_ConstructionError::Raise("Interval non trouve !!");
  Ind1 = Index(Ind1);
  if (Ind2) Ind2 = Index(Ind2);
  
  // Positionnement sur l'edge (ou les 2 Edges) localisee(s)
  Standard_Real Angle;
  Place.SetLocation(myLaw->Law(Ind1));
  if(TheV.IsNull())
    Place.Perform(Precision::Confusion());
  else {
    Place.Perform(SearchParam(myLaw, Ind1, TheV), 
		  Precision::Confusion());    
  }

  myTrsf = Place.Transformation(WithContact, WithCorrection);
  myIndex = Ind1;
  myParam = Place.ParameterOnPath();
  Angle =  Place.Angle();

  if (Ind2) {
    Place.SetLocation(myLaw->Law(Ind2));
    if (TheV.IsNull())
      Place.Perform(Precision::Confusion());
    else {
      if (Ind1 == Ind2) TheV.Reverse();
      Place.Perform(SearchParam(myLaw, Ind2,TheV), 
		    Precision::Confusion()); 
    }
    if (Place.Angle() > Angle) {
      myTrsf = Place.Transformation(WithContact, WithCorrection);
      myIndex = Ind2;
      myParam = Place.ParameterOnPath();
    }							
  }
}

 const gp_Trsf& BRepFill_SectionPlacement::Transformation() const
{
  return myTrsf;
}

 Standard_Real BRepFill_SectionPlacement::AbscissaOnPath()
{
  return myLaw->Abscissa(myIndex, myParam);
}