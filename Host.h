#ifndef HOST_H
#define HOST_H

#include "Port.h"
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
        Host(std::string name, Port * p1);
        std::string getName();
        std::string getAddress();
        void setPayload(std::string payload);
        void setPort(Port * p1);
        std::string frameCreator();
        std::string frameCreatorClock();
        std::string frameCreatorChrono(int randomN);
        void processFrame(Frame * f1);
        void setFrame(Frame * f1, std::string payload);
        void run(int randomN);

        int poissonDelay(int randomN);
        void setdesAddress(std::string destAddress);
        virtual ~Host();
    protected:
    private:
        std::string name;
        std::string address;
        std::string payload;
        Port * myport;
        std:: string destAddress;

};

#endif // HOST_H
