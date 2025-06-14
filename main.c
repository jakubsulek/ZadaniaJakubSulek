#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 20

typedef struct {
    char marka[30];
    int rok_produkcji;
    char nr_rejestracyjny[20];
    int przebieg;
} Samochod;

void dodajSamochod(Samochod *tab, int *licznik) {
    if (*licznik >= MAX_CARS) {
        printf("Osiagnieto maksymalna liczbe samochodow.\n");
        return;
    }

    printf("Podaj marke: ");
    scanf(" %[^\n]", tab[*licznik].marka);
    printf("Podaj rok produkcji: ");
    scanf("%d", &tab[*licznik].rok_produkcji);
    printf("Podaj nr rejestracyjny: ");
    scanf(" %[^\n]", tab[*licznik].nr_rejestracyjny);
    printf("Podaj przebieg: ");
    scanf("%d", &tab[*licznik].przebieg);

    (*licznik)++;
}

void wyswietlSamochody(Samochod *tab, int licznik) {
    for (int i = 0; i < licznik; i++) {
        printf("\nSamochod %d:\n", i + 1);
        printf("Marka: %s\n", tab[i].marka);
        printf("Rok produkcji: %d\n", tab[i].rok_produkcji);
        printf("Nr rejestracyjny: %s\n", tab[i].nr_rejestracyjny);
        printf("Przebieg: %d km\n", tab[i].przebieg);
    }
}

void zapiszDoPliku(Samochod *tab, int licznik) {
    FILE *plik = fopen("samochody.txt", "w");
    if (!plik) {
        printf("Blad otwarcia pliku do zapisu.\n");
        return;
    }

    for (int i = 0; i < licznik; i++) {
        fprintf(plik, "%s;%d;%s;%d\n",
                tab[i].marka,
                tab[i].rok_produkcji,
                tab[i].nr_rejestracyjny,
                tab[i].przebieg);
    }

    fclose(plik);
    printf("Dane zapisane do pliku.\n");
}

void wczytajZPliku(Samochod *tab, int *licznik) {
    FILE *plik = fopen("samochody.txt", "r");
    if (!plik) {
        printf("Blad otwarcia pliku do odczytu.\n");
        return;
    }

    *licznik = 0;
    while (fscanf(plik, " %[^;];%d;%[^;];%d\n",
                  tab[*licznik].marka,
                  &tab[*licznik].rok_produkcji,
                  tab[*licznik].nr_rejestracyjny,
                  &tab[*licznik].przebieg) == 4) {
        (*licznik)++;
        if (*licznik >= MAX_CARS) break;
    }

    fclose(plik);
    printf("Dane wczytane z pliku.\n");
}

int main() {
    Samochod samochody[MAX_CARS];
    int licznik = 0;
    int wybor;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Dodaj samochód\n");
        printf("2. Wyswietl samochody\n");
        printf("3. Zapisz do pliku\n");
        printf("4. Wczytaj z pliku\n");
        printf("0. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                dodajSamochod(samochody, &licznik);
                break;
            case 2:
                wyswietlSamochody(samochody, licznik);
                break;
            case 3:
                zapiszDoPliku(samochody, licznik);
                break;
            case 4:
                wczytajZPliku(samochody, &licznik);
                break;
            case 0:
                printf("Zamykanie programu.\n");
                break;
            default:
                printf("Nieprawidłowa opcja.\n");
        }
    } while (wybor != 0);

    return 0;
}
