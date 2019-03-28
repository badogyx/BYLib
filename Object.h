/**
 *  Writer : badogyang
 *  class name : Object
 *  Version : 1.0.0
 *
 *  usage : Object* name = new Type()
 *
 *  theory : BYLib顶层父类，自定义对象的new和delete
 */

#ifndef OBJECT_H
#define OBJECT_H

namespace BYLib
{

class Object
{
public:
    void* operator new (unsigned int size) throw();
    void operator delete(void* p);
    void* operator new[] (unsigned int size) throw();
    void operator delete[] (void* p);

    virtual ~Object() = 0;
};

}


#endif // OBJECT_H
