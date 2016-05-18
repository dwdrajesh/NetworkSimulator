#ifndef FRAME_H
#define FRAME_H
#include <string>
#include <mutex>
/*using namespace std;*/
class Frame
{
    public:


    Frame();
    Frame(std::string name);
    virtual ~Frame();
    std::string getName();
    std::string getsourceAdd();
    void setsourceAdd(std::string);
    std::string getDestAdd();
    void setDestAdd(std::string);
    void setPayload(std::string);
    void clearPayload();
    void setAddresses();
    //void
    std::string getPayload();
    std::mutex mymutex;
	int isempty();
    protected:
    private:
	int empty;
    std::string name;
    std::string sourceAdd;   /* string of length 17 */
    std::string destAdd;     /* string of length 17 */
    std::string payload;

    /*string etherType;    string of length 4 */
    /*string payload;     string of length >= 84 */
    /*string fcs;          string of length 8 */
};

#endif // FRAME_H
