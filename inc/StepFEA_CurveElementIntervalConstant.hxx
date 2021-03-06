// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_CurveElementIntervalConstant_HeaderFile
#define _StepFEA_CurveElementIntervalConstant_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepFEA_CurveElementIntervalConstant_HeaderFile
#include <Handle_StepFEA_CurveElementIntervalConstant.hxx>
#endif

#ifndef _Handle_StepElement_CurveElementSectionDefinition_HeaderFile
#include <Handle_StepElement_CurveElementSectionDefinition.hxx>
#endif
#ifndef _StepFEA_CurveElementInterval_HeaderFile
#include <StepFEA_CurveElementInterval.hxx>
#endif
#ifndef _Handle_StepFEA_CurveElementLocation_HeaderFile
#include <Handle_StepFEA_CurveElementLocation.hxx>
#endif
#ifndef _Handle_StepBasic_EulerAngles_HeaderFile
#include <Handle_StepBasic_EulerAngles.hxx>
#endif
class StepElement_CurveElementSectionDefinition;
class StepFEA_CurveElementLocation;
class StepBasic_EulerAngles;


//! Representation of STEP entity CurveElementIntervalConstant <br>
class StepFEA_CurveElementIntervalConstant : public StepFEA_CurveElementInterval {

public:

  //! Empty constructor <br>
  Standard_EXPORT   StepFEA_CurveElementIntervalConstant();
  //! Initialize all fields (own and inherited) <br>
  Standard_EXPORT     void Init(const Handle(StepFEA_CurveElementLocation)& aCurveElementInterval_FinishPosition,const Handle(StepBasic_EulerAngles)& aCurveElementInterval_EuAngles,const Handle(StepElement_CurveElementSectionDefinition)& aSection) ;
  //! Returns field Section <br>
  Standard_EXPORT     Handle_StepElement_CurveElementSectionDefinition Section() const;
  //! Set field Section <br>
  Standard_EXPORT     void SetSection(const Handle(StepElement_CurveElementSectionDefinition)& Section) ;




  DEFINE_STANDARD_RTTI(StepFEA_CurveElementIntervalConstant)

protected:




private: 


Handle_StepElement_CurveElementSectionDefinition theSection;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
