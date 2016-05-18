#include "Switch.h"

//Switch::Switch(Frame * f1, Frame * f2, Frame * f3, Frame * f4)
Switch::Switch(Port * p1, Port * p2)
{
    //ctor
    //Port p1(f2, f1);
    //Port p2(f4, f3);
    port1 = p1;
    port2 = p2;
}

void Switch::setFrame(Frame * f1, std::string payload)
{
    f1->setPayload(payload);
}

void Switch::configurePorts(Port * p1, std::string h1)
{
    this->portVector.push_back(p1);
    this->hostAddresses.push_back(h1);
}
std::string Switch::processFrame(Frame * f1)
{
    std::string payload = f1->getPayload();
    f1->clearPayload();
    return payload;
}

void Switch::runPort(Port * p1, Port * p2)
{
    //int count = 0;
    while (1)
    {
            if (!p1->incomingFrame->isempty())
            {
                std::string destAdd = p1->incomingFrame->getDestAdd();
                std::string sourceAdd = p1->incomingFrame->getsourceAdd();
                std::string payload = this->processFrame(p1->incomingFrame);
               /* for (int i = 0; i < (int)(this->hostAddresses.size()); i++)
                {
                    if (this->hostAddresses[i] == sourceAdd)
                    {
                        this->portVector.push_back(p1);
                        this->hostAddresses.push_back(sourceAdd);
                        break;
                    }
                } */
                for (int i = 0; i < (int)(this->hostAddresses.size()); i++)
                {
                    if (this->hostAddresses[i] == destAdd)
                    {
                        this->setFrame(portVector[i]->outgoingFrame, payload);
                        break;
                    }
                }
                // this->setFrame(p2->outgoingFrame, payload);
            }

        //sentAlice += 1;
    //count += 1;
    }
}
void Switch::runSwitch()
{
    //runPort(port1, port2);
    //runPort(port2, port1);
    std::thread t1(&Switch::runPort, this, port1, port2);
    std::thread t2(&Switch::runPort, this, port2, port1);
    t1.join();
    t2.join();
}
Switch::~Switch()
{
    //dtor
}
