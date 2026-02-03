#include <servo.h>

Servo::Servo(void){}

void Servo::begin(int pin, float min_pulse_ms, float max_pulse_ms){
    __pwm_pin = pin;
    __min_pulse_us = min_pulse_ms * 2000;
    __max_pulse_us = max_pulse_ms * 2000;

    // Reset de timers
    TCCR1A = 0;
    TCCR1B = 0;

    // Fast PWM, TOP = ICR1 (modo 14)
    TCCR1A |= (1 << WGM11);
    TCCR1B |= (1 << WGM13) | (1 << WGM12);

    // Prescaler de 8 bits
    TCCR1B |= (1 << CS11);

    // Periodo 20 ms
    ICR1 = 39999;

    if (pin == 9) {
        DDRB |= (1 << PB1);        // Pin 9
        TCCR1A |= (1 << COM1A1);   // Habilitar PWM
        OCR1A = __min_pulse_us;
        
    }
    else if (pin == 10) {
        DDRB |= (1 << PB2);        // Pin 10
        TCCR1A |= (1 << COM1B1);   // Habilitar PWM
        OCR1B = __min_pulse_us;
    }
    else {
        return;
    }
}

void Servo::rotate(int degrees){//Rota el servo a los grados deseados (0-180°).
    //Errores
    if (degrees < 0 || degrees > 180){
        return;
    }
    //Proceso
    int width_pulse = map(degrees, 0, 180, __min_pulse_us, __max_pulse_us);

    if (__pwm_pin == 9){
        OCR1A = width_pulse;
    }
    else if (__pwm_pin == 10){
        OCR1B = width_pulse;
    }
}