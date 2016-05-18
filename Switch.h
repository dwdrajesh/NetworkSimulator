#ifndef SWITCH_H
#define SWITCH_H

#include "Node.h"
#include "Port.h"
#include "Host.h"
#include "Host.h"
#include <thread>
#include <vector>
class Switch : public Node
{
    public:
        //Switch(Frame * f1, Frame * f2, Frame * f3, Frame * f4);
        Switch(Port * p1, Port * p2);
        void runSwitch();
        void runPort(Port * p1, Port * p2);
        std::string processFrame(Frame * f1);
        void setFrame(Frame * f1, std::string payload);
        void configurePorts(Port * p1, std::string h1);
        virtual ~Switch();
    protected:
    private:
        Port * port1;
        Port * port2;
        std::vector <Port *> portVector;
        std::vector <std::string > hostAddresses;
};

#endif // SWITCH_H
