#ifndef HOST_H
#define HOST_H

#include "Node.h"
#include <time.h>
#include <unistd.h>
#include <chrono>
#include <vector>
#include <string.h>
class Host : public Node
{
    public:
        Host();
        Host(std::string name);
        std::string getName();
        std::string getAddress();
        void setPayload(std::string payload);
        std::string frameCreator();
        std::string frameCreatorClock();
        std::string frameCreatorChrono(int randomN);
        void processFrame(Frame & f1);
        void setFrame(Frame & f1, std::string payload);
        void run(Frame & f1, Frame & f2, int randomN);
        int poissonDelay(int randomN);
        //std::vector <std::string> listSent;
        //std::vector <std::string> listRx;
        virtual ~Host();
    protected:
    private:
        std::string name;
        std::string address;
        std::string payload;

};

#endif // HOST_H
