// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PColStd_SeqNodeOfHSequenceOfReal_HeaderFile
#define _PColStd_SeqNodeOfHSequenceOfReal_HeaderFile

#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Handle_PColStd_SeqNodeOfHSequenceOfReal_HeaderFile
#include <Handle_PColStd_SeqNodeOfHSequenceOfReal.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_PColStd_SeqNodeOfHSequenceOfReal_HeaderFile
#include <Handle_PColStd_SeqNodeOfHSequenceOfReal.hxx>
#endif
#ifndef _PMMgt_PManaged_HeaderFile
#include <PMMgt_PManaged.hxx>
#endif
#ifndef _Handle_PColStd_HSequenceOfReal_HeaderFile
#include <Handle_PColStd_HSequenceOfReal.hxx>
#endif
class PColStd_HSequenceOfReal;
class PColStd_SeqExplorerOfHSequenceOfReal;


class PColStd_SeqNodeOfHSequenceOfReal : public PMMgt_PManaged {

public:

  
  Standard_EXPORT   PColStd_SeqNodeOfHSequenceOfReal(const Handle(PColStd_SeqNodeOfHSequenceOfReal)& TheLast,const Standard_Real& TheItem);
  
  Standard_EXPORT   PColStd_SeqNodeOfHSequenceOfReal(const Standard_Real& TheItem,const Handle(PColStd_SeqNodeOfHSequenceOfReal)& TheFirst);
  
  Standard_EXPORT   PColStd_SeqNodeOfHSequenceOfReal(const Handle(PColStd_SeqNodeOfHSequenceOfReal)& ThePrevious,const Handle(PColStd_SeqNodeOfHSequenceOfReal)& TheNext,const Standard_Real& TheItem);
  
  Standard_EXPORT     Standard_Real Value() const;
  
  Standard_EXPORT     Handle_PColStd_SeqNodeOfHSequenceOfReal Next() const;
  
  Standard_EXPORT     Handle_PColStd_SeqNodeOfHSequenceOfReal Previous() const;
  
  Standard_EXPORT     void SetValue(const Standard_Real& AnItem) ;
  
  Standard_EXPORT     void SetNext(const Handle(PColStd_SeqNodeOfHSequenceOfReal)& ANode) ;
  
  Standard_EXPORT     void SetPrevious(const Handle(PColStd_SeqNodeOfHSequenceOfReal)& ANode) ;

  PColStd_SeqNodeOfHSequenceOfReal( )
{
  
}
PColStd_SeqNodeOfHSequenceOfReal(const Storage_stCONSTclCOM& a) : PMMgt_PManaged(a)
{
  
}
    Handle(PColStd_SeqNodeOfHSequenceOfReal) _CSFDB_GetPColStd_SeqNodeOfHSequenceOfRealMyPrevious() const { return MyPrevious; }
    void _CSFDB_SetPColStd_SeqNodeOfHSequenceOfRealMyPrevious(const Handle(PColStd_SeqNodeOfHSequenceOfReal)& p) { MyPrevious = p; }
    Standard_Real _CSFDB_GetPColStd_SeqNodeOfHSequenceOfRealMyItem() const { return MyItem; }
    void _CSFDB_SetPColStd_SeqNodeOfHSequenceOfRealMyItem(const Standard_Real p) { MyItem = p; }
    Handle(PColStd_SeqNodeOfHSequenceOfReal) _CSFDB_GetPColStd_SeqNodeOfHSequenceOfRealMyNext() const { return MyNext; }
    void _CSFDB_SetPColStd_SeqNodeOfHSequenceOfRealMyNext(const Handle(PColStd_SeqNodeOfHSequenceOfReal)& p) { MyNext = p; }

friend class PColStd_HSequenceOfReal;
friend class PColStd_SeqExplorerOfHSequenceOfReal;


  DEFINE_STANDARD_RTTI(PColStd_SeqNodeOfHSequenceOfReal)

protected:




private: 


Handle_PColStd_SeqNodeOfHSequenceOfReal MyPrevious;
Standard_Real MyItem;
Handle_PColStd_SeqNodeOfHSequenceOfReal MyNext;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
