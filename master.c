#include <avr/io.h>

void SPI_MasterInit(void) {
    DDRB = (1<<PB5)|(1<<PB7)|(1<<PB4);
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData) {
    SPDR = cData;
    while(!(SPSR & (1<<SPIF)));
}

void ADC_Init() {
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);
}

uint16_t ADC_Read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    ADCSRA |= (1<<ADSC);
    while (ADCSRA & (1<<ADSC));
    return ADC;
}
