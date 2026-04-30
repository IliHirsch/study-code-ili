#include <stdio.h>


int main(){
    char string_input[100];
    int lang = 0;
    int palindrom = 1;


    printf("Geben Sie ein Wort ein: ");
    scanf("%s", string_input);

    while (string_input[lang] != '\0') {
        lang++;
    }

    for (int i = 0; i < lang / 2; i++) {
        if (string_input[i] == string_input[lang - 1 - i] || (string_input[i] == (string_input[lang - 1 - i] + 32)) || (string_input[i] == (string_input[lang - 1 - i] - 32))) {
            palindrom = 1;
        } else {
            palindrom = 0;
            break;
        }
    }

    if (palindrom) {
        printf("Das Wort ist ein Palindrom.\n");
    } 
    else {
        printf("Das Wort ist kein Palindrom.\n");
    }

}

