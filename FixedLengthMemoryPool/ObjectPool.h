#ifndef __OBJECT_POOL__
#define __OBJECT_POOL__


#include<iostream>
using namespace std;


//定长的对象池
template<class T>
class ObjectPool 
{
  protected:
    struct Block //每一个结点类型
    {
       char* _start = nullptr;//指向已经分配的空间
       size_t _bytesize = 0;//已经分配的空间的大小
       size_t _byteleft = 0;//分配空间的剩余大小
       Block* _next = nullptr;//下一个结点

       Block(size_t bytesize)
       {
         _start = (char*)malloc(bytesize);
         _bytesize = bytesize;
         _byteleft = bytesize;
         _next = nullptr;
       }

      ~Block()
      {
        free(_start);
        _bytesize = 0;
        _byteleft = 0;
        _next = nullptr;
       }
    };

  public:
    ObjectPool(size_t initnum = 8)
    {
      _head = _tail = new Block(initnum * sizeof(T));
    }
    
   void Destory()
   {
     Block* cur = _head;
     while(cur)
     {
       Block* del = cur;
       cur = cur->_next;
       delete del;
     }
     _head = _tail = nullptr;
   }

    ~ObjectPool()
    {
      Destory();
      cout<<"objectpool has been destroy"<<endl;
    }

    T*& OBJ_NEXT(T* obj)
    {
      return *(T**)obj;
    }

    T* New()
    {
       T* obj = nullptr;
       if(_freelist != nullptr)
       {
         obj = _freelist;
         _freelist = OBJ_NEXT(_freelist);
       }
       else
       {
           if(_tail->_byteleft == 0)
           {
             Block* newblock = new Block(_tail->_bytesize*2);
             _tail->_next = newblock;
             _tail = newblock;
           }

           obj = (T*)(_tail->_start + (_tail->_bytesize - _tail->_byteleft));
           _tail->_byteleft -= sizeof(T);
       }
       return obj;
    }

    void Delete(T* ptr)
    {
      if(_freelist == nullptr)
      {
        _freelist = ptr;
        OBJ_NEXT(ptr) = nullptr;
      }
      else 
      {
        OBJ_NEXT(ptr) = _freelist;
        _freelist = ptr;
      }
    }
  protected:
    //自由链表
    T* _freelist = nullptr;
    //块管理
    Block* _head = nullptr;//指向链表的头
    Block* _tail = nullptr; //指向链表的尾
};


#endif
