// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESData_ToolLocation_HeaderFile
#define _IGESData_ToolLocation_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESData_ToolLocation_HeaderFile
#include <Handle_IGESData_ToolLocation.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_IGESData_IGESModel_HeaderFile
#include <Handle_IGESData_IGESModel.hxx>
#endif
#ifndef _Interface_GeneralLib_HeaderFile
#include <Interface_GeneralLib.hxx>
#endif
#ifndef _TColStd_Array1OfInteger_HeaderFile
#include <TColStd_Array1OfInteger.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Handle_IGESData_Protocol_HeaderFile
#include <Handle_IGESData_Protocol.hxx>
#endif
#ifndef _Handle_IGESData_IGESEntity_HeaderFile
#include <Handle_IGESData_IGESEntity.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class IGESData_IGESModel;
class Standard_DomainError;
class IGESData_Protocol;
class IGESData_IGESEntity;
class gp_GTrsf;
class gp_Trsf;


//! This Tool determines and gives access to effective Locations <br>
//!           of IGES Entities as defined by the IGES Norm. These Locations <br>
//!           can be for each Entity : <br>
//!           - on one part, explicitly defined by a Transf in Directory <br>
//!             Part (this Transf can be itself compound); if not defined, <br>
//!             no proper Transformation is defined <br>
//!           - on the other part, implicitly defined by a reference from <br>
//!             another Entity : its Parent <br>
//!           Both implicit and explicit locations are combinable. <br>
//! <br>
//!           Implicit definition can be itself defined, either through the <br>
//!           definition of an Entity (i.e. a Composite Curve references <br>
//!           a list of Curves), or by a specific Associativity, of type <br>
//!           SingleParentEntity, by which the Location of the Parent is <br>
//!           applied to the Childs defined by this Associativity. <br>
//!           Remark that a Transf itself has no Location, but it can be <br>
//!           compound <br>
//! <br>
//!           This is a TShared object, then it is easier to use in an <br>
//!           interactive session <br>
class IGESData_ToolLocation : public MMgt_TShared {

public:

  //! Creates a ToolLocation on a given Model, filled with the help <br>
//!           of a Protocol (which allows to known Entities referenced by <br>
//!           other ones) <br>
  Standard_EXPORT   IGESData_ToolLocation(const Handle(IGESData_IGESModel)& amodel,const Handle(IGESData_Protocol)& protocol);
  //! Does the effective work of determining Locations of Entities <br>
  Standard_EXPORT     void Load() ;
  //! Sets a precision for the Analysis of Locations <br>
//!           (default by constructor is 1.E-05) <br>
  Standard_EXPORT     void SetPrecision(const Standard_Real prec) ;
  //! Sets the "Reference" information for <child> as being <parent> <br>
//!           Sets an Error Status if already set (see method IsAmbiguous) <br>
  Standard_EXPORT     void SetReference(const Handle(IGESData_IGESEntity)& parent,const Handle(IGESData_IGESEntity)& child) ;
  //! Sets the "Associativity" information for <child> as being <br>
//!           <parent> (it must be the Parent itself, not the Associativity) <br>
  Standard_EXPORT     void SetParentAssoc(const Handle(IGESData_IGESEntity)& parent,const Handle(IGESData_IGESEntity)& child) ;
  //! Resets all informations about dependences for <child> <br>
  Standard_EXPORT     void ResetDependences(const Handle(IGESData_IGESEntity)& child) ;
  //! Unitary action which defines Entities referenced by <ent> <br>
//!           (except those in Directory Part and Associativities List) <br>
//!           as Dependent (their Locations are related to that of <ent>) <br>
  Standard_EXPORT     void SetOwnAsDependent(const Handle(IGESData_IGESEntity)& ent) ;
  //! Returns True if <ent> is kind of TransfEntity. Then, it has <br>
//!           no location, while it can be used to define a Location) <br>
  Standard_EXPORT     Standard_Boolean IsTransf(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns True if <ent> is an Associativity (IGES Type 402). <br>
//!           Then, Location does not apply. <br>
  Standard_EXPORT     Standard_Boolean IsAssociativity(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns True if <ent> has a Transformation Matrix in proper <br>
//!           (referenced from its Directory Part) <br>
  Standard_EXPORT     Standard_Boolean HasTransf(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns the Explicit Location defined by the Transformation <br>
//!           Matrix of <ent>. Identity if there is none <br>
  Standard_EXPORT     gp_GTrsf ExplicitLocation(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns True if more than one Parent has been determined for <br>
//!           <ent>, by adding direct References and Associativities <br>
  Standard_EXPORT     Standard_Boolean IsAmbiguous(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns True if <ent> is dependent from one and only one other <br>
//!           Entity, either by Reference or by Associativity <br>
  Standard_EXPORT     Standard_Boolean HasParent(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns the unique Parent recorded for <ent>. <br>
//!           Returns a Null Handle if there is none <br>
  Standard_EXPORT     Handle_IGESData_IGESEntity Parent(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns True if the Parent, if there is one, is defined by <br>
//!           a SingleParentEntity Associativity <br>
//!           Else, if HasParent is True, it is by Reference <br>
  Standard_EXPORT     Standard_Boolean HasParentByAssociativity(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns the effective Location of the Parent of <ent>, if <br>
//!           there is one : this Location is itself given as compound <br>
//!           according dependences on the Parent, if there are some. <br>
//!           Returns an Identity Transformation if no Parent is recorded. <br>
  Standard_EXPORT     gp_GTrsf ParentLocation(const Handle(IGESData_IGESEntity)& ent) const;
  //! Returns the effective Location of an Entity, i.e. the <br>
//!           composition of its proper Transformation Matrix (returned by <br>
//!           Transf) and its Parent's Location (returned by ParentLocation) <br>
  Standard_EXPORT     gp_GTrsf EffectiveLocation(const Handle(IGESData_IGESEntity)& ent) const;
  //! Analysis a Location given as a GTrsf, by trying to convert it <br>
//!           to a Trsf (i.e. to a True Location of which effect is <br>
//!           described by an Isometry or a Similarity) <br>
//!           Works with the Precision given by default or by SetPrecision <br>
//!           Calls ConvertLocation (see below) <br>
  Standard_EXPORT     Standard_Boolean AnalyseLocation(const gp_GTrsf& loc,gp_Trsf& result) const;
  //! Convertion of a Location, from GTrsf form to Trsf form <br>
//!           Works with a precision given as argument. <br>
//!           Returns True if the Conversion is possible, (hence, <result> <br>
//!           contains the converted location), False else <br>
//!           <unit>, if given, indicates the unit in which <loc> is defined <br>
//!           in meters. It concerns the translation part (to be converted. <br>
//! <br>
//!           As a class method, it can be called separately <br>
  Standard_EXPORT   static  Standard_Boolean ConvertLocation(const Standard_Real prec,const gp_GTrsf& loc,gp_Trsf& result,const Standard_Real uni = 1) ;




  DEFINE_STANDARD_RTTI(IGESData_ToolLocation)

protected:




private: 


Standard_Real theprec;
Handle_IGESData_IGESModel themodel;
Interface_GeneralLib thelib;
TColStd_Array1OfInteger therefs;
TColStd_Array1OfInteger theassocs;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
