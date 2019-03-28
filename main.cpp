#include <iostream>
#include "Object.h"

using namespace std;
using namespace BYLib;

class Test : public Object
{
public:
    int i;
    int k;
};

class child : public Object
{
public:
    int m;
};

int main()
{
    Object* t = new Test();
    Object* c = new child();

    delete t;
    delete c;
    return 0;
}
