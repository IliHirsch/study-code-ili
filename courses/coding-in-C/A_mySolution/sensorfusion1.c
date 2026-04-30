#include<stdio.h>
#include<stdlib.h>


int main()
{
    FILE *file = fopen("test.txt", "r");

    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei");
        return -1;
    }
    
    int c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }

    fclose(file);
    return 0;
}