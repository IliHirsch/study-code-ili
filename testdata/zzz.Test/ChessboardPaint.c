#include <stdio.h>

char Letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int Number[] = {1, 2, 3, 4, 5, 6, 7, 8};

int main(){

    printf("\t  8   7   6   5   4   3   2   1\n");
    printf("\n");
    printf("\t+---+---+---+---+---+---+---+---+\n");

      for(int i = 0; i < 8; i++){
        printf("%c\t", Letter[i]);
        for(int j = 7; j >= 0; j--){
            
            if((i + j) % 2 == 0){
                printf("|   ");
            } 
            else {
                printf("|###");
            }
        }
        printf("|");
        printf("\t%c", Letter[i]);
        printf("\n");
        printf("\t+---+---+---+---+---+---+---+---+\n");
    }
    printf("\n");
    printf("\t  8   7   6   5   4   3   2   1\n");

    return 0;

}