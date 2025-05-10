#include <avr/io.h>

void SPI_SlaveInit(void) {
    DDRB = (1<<PB6);
    SPCR = (1<<SPE);
}

uint8_t SPI_SlaveReceive(void) {
    while(!(SPSR & (1<<SPIF)));
    return SPDR;
}

void PWM_Init() {
    DDRD |= (1<<PD5);
    TCCR1A = (1<<COM1A1)|(1<<WGM10);
    TCCR1B = (1<<WGM12)|(1<<CS11);
}

void Set_PWM(uint8_t value) {
    OCR1A = value;
}

int main(void) {
    SPI_SlaveInit();
    PWM_Init();
    
    while(1) {
        uint8_t speed = SPI_SlaveReceive();
        Set_PWM(speed);
    }
}
