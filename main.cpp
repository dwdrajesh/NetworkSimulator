#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Frame.h"
#include "Node.h"
#include <math.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include "Host.h"
#include "Port.h"
#include "Switch.h"
using namespace std;
mutex m1;

int main()
{

    Frame f1("A2S");
    Frame f2("S2A");
    Frame f3("B2S");
    Frame f4("S2B");
    Port p1(&f1, &f2);
    Port p2(&f2, &f1);
    Port p3(&f3, &f4);
    Port p4(&f4, &f3);
    Switch s1(& p2, & p4);
    //s1.
    //p1.Run(&f1);
    //p1.Run(&f2);
    Host Alice("Alice", & p1);
    //cout << Bob1.getAddress();
    //Alice.setFrame(f1, "Rajesh");
    Host Bob("Bob", & p3);
    Alice.setdesAddress(Bob.getAddress());
    Bob.setdesAddress(Alice.getAddress());
    //std::vector <Host *> hostlist;
    //hostlist.push_back(& Alice);
    //hostlist.push_back(& Bob);
    s1.configurePorts(& p2, Alice.getAddress());
    s1.configurePorts(& p4, Bob.getAddress());
    std::thread t1(&Host::run, &Alice, rand());
    std::thread t2(&Host::run, &Bob, rand());
    s1.runSwitch();
    t1.join();
    t2.join();
    return 0;
}
