#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 10;
    int field[10] = {0};
    int temp[10] = {0};
    
    int *p_field = field;
    int *p_temp = temp;
    
    *(p_field + 2) = 1;
    *(p_field + 4) = 1;
    *(p_field + 6) = 1;
    
    srand(time(NULL));
    
    for (int time = 0; time < 5; time++) {
        printf("Time %d: ", time);
        for (int i = 0; i < size; i++) {
            printf("%d ", *(p_field + i));
        }
        printf("\n");
        
      
        for (int i = 0; i < size; i++) {
            *(p_temp + i) = 0;
        }
       
        for (int i = 0; i < size; i++) {
            if (*(p_field + i) == 1) {
                int direction = rand() % 2;
                int new_pos = i;
                
                if (direction == 0) {
                
                    new_pos = (i > 0) ? i - 1 : 0;
                } else {
                
                    new_pos = (i < size - 1) ? i + 1 : size - 1;
                }
                
                *(p_temp + new_pos) += 1;
            }
        }
        
        for (int i = 0; i < size; i++) {
            if (*(p_temp + i) > 1) {
                printf("Collision on index %d\n", i);
                *(p_field + i) = 0;
            } else {
                *(p_field + i) = *(p_temp + i);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}