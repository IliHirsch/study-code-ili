#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
    double wert;
    struct Node *ptr;
} Node;

Node *createNode(double wert) {
    Node *newNode = malloc(sizeof *newNode);    //Speicher reservieren
    if (newNode == NULL){
        printf("Speicher Belegung fehlgeschlagen\n");
        return NULL;
    }
    newNode->wert = wert; //schreibe in den erstellten Struct den Wert: wert rein
    newNode->ptr = NULL;  //schreibe in den erstellten Struct den Pointer: Null rein
    return newNode;
}

int main() {
    srand(time(NULL));      //Random Generator starten

    Node *head = NULL;      //Head pointer initalisieren
    Node *current = NULL;   //Zwischenzeiger initialisieren

    for(int i = 0; i < 50; i++){
        Node *newNode = createNode(rand());
    
        if(newNode == NULL){
            printf("Fehler aufgetreten");
            return 1;
        }

        if(head == NULL){   //Wenn die Liste am Anfang beginnt
            head = newNode; //hier brauchen wir die Adressen vom Pointer deswegen kein *ptr (derefenzieren) //Zeige auf 1.Node
            current = head; //Zeige auf Head/1.Node
        }

        else {
            current->ptr = newNode;
            current = newNode;
        }
    }

/********************************************************************************************************************************/

    int arr[51];

    for (int i = 0; i <= 50; i++)
    
/********************************************************************************************************************************/


    return 0;
}