#include "Frame.h"

Frame::Frame()
{
	this->empty = 1;
//    this->payload = NULL;
    //Default ctor
}
Frame::Frame(std::string name){
	this->empty = 1;
    this->name = name;
}
std::string Frame::getName(){
    return this->name;
}
std::string Frame::getsourceAdd(){
    return this->sourceAdd;
}
void Frame::setsourceAdd(std::string a){
    mymutex.lock();
    this->sourceAdd = a;
    mymutex.unlock();

}
std::string Frame::getDestAdd(){
    return this->destAdd;
}
void Frame::setDestAdd(std::string b){
    mymutex.lock();
    this->destAdd = b;
    mymutex.unlock();
}
void Frame::setPayload(std::string c){
    mymutex.lock();
    this->payload = c;
	this->empty = 0;
    mymutex.unlock();
}
std::string Frame::getPayload(){
    return this->payload;
}
int Frame::isempty()
{
	return this->empty;
}
void Frame::clearPayload()
{
    mymutex.lock();
    this->payload.clear();
	this->empty = 1;
    mymutex.unlock();
}
Frame::~Frame()
{
    //dtor
}

