#include <stdio.h>

char letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int number[] = {1, 2, 3, 4, 5, 6, 7, 8};

int main(){

    for(int i = 0; i < 8; i++){
        for(int j = 7; j >= 0; j--){
            printf("%c%d ", letter[i], number[j]);
        }
        printf("\n");
    }
    return 0;
}