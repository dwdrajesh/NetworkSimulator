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

int main()
{

    Frame f1("A2S");
    Frame f2("S2A");
    Frame f3("B2S");
    Frame f4("S2B");
    Frame f5("X2S");
    Frame f6("S2X");
    Frame f7("C2S");
    Frame f8("S2C");
    Port p1(&f1, &f2);
    Port p2(&f2, &f1);
    Port p3(&f3, &f4);
    Port p4(&f4, &f3);
    Port p5(&f5, &f6);
    Port p6(&f6, &f5);
    Port p7(&f7, &f8);
    Port p8(&f8, &f7);
    Switch s1(& p2, & p4, &p6,  &p8);
    Host Alice("Alice", & p1);
    Host Bob("Bob", & p3);
    Host Xyz("Xyz", & p5);
    Host Cde("Cde", & p7);
    Alice.setdesAddress(Bob.getAddress());
    Bob.setdesAddress(Alice.getAddress());
    Xyz.setdesAddress(Cde.getAddress());
    Cde.setdesAddress(Xyz.getAddress());
    std::thread t1(&Host::run, &Alice, rand());
    std::thread t2(&Host::run, &Bob, rand());
    std::thread t3(&Host::run, &Xyz, rand());
    std::thread t4(&Host::run, &Cde, rand());
    s1.runSwitch();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
