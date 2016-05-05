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
Host::Host(std::string name)
{
    this->name = name;
}
std::string Host::getAddress()
{
    return this->address;
}
std::string Host::getName()
{
    return this->name;
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
        double lambda = (1/30.0);

        //double x = ((double) rand() / RAND_MAX);
        long y = 100000;
        double x = (randomN % y) /double(y);
        //std::cout << "x = " << x << std::endl;
        int interArrival = (-1/lambda)*log(x);
        return interArrival;
        //std::cout << interArrival << std::endl; /* The exponential random variable based on lambda and the uniform rand variable x*/
}
void Host::setFrame(Frame & f1, std::string payload)
{
    f1.setsourceAdd(this->address);
    f1.setDestAdd(this->address);
    f1.setPayload(payload);
    //this->listSent.push_back(payload);
    if (this->getName() == "Alice")
    {
        //std::ofstream myfile;
        //myfile.open("C:/Users/RAJESH.DAWADI/Dropbox/NetProject/NetProject/aliceTx.txt", std::ios::app);
        //myfile << std::cout << this->getName() << " : " << "Payload sent: \" " <<  payload << " \" to link " << f1.getName() << std::endl;
	std::cout << this->getName() << " : " << "Payload sent: \" " <<  payload << " \" to link " << f1.getName() << std::endl;
        //myfile.close();
    }
    if (this->getName() == "Bob")
    {
        //std::ofstream myfile;
        //myfile.open("C:/Users/RAJESH.DAWADI/Dropbox/NetProject/NetProject/bobTx.txt", std::ios::app);
        //myfile << std::cout << this->getName() << " : " << "Payload sent: \" " <<  payload << " \" to link " << f1.getName() << std::endl;
	std::cout << this->getName() << " : " << "Payload sent: \" " <<  payload << " \" to link " << f1.getName() << std::endl;
        //myfile.close();
    }
}

void Host::processFrame(Frame & f1)
{
    this->setPayload(f1.getPayload());
    //this->listRx.push_back(f1.getPayload());
    f1.clearPayload();
    if (this->getName() == "Alice")
    {
        //std::ofstream myfile;
        //myfile.open("C:/Users/RAJESH.DAWADI/Dropbox/NetProject/NetProject/aliceRx.txt", std::ios::app);
        //myfile << this->getName() << " : " << "Payload \" " <<  this->payload << " \" received..." << " from link " << f1.getName() << std::endl;
	std::cout << this->getName() << " : " << "Payload \" " <<  this->payload << " \" received..." << " from link " << f1.getName() << std::endl;        
//myfile.close();
    }
    if (this->getName() == "Bob")
    {
        //std::ofstream myfile;
        //myfile.open("C:/Users/RAJESH.DAWADI/Dropbox/NetProject/NetProject/bobRx.txt", std::ios::app);
        //myfile << this->getName() << " : " << "Payload \" " <<  this->payload << " \" received..." << " from link " << f1.getName() << std::endl;
	std::cout << this->getName() << " : " << "Payload \" " <<  this->payload << " \" received..." << " from link " << f1.getName() << std::endl;
        //myfile.close();
    }

}
void Host::run(Frame & f1, Frame & f2, int randomN)
{
    //int count = 0;
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
            if (!f2.isempty())
            {
                this->processFrame(f2);

                //rxAlice += 1;
            }
        }
        //std::cout << "Current seconds is : " << (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count())/1000000 << endl;
        while(1)
        {
            if (f1.isempty())
            {
                this->setFrame(f1, this->frameCreatorChrono(randomN));
		//this->setFrame(f1, "Rajesh");
                break;
            }
        }

        //sentAlice += 1;
    //count += 1;
    }
}

Host::~Host()
{
    //dtor
}
