#ifndef servo_h
#define servo_h

#include <Arduino.h>

class Servo{
    private:
        int __pwm_pin;
        float __min_pulse_us, __max_pulse_us;
    public:
        Servo(void);//Crea el objeto servo
        void begin(int pin, float min_pulse_ms, float max_pulse_ms);//Inicializa el servo
        void rotate(int degrees);
        
};
#endif
