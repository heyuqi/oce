// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BinMNaming_NamedShapeDriver_HeaderFile
#define _BinMNaming_NamedShapeDriver_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_BinMNaming_NamedShapeDriver_HeaderFile
#include <Handle_BinMNaming_NamedShapeDriver.hxx>
#endif

#ifndef _BinTools_ShapeSet_HeaderFile
#include <BinTools_ShapeSet.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _BinMDF_ADriver_HeaderFile
#include <BinMDF_ADriver.hxx>
#endif
#ifndef _Handle_CDM_MessageDriver_HeaderFile
#include <Handle_CDM_MessageDriver.hxx>
#endif
#ifndef _Handle_TDF_Attribute_HeaderFile
#include <Handle_TDF_Attribute.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _BinObjMgt_RRelocationTable_HeaderFile
#include <BinObjMgt_RRelocationTable.hxx>
#endif
#ifndef _BinObjMgt_SRelocationTable_HeaderFile
#include <BinObjMgt_SRelocationTable.hxx>
#endif
#ifndef _Standard_IStream_HeaderFile
#include <Standard_IStream.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
class CDM_MessageDriver;
class TDF_Attribute;
class BinObjMgt_Persistent;
class BinTools_LocationSet;


//! NamedShape  Attribute Driver. <br>
class BinMNaming_NamedShapeDriver : public BinMDF_ADriver {

public:

  
  Standard_EXPORT   BinMNaming_NamedShapeDriver(const Handle(CDM_MessageDriver)& theMessageDriver);
  
  Standard_EXPORT     Handle_TDF_Attribute NewEmpty() const;
  
  Standard_EXPORT     Standard_Boolean Paste(const BinObjMgt_Persistent& Source,const Handle(TDF_Attribute)& Target,BinObjMgt_RRelocationTable& RelocTable) const;
  
  Standard_EXPORT     void Paste(const Handle(TDF_Attribute)& Source,BinObjMgt_Persistent& Target,BinObjMgt_SRelocationTable& RelocTable) const;
  //! Input the shapes from Bin Document file <br>
  Standard_EXPORT     void ReadShapeSection(Standard_IStream& theIS) ;
  //! Output the shapes into Bin Document file <br>
  Standard_EXPORT     void WriteShapeSection(Standard_OStream& theOS) ;
  //! Clear myShapeSet <br>
  Standard_EXPORT     void Clear() ;
  //! set the format of topology <br>
//!          First : does not write CurveOnSurface UV Points into the file <br>
//!                  on reading calls Check() method. <br>
//!          Second: stores CurveOnSurface UV Points. <br>
        void SetFormatNb(const Standard_Integer theFormat) ;
  //! get the format of topology <br>
        Standard_Integer GetFormatNb() const;
  //! get the format of topology <br>
        BinTools_LocationSet& GetShapesLocations() ;




  DEFINE_STANDARD_RTTI(BinMNaming_NamedShapeDriver)

protected:




private: 


BinTools_ShapeSet myShapeSet;
Standard_Integer myFormatNb;


};


#include <BinMNaming_NamedShapeDriver.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
