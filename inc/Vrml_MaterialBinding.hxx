// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Vrml_MaterialBinding_HeaderFile
#define _Vrml_MaterialBinding_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Vrml_MaterialBindingAndNormalBinding_HeaderFile
#include <Vrml_MaterialBindingAndNormalBinding.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif


//! defines a MaterialBinding node of VRML specifying properties of geometry <br>
//!          and its appearance. <br>
//!  Material nodes may contain more than one material. This node specifies how the current <br>
//!  materials are bound to shapes that follow in the scene graph. Each shape node may <br>
//!  interpret bindings differently. For example, a Sphere node is always drawn using the first <br>
//!  material in the material node, no matter what the current MaterialBinding, while a Cube <br>
//!  node may use six different materials to draw each of its six faces, depending on the <br>
//!  MaterialBinding. <br>
class Vrml_MaterialBinding  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   Vrml_MaterialBinding(const Vrml_MaterialBindingAndNormalBinding aValue);
  
  Standard_EXPORT   Vrml_MaterialBinding();
  
  Standard_EXPORT     void SetValue(const Vrml_MaterialBindingAndNormalBinding aValue) ;
  
  Standard_EXPORT     Vrml_MaterialBindingAndNormalBinding Value() const;
  
  Standard_EXPORT     Standard_OStream& Print(Standard_OStream& anOStream) const;





protected:





private:



Vrml_MaterialBindingAndNormalBinding myValue;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
