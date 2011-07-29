// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TDocStd_SequenceOfApplicationDelta_HeaderFile
#define _TDocStd_SequenceOfApplicationDelta_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BaseSequence_HeaderFile
#include <TCollection_BaseSequence.hxx>
#endif
#ifndef _Handle_TDocStd_ApplicationDelta_HeaderFile
#include <Handle_TDocStd_ApplicationDelta.hxx>
#endif
#ifndef _Handle_TDocStd_SequenceNodeOfSequenceOfApplicationDelta_HeaderFile
#include <Handle_TDocStd_SequenceNodeOfSequenceOfApplicationDelta.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_NoSuchObject;
class Standard_OutOfRange;
class TDocStd_ApplicationDelta;
class TDocStd_SequenceNodeOfSequenceOfApplicationDelta;



class TDocStd_SequenceOfApplicationDelta  : public TCollection_BaseSequence {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  
      TDocStd_SequenceOfApplicationDelta();
  
  Standard_EXPORT     void Clear() ;
~TDocStd_SequenceOfApplicationDelta()
{
  Clear();
}
  
  Standard_EXPORT    const TDocStd_SequenceOfApplicationDelta& Assign(const TDocStd_SequenceOfApplicationDelta& Other) ;
   const TDocStd_SequenceOfApplicationDelta& operator =(const TDocStd_SequenceOfApplicationDelta& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void Append(const Handle(TDocStd_ApplicationDelta)& T) ;
  
        void Append(TDocStd_SequenceOfApplicationDelta& S) ;
  
  Standard_EXPORT     void Prepend(const Handle(TDocStd_ApplicationDelta)& T) ;
  
        void Prepend(TDocStd_SequenceOfApplicationDelta& S) ;
  
        void InsertBefore(const Standard_Integer Index,const Handle(TDocStd_ApplicationDelta)& T) ;
  
        void InsertBefore(const Standard_Integer Index,TDocStd_SequenceOfApplicationDelta& S) ;
  
  Standard_EXPORT     void InsertAfter(const Standard_Integer Index,const Handle(TDocStd_ApplicationDelta)& T) ;
  
        void InsertAfter(const Standard_Integer Index,TDocStd_SequenceOfApplicationDelta& S) ;
  
  Standard_EXPORT    const Handle_TDocStd_ApplicationDelta& First() const;
  
  Standard_EXPORT    const Handle_TDocStd_ApplicationDelta& Last() const;
  
        void Split(const Standard_Integer Index,TDocStd_SequenceOfApplicationDelta& Sub) ;
  
  Standard_EXPORT    const Handle_TDocStd_ApplicationDelta& Value(const Standard_Integer Index) const;
   const Handle_TDocStd_ApplicationDelta& operator()(const Standard_Integer Index) const
{
  return Value(Index);
}
  
  Standard_EXPORT     void SetValue(const Standard_Integer Index,const Handle(TDocStd_ApplicationDelta)& I) ;
  
  Standard_EXPORT     Handle_TDocStd_ApplicationDelta& ChangeValue(const Standard_Integer Index) ;
    Handle_TDocStd_ApplicationDelta& operator()(const Standard_Integer Index) 
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT     void Remove(const Standard_Integer Index) ;
  
  Standard_EXPORT     void Remove(const Standard_Integer FromIndex,const Standard_Integer ToIndex) ;





protected:





private:

  
  Standard_EXPORT   TDocStd_SequenceOfApplicationDelta(const TDocStd_SequenceOfApplicationDelta& Other);




};

#define SeqItem Handle_TDocStd_ApplicationDelta
#define SeqItem_hxx <TDocStd_ApplicationDelta.hxx>
#define TCollection_SequenceNode TDocStd_SequenceNodeOfSequenceOfApplicationDelta
#define TCollection_SequenceNode_hxx <TDocStd_SequenceNodeOfSequenceOfApplicationDelta.hxx>
#define Handle_TCollection_SequenceNode Handle_TDocStd_SequenceNodeOfSequenceOfApplicationDelta
#define TCollection_SequenceNode_Type_() TDocStd_SequenceNodeOfSequenceOfApplicationDelta_Type_()
#define TCollection_Sequence TDocStd_SequenceOfApplicationDelta
#define TCollection_Sequence_hxx <TDocStd_SequenceOfApplicationDelta.hxx>

#include <TCollection_Sequence.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif