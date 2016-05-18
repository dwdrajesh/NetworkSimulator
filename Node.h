#ifndef NODE_H
#define NODE_H
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "Frame.h"
class Node
{
    public:
        Node();
        //Node(std::string address);

        //std::string getAddress();
        //std::string frameCreator();

        std::string getFrame(Frame & f1);
        virtual ~Node();
    protected:
    private:
        std::string nodeName;
};

#endif // NODE_H
