/*
    Created by Shadowsparky, 2019
*/

#include "CustomThread.h"

void CustomThread::run() {
    auto fixed_two_time = first_callback_delay + two_callback_delay; 
    if (millis() - saved_time > first_callback_delay) {
      _t_callback();
      if (millis() - saved_time > fixed_two_time) {
        saved_time = millis();    
      }
    } else {
        _f_callback();
    } 
}