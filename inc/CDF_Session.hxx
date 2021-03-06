// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _CDF_Session_HeaderFile
#define _CDF_Session_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_CDF_Session_HeaderFile
#include <Handle_CDF_Session.hxx>
#endif

#ifndef _Handle_CDF_Directory_HeaderFile
#include <Handle_CDF_Directory.hxx>
#endif
#ifndef _Handle_CDF_Application_HeaderFile
#include <Handle_CDF_Application.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_CDF_MetaDataDriver_HeaderFile
#include <Handle_CDF_MetaDataDriver.hxx>
#endif
#ifndef _Standard_Transient_HeaderFile
#include <Standard_Transient.hxx>
#endif
class CDF_Directory;
class CDF_Application;
class CDF_MetaDataDriver;
class Standard_NoSuchObject;
class Standard_MultiplyDefined;



class CDF_Session : public Standard_Transient {

public:

  
  Standard_EXPORT   CDF_Session();
  //! returns true if a session has been created. <br>
  Standard_EXPORT   static  Standard_Boolean Exists() ;
  //! returns the only one instance of Session <br>
//!          that has been created. <br>
  Standard_EXPORT   static  Handle_CDF_Session CurrentSession() ;
  //! returns the directory of the session; <br>
  Standard_EXPORT     Handle_CDF_Directory Directory() const;
  
  Standard_EXPORT     Standard_Boolean HasCurrentApplication() const;
  
  Standard_EXPORT     Handle_CDF_Application CurrentApplication() const;
  
  Standard_EXPORT     void SetCurrentApplication(const Handle(CDF_Application)& anApplication) ;
  
  Standard_EXPORT     void UnsetCurrentApplication() ;
  
  Standard_EXPORT     Handle_CDF_MetaDataDriver MetaDataDriver() const;
  
  Standard_EXPORT     void LoadDriver() ;


friend class CDF_Application;


  DEFINE_STANDARD_RTTI(CDF_Session)

protected:




private: 


Handle_CDF_Directory myDirectory;
Handle_CDF_Application myCurrentApplication;
Standard_Boolean myHasCurrentApplication;
Handle_CDF_MetaDataDriver myMetaDataDriver;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
