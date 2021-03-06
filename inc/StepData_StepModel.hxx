// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepData_StepModel_HeaderFile
#define _StepData_StepModel_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepData_StepModel_HeaderFile
#include <Handle_StepData_StepModel.hxx>
#endif

#ifndef _Interface_EntityList_HeaderFile
#include <Interface_EntityList.hxx>
#endif
#ifndef _Handle_TColStd_HArray1OfInteger_HeaderFile
#include <Handle_TColStd_HArray1OfInteger.hxx>
#endif
#ifndef _Interface_InterfaceModel_HeaderFile
#include <Interface_InterfaceModel.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Interface_InterfaceModel_HeaderFile
#include <Handle_Interface_InterfaceModel.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Standard_Type_HeaderFile
#include <Handle_Standard_Type.hxx>
#endif
#ifndef _Handle_Interface_Check_HeaderFile
#include <Handle_Interface_Check.hxx>
#endif
#ifndef _Handle_Message_Messenger_HeaderFile
#include <Handle_Message_Messenger.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
class TColStd_HArray1OfInteger;
class Standard_NoSuchObject;
class Standard_Transient;
class Interface_InterfaceModel;
class Interface_EntityIterator;
class Standard_Type;
class Interface_Check;
class Message_Messenger;
class TCollection_HAsciiString;


//! Gives access to <br>
//! - entities in a STEP file, <br>
//! - the STEP file header. <br>
class StepData_StepModel : public Interface_InterfaceModel {

public:

  //! Creates an empty STEP model with an empty header. <br>
  Standard_EXPORT   StepData_StepModel();
  //! returns entity given its rank. <br>
//!           Same as InterfaceEntity, but with a shorter name <br>
  Standard_EXPORT     Handle_Standard_Transient Entity(const Standard_Integer num) const;
  //! gets header from another Model (uses Header Protocol) <br>
  Standard_EXPORT     void GetFromAnother(const Handle(Interface_InterfaceModel)& other) ;
  //! Returns a New Empty Model, same type as <me>, i.e. StepModel <br>
  Standard_EXPORT     Handle_Interface_InterfaceModel NewEmptyModel() const;
  //! returns Header entities under the form of an iterator <br>
  Standard_EXPORT     Interface_EntityIterator Header() const;
  //! says if a Header entity has a specifed type <br>
  Standard_EXPORT     Standard_Boolean HasHeaderEntity(const Handle(Standard_Type)& atype) const;
  //! Returns Header entity with specified type, if there is <br>
  Standard_EXPORT     Handle_Standard_Transient HeaderEntity(const Handle(Standard_Type)& atype) const;
  //! Clears the Header <br>
  Standard_EXPORT     void ClearHeader() ;
  //! Adds an Entity to the Header <br>
  Standard_EXPORT     void AddHeaderEntity(const Handle(Standard_Transient)& ent) ;
  //! Specific Check, checks Header Items with HeaderProtocol <br>
  Standard_EXPORT   virtual  void VerifyCheck(Handle(Interface_Check)& ach) const;
  //! Dumps the Header, with the Header Protocol of StepData. <br>
//!           If the Header Protocol is not defined, for each Header Entity, <br>
//!           prints its Type. Else sends the Header under the form of <br>
//!           HEADER Section of an Ascii Step File <br>
//!           <level> is not used because Header is not so big <br>
  Standard_EXPORT     void DumpHeader(const Handle(Message_Messenger)& S,const Standard_Integer level = 0) const;
  //! erases specific labels, i.e. clears the map (entity-ident) <br>
  Standard_EXPORT     void ClearLabels() ;
  //! Attaches an ident to an entity to produce a label <br>
//!           (does nothing if <ent> is not in <me>) <br>
  Standard_EXPORT     void SetIdentLabel(const Handle(Standard_Transient)& ent,const Standard_Integer ident) ;
  //! returns the label ident attached to an entity, 0 if not in me <br>
  Standard_EXPORT     Standard_Integer IdentLabel(const Handle(Standard_Transient)& ent) const;
  //! Prints label specific to STEP norm for a given entity, i.e. <br>
//!           if a LabelIdent has been recorded, its value with '#', else <br>
//!           the number in the model with '#' and between () <br>
  Standard_EXPORT     void PrintLabel(const Handle(Standard_Transient)& ent,const Handle(Message_Messenger)& S) const;
  //! Returns a string with the label attached to a given entity, <br>
//!           same form as for PrintLabel <br>
  Standard_EXPORT     Handle_TCollection_HAsciiString StringLabel(const Handle(Standard_Transient)& ent) const;




  DEFINE_STANDARD_RTTI(StepData_StepModel)

protected:




private: 


Interface_EntityList theheader;
Handle_TColStd_HArray1OfInteger theidnums;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
