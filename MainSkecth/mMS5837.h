#ifndef mMS5837_h
#define mMS5837_h

#include <Wire.h>

class mMS5837
{
private:
    /* data */
    bool initStatus = true;
public:
    mMS5837(/* args */);
    virtual ~mMS5837();

    void init();
    void run();
};

#endif
