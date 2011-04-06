// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PCDMShape_Document_HeaderFile
#define _PCDMShape_Document_HeaderFile

#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Handle_PCDMShape_Document_HeaderFile
#include <Handle_PCDMShape_Document.hxx>
#endif

#ifndef _PTopoDS_Shape1_HeaderFile
#include <PTopoDS_Shape1.hxx>
#endif
#ifndef _PCDM_Document_HeaderFile
#include <PCDM_Document.hxx>
#endif
class PTopoDS_Shape1;


class PCDMShape_Document : public PCDM_Document {

public:

  
  Standard_EXPORT   PCDMShape_Document();
  
  Standard_EXPORT   PCDMShape_Document(const PTopoDS_Shape1& T);
  
  Standard_EXPORT    const PTopoDS_Shape1 Shape() const;
  
  Standard_EXPORT     void Shape(const PTopoDS_Shape1& T) ;

PCDMShape_Document(const Storage_stCONSTclCOM& a) : PCDM_Document(a)
{
  
}
    const PTopoDS_Shape1& _CSFDB_GetPCDMShape_DocumentmyShape() const { return myShape; }



  DEFINE_STANDARD_RTTI(PCDMShape_Document)

protected:




private: 


PTopoDS_Shape1 myShape;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif