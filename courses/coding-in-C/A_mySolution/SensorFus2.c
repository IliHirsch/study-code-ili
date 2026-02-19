#include <stdio.h>
#include <string.h>


typedef struct {
    float fuel_level;
    float max_fuel_level;
    char model[50];
} Car;

void refuel(Car *car, float amount) {
     float new_fuel_level = car->fuel_level + amount;
    
    if (new_fuel_level > car->max_fuel_level) {
        printf("Maximale Tankkapazität erreicht.\n");
        car->fuel_level = car->max_fuel_level;
    } 
    
    else{
        car->fuel_level = new_fuel_level;
    }

}

int main() {
    //Ini des Autos
    Car myCar;
    strcpy(myCar.model, "VW Golf 4");
    myCar.fuel_level = 15.5f;
    myCar.max_fuel_level = 60.0f;
    
    printf("Tank System\n");
    printf("Auto Modell: %s\n", myCar.model);
    printf("Tankstand: %.2f Liter\n", myCar.fuel_level);
    printf("Max. Tankstand: %.2f Liter\n\n", myCar.max_fuel_level);
    
   //nachtanken mit 20 Litern
    printf("Tanken mit 20.0 Litern\n");
    refuel(&myCar, 20.0f);
    printf("Neuer Tankstand: %.2f Liter\n\n", myCar.fuel_level);
    
    //nachtanken mit 30 Litern
    printf("Tanken mit 30.0 Liter\n"); 
    refuel(&myCar, 30.0f);
    printf("Neuer Tankstand: %.2f Liter\n", myCar.fuel_level);
    
   
    return 0;
}

