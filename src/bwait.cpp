
#include <Arduino.h>
#include <bwait.h>


    b_wait::b_wait(int wait_time){
        this->wait_time = wait_time;
        this->isActive =false;
        this->start_time = 0;
    }

    void b_wait::start(){
        isActive =true;
        start_time = millis();
    }

    void b_wait::stop(){
        isActive = false;
    }

    void b_wait::reset_en_time(){
        start_time = millis();
    } 

    bool b_wait::GetIsActive(){
        return isActive;
    }

    bool b_wait::is_Time_Enlapsed(){
        
        if(!isActive){
            return false;
    }

        if((millis() - start_time) > wait_time){
            reset_en_time();
            return true;
        }else{
        return false;
        }
    }

