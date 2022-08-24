#ifndef mSdCard_h
#define mSdCard_h

#include <SPI.h>
#include <SD.h>

class mSdCard
{
private:
    /* data */
    bool initStatus = true;
public:
    mSdCard(/* args */);
    ~mSdCard();

    void init();
    void run();
};

#endif
