#include "Host.h"
#include <fstream>
using namespace std;

Host::Host()
{
    std::string address1;
        /*this->address = "aa:bb:cc:dd:ee:ff";*/
    for (int i = 0; i <17; ++i){
        if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14){
            address1.push_back(':');
        }
        else {
            address1.push_back('a' + rand()%26);
        }
    }
    this->address = address1;
}
Host::Host(std::string name, Port * p1)
{
    this->name = name;
    //this->destAddress = destAddress;
    myport = p1;
    std::string address1;
        /*this->address = "aa:bb:cc:dd:ee:ff";*/
    for (int i = 0; i <17; ++i){
        if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14){
            address1.push_back(':');
        }
        else {
            address1.push_back('a' + rand()%26);
        }
    }
    this->address = address1;

    //this->setPort(& p1);
}
void Host::setPort(Port * p1)
{
    //myport = p1;
}
std::string Host::getAddress()
{
    return this->address;
}
std::string Host::getName()
{
    return this->name;
}
void Host::setdesAddress(std::string destAddress)
{
    this->destAddress = destAddress;
}
void Host::setPayload(std::string payload)
{
    this->payload = payload;
}
std::string Host::frameCreator()
{
        srand (time(NULL));
        std::string payload;
        double lambda = (1/5.0);

        double x = (double) rand()/(RAND_MAX);
        std::cout << "x = " << x << std::endl;
        int interArrival = (-1/lambda)*log(x);
        std::cout << interArrival << std::endl; /* The exponential random variable based on lambda and the uniform rand variable x*/
        int randlength = 1 + (10-1)*x;
        /*usleep(randlength*1000000);*/
        /*cout << "randlength = " << randlength << endl;*/
        for (int i = 0; i < randlength; ++i){
            payload.push_back('a' + rand()%26);
        }
        time_t start;
        start = time(NULL);
        cout << "Current seconds is: " << start << endl;
        time_t nextTime = start + interArrival;
        //sleep(5);
        while(time(NULL) < nextTime){ }
        time_t end;
        end = time(NULL);
        cout << "Updated time now is: " << end << endl;
        cout << "Elapsed time is: " << difftime(end, start) << endl;
        /*cout << payload << endl;*/
        return payload;
    }
std::string Host::frameCreatorClock()
{
        srand (time(NULL));
        std::string payload;
        double lambda = (1/5.0);

        double x = (double) rand()/(RAND_MAX);
        std::cout << "x = " << x << std::endl;
        int interArrival = (-1/lambda)*log(x);
        std::cout << interArrival << std::endl; /* The exponential random variable based on lambda and the uniform rand variable x*/
        int randlength = 1 + (10-1)*x;
        /*usleep(randlength*1000000);*/
        /*cout << "randlength = " << randlength << endl;*/
        for (int i = 0; i < randlength; ++i)
        {
            payload.push_back('a' + rand()%26);
        }
        clock_t start;
        start = clock();
        cout << "Current ticks is: " << start << endl;
        clock_t nextTime = start + interArrival*CLOCKS_PER_SEC;
        //sleep(5);
        while(clock() < nextTime){ }
        clock_t end;
        end = clock();
        cout << "Updated ticks now is: " << end << endl;
        cout << "Elapsed time is: " << (double) (end - start)/CLOCKS_PER_SEC << endl;
        /*cout << payload << endl;*/
        return payload;
    }
std::string Host::frameCreatorChrono(int randomN)
{
        std::string payload;
        double x = (randomN / (double) RAND_MAX);
        //long y = 1000000;
        //double x = (randomN % y) /double(y);
        //std::cout << "x = " << x << std::endl;
        int randlength = 1 + (10-1)*x;
        /*usleep(randlength*10000000);*/
        /*cout << "randlength = " << randlength << endl;*/
        for (int i = 0; i < randlength; ++i)
        {
            payload.push_back('a' + rand()%26);
        }

        return payload;
}
int Host::poissonDelay(int randomN)
{
        double lambda = (1/20.0);
        long y = 100000;
        double x = (randomN % y) /double(y);
        int interArrival = (-1/lambda)*log(x);
        return interArrival;
}
void Host::setFrame(Frame * f1, std::string payload)
{
    f1->setPayload(this->address, this->destAddress, payload);

    std::ofstream myfile;
    myfile.open(this->getName() + "Tx.txt", std::ios::app);
    myfile << std::cout << this->getName() << " : " << "Payload sent: \" " <<  payload << " \" to link " << f1->getName() << std::endl;
    std::cout << this->getName() << " : " << "Payload sent: \" " <<  payload << " \" to link " << f1->getName() << std::endl;
    myfile.close();
}

void Host::processFrame(Frame * f1)
{
    if (f1->getDestAdd() == this->address)
    {
    this->setPayload(f1->getPayload());
    std::string srcAdd = f1->getsourceAdd();
    std::string destAdd = f1->getDestAdd();
    f1->clearPayload();

    std::ofstream myfile;
    myfile.open(this->getName() + "Rx.txt", std::ios::app);
    myfile << this->getName() << " : " << "Payload \" " <<  this->payload << " \" received..." << " from link " << f1->getName() << std::endl;
    std::cout << this->getName() << " : " << "Payload \" " <<  this->payload << " \" received..." << " from link " << f1->getName() << std::endl;
    myfile.close();
    }
}
void Host::run(int randomN)
{
    while (1)
    {
        int interArrival = this->poissonDelay(rand());
        //std::cout << interArrival << endl;
        auto start_time = std::chrono::high_resolution_clock::now().time_since_epoch();
        //std::cout << "Current seconds is : " << (std::chrono::duration_cast<std::chrono::microseconds>(start_time).count())/1000000 << endl << endl << "Waiting..." << endl;
        auto intv = std::chrono::microseconds(interArrival*10000);
        auto totTime = start_time + intv;
        while(std::chrono::high_resolution_clock::now().time_since_epoch() < totTime)
        {
            if (!myport->incomingFrame->isempty())
            {
                if (myport->incomingFrame->getDestAdd() == this->address)
                {
                    this->processFrame(myport->incomingFrame);
                }
            }
        }

        while(1)
        {
            if (myport->outgoingFrame->isempty())
            {
                this->setFrame(myport->outgoingFrame, this->frameCreatorChrono(randomN));
                break;
            }
        }
    }
}

Host::~Host()
{
    //dtor
}
