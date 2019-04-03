/**
 *  Writer : badogyang
 *  class name : SmartPointer
 *  Version : 1.0.0
 *
 *  usage : SmartPointer<type> pointer = new Type();
 *
 *  theory : 堆栈空间的区别，当使用的指针生成对象时，在堆空间生成对象，需自己释放空间，
 *           而智能指针是通过栈区生成对象，系统自动释放
 *           SmartPointer<type> obj = new type();
 *           没有指针，所以自动释放空间;
 *           type* p = new type()
 *           在堆空间生成对象，不能自动释放空间
 */

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object.h"

namespace BYLib
{

template < typename T >
class SmartPointer : public Object
{
    T* m_pointer;

public:
    SmartPointer(T* p = NULL)
    {
        m_pointer = p;
    }

    SmartPointer(const SmartPointer<T>& obj)
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }

    SmartPointer<T>& operator = (const SmartPointer<T>& obj)
    {
        if(this != obj)
        {
            delete m_pointer;
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
        }

        return *this;
    }

    T& operator ->()
    {
        return *m_pointer;
    }

    T* operator *()
    {
        return m_pointer;
    }

    bool isNULL()
    {
        return (m_pointer == NULL);
    }

    ~SmartPointer()
    {
        delete m_pointer;
    }
};

}

#endif // SMARTPOINTER_H
