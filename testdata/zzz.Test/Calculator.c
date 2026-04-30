#include <stdio.h>

float inputNumber1;
float inputNumber2;
float result;
char operator;

void rechner();
void addition();
void subtraction();
void multiplication();
void division();

int main(){
    printf("Geben Sie ihre erste Zahl ein: ");
    scanf("%f", &inputNumber1);

    printf("Geben Sie ihre zweite Zahl ein: ");
    scanf("%f", &inputNumber2);

    printf("Geben Sie den Operator ein (+, -, *, /): ");
    scanf(" %c", &operator);

    rechner();

    if (inputNumber2 == 0 && operator == '/') {
        return 0;
    }
    else{
        printf("Das Ergebnis ist:\n");
        printf("%.3f %c %.3f = %.3f\n", inputNumber1, operator, inputNumber2, result);
    }

   return 0;
}

/*****************************************************************************/

void rechner(){
   
    switch(operator){
        case '+':
            addition();
            break;
        case '-':
            subtraction();
            break;
        case '*':
            multiplication();
            break;
        case '/':
            division();
            break;
        default:
            printf("Fehler: Ungültiger Operator.\n");
            result = 0;
            break; 
    }

}

/*****************************************************************************/

void addition(){
    result = inputNumber1 + inputNumber2;
}

void subtraction(){
    result = inputNumber1 - inputNumber2;
}

void multiplication(){
    result = inputNumber1 * inputNumber2;
}

void division(){
    if(inputNumber2 != 0){
        result = inputNumber1 / inputNumber2;
    } 
    else {
        printf("Fehler: Division durch Null ist nicht erlaubt.\n");
        result = 0;
    }
}