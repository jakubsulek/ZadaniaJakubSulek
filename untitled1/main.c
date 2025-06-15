#include <stdio.h>
#define SIZE 10

void printArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("tabela[%d] = %d\n", i, array[i]);
        printf("(%p) = %d\n\n", array, i, *(array + i));
    }
}

void menu(void) {
    printf("Wybierz opcje: \n");
    printf("1. Wprowadz wartosci do tablicy. \n");
    printf("2. Wyswietl tablice. \n");
    printf("3. Wyswietl najmniejsza wartosc z tablicy. \n");
    printf("4. Wyswietl najwieksza wartosc z tablicy. \n");
    printf("5. Wyswietl srednia wartosc liczb z tablicy.\n");
    printf("6. Zapis tabeli w pliku.\n");
    printf("7. Odczyt tabeli z pliku.\n");
    printf("0. Wyjdz z programu.\n");
}

void numbers(int array[], int size) {
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }
}

void minimum(int *array) {
    int min = *array;
    for (int i = 1; i < SIZE; ++i) {
        if (min > *(array + i)) {
            min = *(array + i);
        }
    }
    printf("Najmniejsza wartoscia w tablicy jest: %d\n\n", min);
}

void maksimum(int *array) {
    int max = *array;
    for (int i = 1; i < SIZE; ++i) {
        if (max < *(array + i)) {
            max = *(array + i);
        }
    }
    printf("Najwieksza wartoscia w tablicy jest: %d\n\n", max);
}

void average(int *array) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += *(array + i);
    }
    float average = (float) sum / SIZE;
    printf("Srednia wartosc liczb to: %f \n\n", average);
}

int zapis(int array[]) {
    FILE *fptr = fopen("C:\\Users\\student\\Desktop\\tak.txt", "w");
    if (fptr == NULL) {
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        fprintf(fptr, "%d\n", array[i]);
    }
    fclose(fptr);
    return 0;
}

int readFromFile(int array[]) {
    FILE *fptr = fopen("C:\\Users\\student\\Desktop\\tak.txt", "r");
    if (fptr == NULL) {
        printf("Nie mozna otworzyc pliku do odczytu.\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        if (fscanf(fptr, "%d", &array[i]) != 1) {
            printf("Blad odczytu danych z pliku.\n");
            fclose(fptr);
            return 2;
        }
    }

    fclose(fptr);
    return 0;
}

int main() {
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int option = 0;
    int errorCode = 0;

    do {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                printf("Wprowadz dane do tablicy\n\n");
                numbers(array, SIZE);
                break;
            case 2:
                printArray(array);
                break;
            case 3:
                printf("Najmniejsza wartosc liczby \n\n");
                minimum(array);
                break;
            case 4:
                printf("Najwieksza wartosc liczby \n\n");
                maksimum(array);
                break;
            case 5:
                printf("Srednia wartosc liczby \n\n");
                average(array);
                break;
            case 6:
                printf("Tabela zapisywana do pliku \n\n");
                errorCode = zapis(array);
                if (!errorCode) {
                    printf("Tabela zapisana do pliku\n\n");
                } else {
                    printf("Przykro mi, zapis się nie udał\n\n");
                }
                break;
            case 7:
                printf("Odczyt tabeli\n\n");
                errorCode = readFromFile(array);
                if (!errorCode) {
                    printf("Tabela odczytana poprawnie.\n\n");
                } else {
                    printf("Blad przy odczycie tabeli.\n\n");
                }
                break;
            default:
                printf("Zla opcja, wybierz liczbe od 0 do 7\n\n");
        }

    } while (option != 0);

    printf("Dobranoc\n");
    return 0;
}
