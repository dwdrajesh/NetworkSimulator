#include <iostream>
#include "Port.h"


Port::Port(Frame * f1, Frame * f2)
{    //ctor
    this->outgoingFrame = f1;
    this->incomingFrame = f2;
}
void Port::Run(Frame * f1)
{
    //f1->mymutex.lock();
}
Port::~Port()
{
    //dtor
}
