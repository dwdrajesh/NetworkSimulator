#include "Node.h"
#include "Frame.h"

using namespace std;

Node::Node(){};
std::string Node::getFrame(Frame & f1){
    cout << "Frame received : " << f1.getPayload() << " from link " << f1.getName() << endl;
    return f1.getPayload();

}
Node::~Node()
{
    //dtor
}
