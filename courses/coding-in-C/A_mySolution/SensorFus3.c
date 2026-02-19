#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSWERTE 3000


/* ----------- Datenstrukturen ----------- */

typedef struct {
    float zeit;            // Zeit in Sekunden
    double wahrscheinlichkeit;  // Signalwert (0..1)
} Messwert;

typedef struct {
    int id;                            // Sensor-ID
    double schwellenwert;              // Detektionsschwelle
    Messwert daten[MAX_MESSWERTE];     // Messdaten
    int detektion[MAX_MESSWERTE];      // Binäres Signal (0/1)
    int anzahl_messwerte;              // Anzahl eingelesener Werte
} Sensor;


/* ----------- Funktionsprototypen ----------- */

int lese_messdaten(const char *dateiname, Sensor *sensor);
void erzeuge_detectionsignal(Sensor *sensor);
void gib_intervalle_aus(const char *titel, Sensor *sensor);
void gib_fusion_aus(Sensor *sensor1, Sensor *sensor2);


/* ----------- Hauptprogramm ----------- */

int main() {

    Sensor sensor1 = {1, 0.8};
    Sensor sensor2 = {2, 0.7};

    if (!lese_messdaten("sensor1.txt", &sensor1)) {
        printf("Fehler beim Lesen von sensor1.txt\n");
        return 1;
    }

    if (!lese_messdaten("sensor2.txt", &sensor2)) {
        printf("Fehler beim Lesen von sensor2.txt\n");
        return 1;
    }

    erzeuge_detectionsignal(&sensor1);
    erzeuge_detectionsignal(&sensor2);

    printf("\n--- Objekterkennung Ergebnisse ---\n\n");

    gib_intervalle_aus("Sensor 1 Detektionen:", &sensor1);
    gib_intervalle_aus("Sensor 2 Detektionen:", &sensor2);
    gib_fusion_aus(&sensor1, &sensor2);

    return 0;
}


/* ----------- Funktionsdefinitionen ----------- */

int lese_messdaten(const char *dateiname, Sensor *sensor) {

    FILE *datei = fopen(dateiname, "r");
    if (datei == NULL) {
        return 0;
    }

    int i = 0;

    while (i < MAX_MESSWERTE &&
           fscanf(datei, "%f %lf",
                  &sensor->daten[i].zeit,
                  &sensor->daten[i].wahrscheinlichkeit) == 2) {
        i++;
    }

    sensor->anzahl_messwerte = i;

    fclose(datei);
    return 1;
}


void erzeuge_detectionsignal(Sensor *sensor) {

    for (int i = 0; i < sensor->anzahl_messwerte; i++) {

        if (sensor->daten[i].wahrscheinlichkeit > sensor->schwellenwert)
            sensor->detektion[i] = 1;
        else
            sensor->detektion[i] = 0;
    }
}


void gib_intervalle_aus(const char *titel, Sensor *sensor) {

    printf("%s\n", titel);

    int aktiv = 0;
    float startzeit = 0.0;

    for (int i = 0; i < sensor->anzahl_messwerte; i++) {

        /* Start eines Intervalls */
        if (!aktiv && sensor->detektion[i] == 1) {
            aktiv = 1;
            startzeit = sensor->daten[i].zeit;
        }

        /* Ende eines Intervalls */
        if (aktiv &&
            (sensor->detektion[i] == 0 ||
             i == sensor->anzahl_messwerte - 1)) {

            float endzeit;

            if (sensor->detektion[i] == 0)
                endzeit = sensor->daten[i - 1].zeit;
            else
                endzeit = sensor->daten[i].zeit;

            printf("Start: %.2f s  Ende: %.2f s\n",
                   startzeit, endzeit);

            aktiv = 0;
        }
    }

    printf("\n");
}


void gib_fusion_aus(Sensor *sensor1, Sensor *sensor2) {

    printf("Fusion (beide Sensoren aktiv):\n");

    int aktiv = 0;
    float startzeit = 0.0;

    int min_messwerte = (sensor1->anzahl_messwerte < sensor2->anzahl_messwerte)
                        ? sensor1->anzahl_messwerte
                        : sensor2->anzahl_messwerte;

    for (int i = 0; i < min_messwerte; i++) {

        int fusion = sensor1->detektion[i] &&
                     sensor2->detektion[i];

        if (!aktiv && fusion) {
            aktiv = 1;
            startzeit = sensor1->daten[i].zeit;
        }

        if (aktiv &&
            (!fusion || i == min_messwerte - 1)) {

            float endzeit;

            if (!fusion)
                endzeit = sensor1->daten[i - 1].zeit;
            else
                endzeit = sensor1->daten[i].zeit;

            printf("Start: %.2f s  Ende: %.2f s\n",
                   startzeit, endzeit);

            aktiv = 0;
        }
    }

    printf("\n");
}