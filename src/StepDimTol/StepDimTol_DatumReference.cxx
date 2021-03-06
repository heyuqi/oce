// Created on: 2003-06-04
// Created by: Galina KULIKOVA
// Copyright (c) 2003-2014 OPEN CASCADE SAS
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

// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.2

#include <StepDimTol_DatumReference.ixx>

//=======================================================================
//function : StepDimTol_DatumReference
//purpose  : 
//=======================================================================

StepDimTol_DatumReference::StepDimTol_DatumReference ()
{
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void StepDimTol_DatumReference::Init (const Standard_Integer aPrecedence,
                                      const Handle(StepDimTol_Datum) &aReferencedDatum)
{

  thePrecedence = aPrecedence;

  theReferencedDatum = aReferencedDatum;
}

//=======================================================================
//function : Precedence
//purpose  : 
//=======================================================================

Standard_Integer StepDimTol_DatumReference::Precedence () const
{
  return thePrecedence;
}

//=======================================================================
//function : SetPrecedence
//purpose  : 
//=======================================================================

void StepDimTol_DatumReference::SetPrecedence (const Standard_Integer aPrecedence)
{
  thePrecedence = aPrecedence;
}

//=======================================================================
//function : ReferencedDatum
//purpose  : 
//=======================================================================

Handle(StepDimTol_Datum) StepDimTol_DatumReference::ReferencedDatum () const
{
  return theReferencedDatum;
}

//=======================================================================
//function : SetReferencedDatum
//purpose  : 
//=======================================================================

void StepDimTol_DatumReference::SetReferencedDatum (const Handle(StepDimTol_Datum) &aReferencedDatum)
{
  theReferencedDatum = aReferencedDatum;
}
