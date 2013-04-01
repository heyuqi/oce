// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Extrema_CCLocFOfLocECCOfLocateExtCC_HeaderFile
#define _Extrema_CCLocFOfLocECCOfLocateExtCC_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _gp_Pnt_HeaderFile
#include <gp_Pnt.hxx>
#endif
#ifndef _TColStd_SequenceOfReal_HeaderFile
#include <TColStd_SequenceOfReal.hxx>
#endif
#ifndef _Extrema_SeqPOnCOfCCLocFOfLocECCOfLocateExtCC_HeaderFile
#include <Extrema_SeqPOnCOfCCLocFOfLocECCOfLocateExtCC.hxx>
#endif
#ifndef _math_FunctionSetWithDerivatives_HeaderFile
#include <math_FunctionSetWithDerivatives.hxx>
#endif
#ifndef _Handle_Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC_HeaderFile
#include <Handle_Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_OutOfRange;
class Adaptor3d_Curve;
class Extrema_CurveTool;
class Extrema_POnCurv;
class gp_Pnt;
class gp_Vec;
class Extrema_SeqPOnCOfCCLocFOfLocECCOfLocateExtCC;
class Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC;
class math_Vector;
class math_Matrix;



class Extrema_CCLocFOfLocECCOfLocateExtCC  : public math_FunctionSetWithDerivatives {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   Extrema_CCLocFOfLocECCOfLocateExtCC(const Standard_Real thetol = 1.0e-10);
  
  Standard_EXPORT   Extrema_CCLocFOfLocECCOfLocateExtCC(const Adaptor3d_Curve& C1,const Adaptor3d_Curve& C2,const Standard_Real thetol = 1.0e-10);
  
        void SetCurve(const Standard_Integer theRank,const Adaptor3d_Curve& C1) ;
  
        void SetTolerance(const Standard_Real theTol) ;
  
      virtual  Standard_Integer NbVariables() const;
  
      virtual  Standard_Integer NbEquations() const;
  
  Standard_EXPORT   virtual  Standard_Boolean Value(const math_Vector& UV,math_Vector& F) ;
  
  Standard_EXPORT     Standard_Boolean Derivatives(const math_Vector& UV,math_Matrix& DF) ;
  
  Standard_EXPORT     Standard_Boolean Values(const math_Vector& UV,math_Vector& F,math_Matrix& DF) ;
  
  Standard_EXPORT   virtual  Standard_Integer GetStateNumber() ;
  
        Standard_Integer NbExt() const;
  
        Standard_Real SquareDistance(const Standard_Integer N) const;
  
  Standard_EXPORT     void Points(const Standard_Integer N,Extrema_POnCurv& P1,Extrema_POnCurv& P2) const;
  
        Standard_Address CurvePtr(const Standard_Integer theRank) const;
  
        Standard_Real Tolerance() const;





protected:





private:



Standard_Address myC1;
Standard_Address myC2;
Standard_Real myTol;
Standard_Real myU;
Standard_Real myV;
gp_Pnt myP1;
gp_Pnt myP2;
gp_Vec myDu;
gp_Vec myDv;
TColStd_SequenceOfReal mySqDist;
Extrema_SeqPOnCOfCCLocFOfLocECCOfLocateExtCC myPoints;


};

#define Curve1 Adaptor3d_Curve
#define Curve1_hxx <Adaptor3d_Curve.hxx>
#define Tool1 Extrema_CurveTool
#define Tool1_hxx <Extrema_CurveTool.hxx>
#define Curve2 Adaptor3d_Curve
#define Curve2_hxx <Adaptor3d_Curve.hxx>
#define Tool2 Extrema_CurveTool
#define Tool2_hxx <Extrema_CurveTool.hxx>
#define POnC Extrema_POnCurv
#define POnC_hxx <Extrema_POnCurv.hxx>
#define Pnt gp_Pnt
#define Pnt_hxx <gp_Pnt.hxx>
#define Vec gp_Vec
#define Vec_hxx <gp_Vec.hxx>
#define Extrema_SeqPOnC Extrema_SeqPOnCOfCCLocFOfLocECCOfLocateExtCC
#define Extrema_SeqPOnC_hxx <Extrema_SeqPOnCOfCCLocFOfLocECCOfLocateExtCC.hxx>
#define Extrema_SequenceNodeOfSeqPOnC Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC
#define Extrema_SequenceNodeOfSeqPOnC_hxx <Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC.hxx>
#define Extrema_SequenceNodeOfSeqPOnC Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC
#define Extrema_SequenceNodeOfSeqPOnC_hxx <Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC.hxx>
#define Handle_Extrema_SequenceNodeOfSeqPOnC Handle_Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC
#define Extrema_SequenceNodeOfSeqPOnC_Type_() Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC_Type_()
#define Handle_Extrema_SequenceNodeOfSeqPOnC Handle_Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC
#define Extrema_SequenceNodeOfSeqPOnC_Type_() Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECCOfLocateExtCC_Type_()
#define Extrema_FuncExtCC Extrema_CCLocFOfLocECCOfLocateExtCC
#define Extrema_FuncExtCC_hxx <Extrema_CCLocFOfLocECCOfLocateExtCC.hxx>

#include <Extrema_FuncExtCC.lxx>

#undef Curve1
#undef Curve1_hxx
#undef Tool1
#undef Tool1_hxx
#undef Curve2
#undef Curve2_hxx
#undef Tool2
#undef Tool2_hxx
#undef POnC
#undef POnC_hxx
#undef Pnt
#undef Pnt_hxx
#undef Vec
#undef Vec_hxx
#undef Extrema_SeqPOnC
#undef Extrema_SeqPOnC_hxx
#undef Extrema_SequenceNodeOfSeqPOnC
#undef Extrema_SequenceNodeOfSeqPOnC_hxx
#undef Extrema_SequenceNodeOfSeqPOnC
#undef Extrema_SequenceNodeOfSeqPOnC_hxx
#undef Handle_Extrema_SequenceNodeOfSeqPOnC
#undef Extrema_SequenceNodeOfSeqPOnC_Type_
#undef Handle_Extrema_SequenceNodeOfSeqPOnC
#undef Extrema_SequenceNodeOfSeqPOnC_Type_
#undef Extrema_FuncExtCC
#undef Extrema_FuncExtCC_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif
