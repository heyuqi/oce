// Created on: 2004-06-10
// Created by: Alexander SOLOVYOV
// Copyright (c) 2004-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and / or modify it
// under the terms of the GNU Lesser General Public version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <XSDRAWSTLVRML_DataSource.ixx>

#include <StlMesh_SequenceOfMeshTriangle.hxx>
#include <StlMesh_MeshTriangle.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>

//================================================================
// Function : Constructor
// Purpose  :
//================================================================
XSDRAWSTLVRML_DataSource::XSDRAWSTLVRML_DataSource( const Handle( StlMesh_Mesh )& aMesh )
{
  myMesh = aMesh;

  if( !myMesh.IsNull() )
  {
    const TColgp_SequenceOfXYZ& aCoords = myMesh->Vertices();
    Standard_Integer len = aCoords.Length(), i, j;
    myNodeCoords = new TColStd_HArray2OfReal(1, len, 1, 3);
    cout << "Nodes : " << len << endl;

    gp_XYZ xyz;

    for( i = 1; i <= len; i++ )
    {
      myNodes.Add( i );
      xyz = aCoords(i);

      myNodeCoords->SetValue(i, 1, xyz.X());
      myNodeCoords->SetValue(i, 2, xyz.Y());
      myNodeCoords->SetValue(i, 3, xyz.Z());
    }

    const StlMesh_SequenceOfMeshTriangle& aSeq = myMesh->Triangles();
    len = aSeq.Length();
    myElemNormals = new TColStd_HArray2OfReal(1, len, 1, 3);
    myElemNodes = new TColStd_HArray2OfInteger(1, len, 1, 3);

    cout << "Elements : " << len << endl;

    for( i = 1; i <= len; i++ )
    {
      myElements.Add( i );
      Handle( StlMesh_MeshTriangle ) aTriangle = aSeq.Value( i );
      Standard_Integer V[3]; Standard_Real nx, ny, nz;

      aTriangle->GetVertexAndOrientation( V[0], V[1], V[2], nx, ny, nz );

      for( j = 0; j < 3; j++ )
      {
        myElemNodes->SetValue(i, j+1, V[j]);
      }

      myElemNormals->SetValue(i, 1, nx);
      myElemNormals->SetValue(i, 2, ny);
      myElemNormals->SetValue(i, 3, nz);
    }
  }
  cout << "Construction is finished" << endl;
}

//================================================================
// Function : GetGeom
// Purpose  :
//================================================================
Standard_Boolean XSDRAWSTLVRML_DataSource::GetGeom
( const Standard_Integer ID, const Standard_Boolean IsElement,
 TColStd_Array1OfReal& Coords, Standard_Integer& NbNodes,
 MeshVS_EntityType& Type ) const
{
  if( myMesh.IsNull() )
    return Standard_False;

  if( IsElement )
  {
    if( ID>=1 && ID<=myElements.Extent() )
    {
      Type = MeshVS_ET_Face;
      NbNodes = 3;

      for( Standard_Integer i = 1, k = 1; i <= 3; i++ )
      {
        Standard_Integer IdxNode = myElemNodes->Value(ID, i);
        for(Standard_Integer j = 1; j <= 3; j++, k++ )
          Coords(k) = myNodeCoords->Value(IdxNode, j);
      }

      return Standard_True;
    }
    else
      return Standard_False;
  }
  else
    if( ID>=1 && ID<=myNodes.Extent() )
    {
      Type = MeshVS_ET_Node;
      NbNodes = 1;

      Coords( 1 ) = myNodeCoords->Value(ID, 1);
      Coords( 2 ) = myNodeCoords->Value(ID, 2);
      Coords( 3 ) = myNodeCoords->Value(ID, 3);
      return Standard_True;
    }
    else
      return Standard_False;
}

//================================================================
// Function : GetGeomType
// Purpose  :
//================================================================
Standard_Boolean XSDRAWSTLVRML_DataSource::GetGeomType
( const Standard_Integer,
 const Standard_Boolean IsElement,
 MeshVS_EntityType& Type ) const
{
  if( IsElement )
  {
    Type = MeshVS_ET_Face;
    return Standard_True;
  }
  else
  {
    Type = MeshVS_ET_Node;
    return Standard_True;
  }
}

//================================================================
// Function : GetAddr
// Purpose  :
//================================================================
Standard_Address XSDRAWSTLVRML_DataSource::GetAddr
( const Standard_Integer, const Standard_Boolean ) const
{
  return NULL;
}

//================================================================
// Function : GetNodesByElement
// Purpose  :
//================================================================
Standard_Boolean XSDRAWSTLVRML_DataSource::GetNodesByElement
( const Standard_Integer ID,
 TColStd_Array1OfInteger& theNodeIDs,
 Standard_Integer& /*theNbNodes*/ ) const
{
  if( myMesh.IsNull() )
    return Standard_False;

  if( ID>=1 && ID<=myElements.Extent() && theNodeIDs.Length() >= 3 )
  {
    Standard_Integer aLow = theNodeIDs.Lower();
    theNodeIDs (aLow)     = myElemNodes->Value(ID, 1 );
    theNodeIDs (aLow + 1) = myElemNodes->Value(ID, 2 );
    theNodeIDs (aLow + 2) = myElemNodes->Value(ID, 3 );
    return Standard_True;
  }
  return Standard_False;
}

//================================================================
// Function : GetAllNodes
// Purpose  :
//================================================================
const TColStd_PackedMapOfInteger& XSDRAWSTLVRML_DataSource::GetAllNodes() const
{
  return myNodes;
}

//================================================================
// Function : GetAllElements
// Purpose  :
//================================================================
const TColStd_PackedMapOfInteger& XSDRAWSTLVRML_DataSource::GetAllElements() const
{
  return myElements;
}

//================================================================
// Function : GetNormal
// Purpose  :
//================================================================
Standard_Boolean XSDRAWSTLVRML_DataSource::GetNormal
( const Standard_Integer Id, const Standard_Integer Max,
 Standard_Real& nx, Standard_Real& ny,Standard_Real& nz ) const
{
  if( myMesh.IsNull() )
    return Standard_False;

  if( Id>=1 && Id<=myElements.Extent() && Max>=3 )
  {
    nx = myElemNormals->Value(Id, 1);
    ny = myElemNormals->Value(Id, 2);
    nz = myElemNormals->Value(Id, 3);
    return Standard_True;
  }
  else
    return Standard_False;
}

