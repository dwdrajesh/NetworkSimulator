#ifndef PORT_H
#define PORT_H
#include "Frame.h"

class Port
{
    public:
        Port(Frame * f1, Frame * f2);
        void Run(Frame * f1);
        virtual ~Port();
    protected:
    public:
        Frame *outgoingFrame, *incomingFrame;
};

#endif // PORT_H
