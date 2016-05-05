#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Frame.h"
#include "Node.h"
#include <math.h>
/*#include <windows.h>*/
#include <unistd.h>
#include <thread>
#include <mutex>
#include "Host.h"
using namespace std;
mutex m1;
int printscr(int x){
    x = 101;
    return x;
}
int printscr2(int x){
    x = 102;
    return x;
}
int sentBob = 0, sentAlice = 0, rxBob = 0, rxAlice = 0;
int main()
{
    srand(time(0));
    Frame f1("A2B");
    Frame f2("B2A");
    //if (!f1.getPayload().empty()) { cout << "empty" << endl;}
    //else { cout << "Full" << endl;}
    Host Alice("Alice");
    //cout << Bob1.getAddress();
    //Alice.setFrame(f1, "Rajesh");
    Host Bob("Bob");
    //cout << Bob.frameCreatorChrono(rand()) << endl;
    //Bob.setFrame(f2, "Dawadi");
    //Bob.processFrame(f2);
    //Alice.processFrame(f1);

    std::thread t1(&Host::run, &Alice, std::ref(f1), std::ref(f2), rand());
    std::thread t2(&Host::run, &Bob, std::ref(f2), std::ref(f1), rand());
    t1.join();
    t2.join();

    /*while(1){
    cout << Bob.poissonDelay(rand()) << endl;
    }*/
    /*for (int i = 0; i < Alice.listSent.size(); i++)
    {
        cout << "Alice sent: " << endl << endl << Alice.listSent[i] << endl;
    }
    for (int i = 0; i < Bob.listRx.size(); i++)
    {
        cout << "Bob  received: " << endl << endl << Bob.listRx[i] << endl;
    }*/
    return 0;
}
