#include <Wire.h>

class mMS5837
{
private:
    /* data */
    bool initStatus;
public:
    mMS5837(/* args */);
    virtual ~mMS5837();

    void init();
    void readData();
};
