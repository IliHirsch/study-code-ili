#include<stdio.h>

char name[] = "bigstef";
char class[];
int crew;
int mission;
long int distance = 400000000;
float velocity = 33.7;
double range = 43234.891;

int main(){

    printf("Name des Schiffs: \n");
    scanf("%s", class);
    printf("Anzahl der Crewmitglieder: \n");
    scanf("%d", &crew);
    printf("Missionsnummer: \n");
    scanf("%d", &mission);


    printf("\n");
    printf("Name\t\t %s\n", name);
    printf("--------------------------------\n");
    printf("Klasse\t\t %s\n", class);
    printf("Crew\t\t %d\n", crew);
    printf("Mission\t\t %d\n", mission);
    printf("Distance\t %ld\n", distance);
    printf("Velocity\t %.1f\n", velocity);
    printf("Range\t\t %.3lf\n", range);

    return 0;
}