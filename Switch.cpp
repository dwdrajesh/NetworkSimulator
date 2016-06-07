#include "Switch.h"

//Switch::Switch(Frame * f1, Frame * f2, Frame * f3, Frame * f4)
Switch::Switch(Port * p1, Port * p2, Port * p3, Port * p4)
{
    //ctor
    //Port p1(f2, f1);
    //Port p2(f4, f3);
    port1 = p1;
    port2 = p2;
    port3 = p3;
    port4 = p4;
    this->portList.push_back(p1);
    this->portList.push_back(p2);
    this->portList.push_back(p3);
    this->portList.push_back(p4);
}

void Switch::setFrame(Frame * f1, std::string sourceAdd, std::string destAdd, std::string payload)
{
    f1->setPayload(sourceAdd, destAdd, payload);
}

void Switch::configurePorts(Port * p1, std::string h1)
{
    this->portVector.push_back(p1);
    //this->hostAddresses.push_back(h1);
}
std::string Switch::processFrame(Frame * f1)
{
    std::string payload = f1->getPayload();
    f1->clearPayload();
    return payload;
}

void Switch::runPort(Port * p1)
{
    //int count = 0;
    while (1)
    {
            if (!p1->incomingFrame->isempty())
            {
                std::string destAdd = p1->incomingFrame->getDestAdd();
                std::string sourceAdd = p1->incomingFrame->getsourceAdd();
                std::string payload = this->processFrame(p1->incomingFrame);
                if (std::find(this->hostAddrSwitch.begin(), this->hostAddrSwitch.end(), sourceAdd) == this->hostAddrSwitch.end())
                {
                    this->hostAddrSwitch.push_back(sourceAdd);
                    this->portListsorted.push_back(p1);

                }

                if (std::find(this->hostAddrSwitch.begin(), this->hostAddrSwitch.end(), destAdd) != this->hostAddrSwitch.end())
                {
                    int pos = ( std::find(this->hostAddrSwitch.begin(), this->hostAddrSwitch.end(), destAdd) - this->hostAddrSwitch.begin());
                    //this->hostAddrSwitch.push_back(sourceAdd);
                    //this->portListsorted.push_back(p1);
                    this->setFrame(portListsorted[pos]->outgoingFrame, sourceAdd, destAdd, payload);
                }
                else
                {
                    for (int i = 0; i < (int) this->portVector.size(); i++)
                    {
                        this->setFrame(portVector[i]->outgoingFrame, sourceAdd, destAdd, payload);
                    }
                }
                /*for (int i = 0; i < (int)(this->hostAddresses.size()); i++)
                {
                    if (this->hostAddresses[i] == destAdd)
                    {
                        this->setFrame(portVector[i]->outgoingFrame, payload);
                        break;
                    }
                } */
                // this->setFrame(p2->outgoingFrame, payload);
            }
    }
}
void Switch::runSwitch()
{
    //runPort(port1, port2);
    //runPort(port2, port1);
    std::thread threadlist[portList.size()];
    for (int i = 0; i < portList.size(); i++)
    {
        threadlist[i] = std::thread(&Switch::runPort, this, portList[i]);
    }
    for (int i = 0; i < portList.size(); i++)
    {
        threadlist[i].join();
    }
    //std::thread t1(&Switch::runPort, this, port1);
    //std::thread t2(&Switch::runPort, this, port2);
    //t1.join();
    //t2.join();
}
Switch::~Switch()
{
    //dtor
}
