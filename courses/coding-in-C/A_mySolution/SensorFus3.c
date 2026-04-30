#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float zeit;                         // Zeit in Sekunden
    double wahrscheinlichkeit;          // Signalwert (0,...,1)
} SensorData;

typedef struct {
    int id;                            // Sensor-ID
    double schwellenwert;              // Detektionsschwelle
    SensorData daten[3000];            // Messdaten
    int erkennung[3000];               // Binäres Signal (0/1) / Tipp
    int anzahl_messwerte;              // Anzahl eingelesener Werte
} Sensor;

/**********************************************************************************/

int lese_messdaten(const char *dateiname, Sensor *sensor) {                                         //mit Rückgabewert, deswegen int

    FILE *datei = fopen(dateiname, "r");
    if (!datei)                                                                                     //Fehler beim Öffnen
    {
        return -1;
    }

    int i = 0;
    while (fscanf(datei, "%f %lf",&sensor->daten[i].zeit, &sensor->daten[i].wahrscheinlichkeit) == 2) //Wenn gelesen, dann Werte speichern
    {
        sensor->anzahl_messwerte++;
        i++;
    }

    fclose(datei);
    return 1; 
}

/**********************************************************************************/

void erzeuge_erkennungssignal(Sensor *sensor) {                             //Erkennungsignal als Extrafunktion, 2 Sensoren

    for (int i = 0; i < sensor->anzahl_messwerte; i++) {

        if (sensor->daten[i].wahrscheinlichkeit > sensor->schwellenwert)    //Erkennungsschwelle überschritten
        {
            sensor->erkennung[i] = 1;
        }
        else 
        {
            sensor->erkennung[i] = 0;                                       //Erkennungsschwelle nicht überschritten
        }
    }
}

/**********************************************************************************/

void gib_intervalle_aus(const char *titel, Sensor *sensor) {

    printf("%s\n", titel);                                                              //Printf der übergabe im main

    int aktiv = 0; 
    float startzeit = 0.0; 

    for (int i = 0; i < sensor->anzahl_messwerte; i++)                                  //Start des Intervall
    {
        if (!aktiv && sensor->erkennung[i] == 1) 
        {
            aktiv = 1;                                                                  //Sensor aktiv
            startzeit = sensor->daten[i].zeit;
        }

        
        if (aktiv && (sensor->erkennung[i] == 0 || i == sensor->anzahl_messwerte - 1))  //Ende des Intervall
        {
            float endzeit;

            if (sensor->erkennung[i] == 0)                                              //Sensor wird abgeschaltet
            {
                endzeit = sensor->daten[i - 1].zeit;
            }
            else {
                endzeit = sensor->daten[i].zeit;                                        //Sensor wird am Ende der Liste angeschaltet 
            }

            printf("Objekt erkannt von %.2f s bis %.2f s\n", startzeit, endzeit);       //Ausgabe der Zeiten/Intervalle
            aktiv = 0;
        }
    }
}

/**********************************************************************************/

void gib_fusion_aus(Sensor *sensor1, Sensor *sensor2) {

    printf("\nFusion (beide Sensoren aktiv):\n");

    int aktiv = 0;                                                          //Ini der Werte/Funktion
    float startzeit = 0.0;

    int min_messwerte;                                                      //Variable für Schleifen, Begrenzung

    if (sensor1->anzahl_messwerte < sensor2->anzahl_messwerte)              //Kleinere Anzahl der Messwerte = Begrenzung
    {
    min_messwerte = sensor1->anzahl_messwerte;                              //Sensor1 hat weniger Messwerte
    } 

    else 
    {
    min_messwerte = sensor2->anzahl_messwerte;                              //Sensor2 hat weniger Messwerte
    }

    for (int i = 0; i < min_messwerte; i++) {

        int fusion = sensor1->erkennung[i] && sensor2->erkennung[i];        //Beide Sensoren müssen aktiv sein

        if (!aktiv && fusion) 
        {
            aktiv = 1;
            startzeit = sensor1->daten[i].zeit;
        }

        if (aktiv && (!fusion || i == min_messwerte - 1))                   //Ende der Fusion
            {
            float endzeit;

            if (!fusion)                                                    //Fusion wird unterbrochen
            {
                endzeit = sensor1->daten[i - 1].zeit;
            }
            else
            {
                endzeit = sensor1->daten[i].zeit;
            }

            printf("Start: %.2f s  Ende: %.2f s\n", startzeit, endzeit);    //Ausgabe der Zeiten/Intervalle der Fusion

            aktiv = 0;
        }
    }

    printf("\n");
}

/**********************************************************************************/

int main (){
    Sensor sensor1 = {1, 0.8}; //ID, Schwellenwert
    Sensor sensor2 = {2, 0.7}; //ID, Schwellenwert

    if (!lese_messdaten("sensor1.txt", &sensor1)) {
        printf("Fehler beim Lesen von sensor1.txt\n");
        return -1;
    }

    if (!lese_messdaten("sensor2.txt", &sensor2)) {
        printf("Fehler beim Lesen von sensor2.txt\n");
        return -1;
    }

    erzeuge_erkennungssignal(&sensor1);
    erzeuge_erkennungssignal(&sensor2);

    printf("Objekterkennung Ergebnisse\n");

    gib_intervalle_aus("\nSensor 1 Erkennungen:", &sensor1);
    gib_intervalle_aus("\nSensor 2 Erkennungen:", &sensor2);
    
    gib_fusion_aus(&sensor1, &sensor2);

    return 0;
}