#ifndef SWITCH_H
#define SWITCH_H

#include "Node.h"
#include "Port.h"
#include "Host.h"
#include "Host.h"
#include <thread>
#include <vector>
#include <algorithm>
//using namespace std;
class Switch : public Node
{
    public:
        //Switch(Frame * f1, Frame * f2, Frame * f3, Frame * f4);
        Switch(Port * p1, Port * p2, Port * p3, Port * p4);
        void runSwitch();
        void runPort(Port * p1);
        std::string processFrame(Frame * f1);
        void setFrame(Frame * f1, std::string sourceAdd, std::string destAdd, std::string payload);
        void configurePorts(Port * p1, std::string h1);
        virtual ~Switch();
    protected:
    private:
        Port * port1;
        Port * port2;
        Port * port3;
        Port * port4;
        std::vector <Port *> portList;
        std::vector <Port *> portListsorted;
        std::vector <Port *> portVector;
        std::vector <std::string > hostAddresses;
        std::vector <std::string > hostAddrSwitch;
};

#endif // SWITCH_H
