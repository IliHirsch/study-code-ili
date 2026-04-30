#include <stdio.h>

int myNumbers[5] = {10, 20, 30, 40, 50};
int *p1;
int *p2;

int main() {
    p1 = &myNumbers[1];
    p2 = &myNumbers[4];

    printf("Adresse von Zeiger p1: %p\n", p1);
    printf("Adresse von Zeiger p2: %p\n", p2);

    printf("Differenz der Adressen: %ld\n", p2-p1);

    printf("Wert von Zeiger p1: %d\n", *p1);
    printf("Wert von Zeiger p2: %d\n", *p2);

    return 0;
}