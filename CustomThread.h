/*
    Created by Shadowsparky, 2019
*/

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif
#include <inttypes.h>

class CustomThread {
    protected: 
        unsigned long saved_time; 
        int first_callback_delay; 
        int two_callback_delay;
        void (*_f_callback) (void); 
        void (*_t_callback) (void);

    public: 
        CustomThread(void (*_f_callback_) (void) = NULL, int first_callback_delay_ = -1, void (*_t_callback_) (void) = NULL, int two_callback_delay_ = -1) {
            saved_time = millis(); 
            _f_callback = _f_callback_; 
            first_callback_delay = first_callback_delay_; 
            _t_callback = _t_callback_; 
            two_callback_delay = two_callback_delay_;
        }
        virtual void run();
};  