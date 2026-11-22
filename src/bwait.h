#ifndef B_WAIT_H
#define B_WAIT_H

#include <Arduino.h>

class b_wait{
    private:
    unsigned long int wait_time;
    bool isActive;
    unsigned long int start_time;
    

    public :
    b_wait(int wait_time);
    bool GetIsActive();
    void start();
    void stop();

    void reset_en_time();

    bool is_Time_Enlapsed();

};

#endif
