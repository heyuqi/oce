// Created on: 1995-05-23
// Created by: Robert COUBLANC
// Copyright (c) 1995-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
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

#include <SelectMgr_EntityOwner.ixx>



//==================================================
// Function: 
// Purpose :
//==================================================
SelectMgr_EntityOwner::SelectMgr_EntityOwner(const Standard_Integer aPriority):
SelectBasics_EntityOwner(aPriority),
mySelectable(NULL),
mystate(0)
{
}

SelectMgr_EntityOwner::SelectMgr_EntityOwner(const Handle(SelectMgr_SelectableObject)& aSO,
					     const Standard_Integer aPriority):
SelectBasics_EntityOwner(aPriority),
mystate(0)
{
  mySelectable = aSO.operator->();
}


//=======================================================================
//function : About Selectable...
//purpose  : 
//=======================================================================
void SelectMgr_EntityOwner::Set(const Handle(SelectMgr_SelectableObject)& aSO)
{
  mySelectable = aSO.operator->();
}

Standard_Boolean SelectMgr_EntityOwner::HasSelectable() const
{  
  Handle(Standard_Transient) aNull;
  if(mySelectable != aNull.operator->()){
    if(!Selectable().IsNull()) return Standard_True;}
  return Standard_False;
}

Handle(SelectMgr_SelectableObject) SelectMgr_EntityOwner::Selectable() const
{  
  return mySelectable;
}

//=======================================================================
//function : about Hilight
//purpose  : 
//=======================================================================
Standard_Boolean SelectMgr_EntityOwner::IsHilighted(const Handle(PrsMgr_PresentationManager)& PM,
						    const Standard_Integer aMode) const 
{if(HasSelectable())
   return PM->IsHighlighted(mySelectable,aMode);
 return Standard_False;
}
void SelectMgr_EntityOwner::Hilight(const Handle(PrsMgr_PresentationManager)& PM,
				    const Standard_Integer aMode)
{if(HasSelectable())
   PM->Highlight(mySelectable,aMode);
}

void SelectMgr_EntityOwner::HilightWithColor(const Handle(PrsMgr_PresentationManager3d)& PM,
					     const Quantity_NameOfColor aColor,
					     const Standard_Integer aMode)
{
  if( HasSelectable() ) {
    if( IsAutoHilight() )
      PM->Color(mySelectable,aColor,aMode);
    else
      mySelectable->HilightOwnerWithColor( PM, aColor, this );
  }
}

void SelectMgr_EntityOwner::Unhilight(const Handle(PrsMgr_PresentationManager)& PM,
	const Standard_Integer aMode)
{
  if(HasSelectable())
    PM->Unhighlight(mySelectable,aMode);
}

void SelectMgr_EntityOwner::Clear(const Handle(PrsMgr_PresentationManager)&,
				  const Standard_Integer)
{
// nothing done on the selectable here...
}


void SelectMgr_EntityOwner::
Hilight(){}



//=======================================================================
//function : about Location
//purpose  : 
//=======================================================================

Standard_Boolean SelectMgr_EntityOwner::HasLocation() const
{
  return (HasSelectable() && mySelectable->HasLocation());
}

void SelectMgr_EntityOwner::SetLocation(const TopLoc_Location&)
{
}

const TopLoc_Location& SelectMgr_EntityOwner::Location() const
{
  static TopLoc_Location anIdentity;
  return HasSelectable() ? mySelectable->Location() : anIdentity;
}

void SelectMgr_EntityOwner::ResetLocation()
{
}

Standard_Boolean SelectMgr_EntityOwner::IsAutoHilight () const
{
  if ( mySelectable==0 )
    return Standard_True;
  else
    return mySelectable->IsAutoHilight();
}

Standard_Boolean SelectMgr_EntityOwner::IsForcedHilight () const
{
  return Standard_False;
}

//=======================================================================
//function : SetZLayer
//purpose  :
//=======================================================================
void SelectMgr_EntityOwner::SetZLayer 
  (const Handle(PrsMgr_PresentationManager)&,
   const Standard_Integer)
{
}
