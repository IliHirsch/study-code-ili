#include <stdio.h>

#define MASK_ERROR 0b10000000
#define MASK_TEMP 0b01000000
#define MASK_VOLT 0b00100000
#define MASK_VALUE 0b00001111

unsigned char status = 0xA7;
unsigned char value_status;

int main(){
    if (status & MASK_ERROR) {
        printf("Sensorfehler vorhanden\n");
    };
     

    if (status & MASK_TEMP) {
        printf("Temperatur zu hoch\n");
    };

    if (status & MASK_VOLT) {
        printf("Spannung zu niedrig\n");
    };

    unsigned char value_status = status & MASK_VALUE;
    printf("Value Status Code: %u\n", value_status);

    return 0;
}