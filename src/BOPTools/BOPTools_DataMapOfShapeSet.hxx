// Created by: Peter KURNEV
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

#ifndef BOPTools_DataMapOfShapeSet_HeaderFile
#define BOPTools_DataMapOfShapeSet_HeaderFile

#include <TopoDS_Shape.hxx>  
#include <TopTools_ShapeMapHasher.hxx>
  
#define _NCollection_MapHasher
#include <NCollection_DataMap.hxx>

typedef NCollection_DataMap<TopoDS_Shape, BOPTools_Set, TopTools_ShapeMapHasher> BOPTools_DataMapOfShapeSet; 
typedef BOPTools_DataMapOfShapeSet::Iterator BOPCol_DataMapIteratorOfDataMapOfShapeSet; 
 
#undef _NCollection_MapHasher


#endif
