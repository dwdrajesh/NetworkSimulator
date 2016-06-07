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
    //std::mutex * thismutex =  (mymutex);
    this->mymutex.lock();
    this->sourceAdd = a;
    this->mymutex.unlock();

}
std::string Frame::getDestAdd(){
    return this->destAdd;
}
void Frame::setDestAdd(std::string b){
    this->mymutex.lock();
    this->destAdd = b;
    this->mymutex.unlock();
}
void Frame::setPayload(std::string s, std::string d, std::string c){
    this->mymutex.lock();
    this->sourceAdd = s;
    this->destAdd = d;
    this->payload = c;
	this->empty = 0;
    this->mymutex.unlock();
}
std::string Frame::getPayload()
{
    return this->payload;
}
int Frame::isempty()
{
	return this->empty;
}
void Frame::clearPayload()
{
    this->mymutex.lock();
    this->sourceAdd.clear();
    this->destAdd.clear();
    this->payload.clear();
	this->empty = 1;
    this->mymutex.unlock();
}
Frame::~Frame()
{
    //dtor
}

