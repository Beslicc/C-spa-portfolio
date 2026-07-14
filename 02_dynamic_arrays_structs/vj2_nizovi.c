#include <stdio.h>
#include <stdlib.h>

int* podniz(int* niz, int start, int stop) {
    int velicina = stop - start + 1;

    int* novi_niz = (int*)malloc(velicina * sizeof(int));

    if (novi_niz == NULL) {
        return NULL;
    }

    for (int i = 0; i < velicina; i++) {
        novi_niz[i] = niz[start + i];
    }

    return novi_niz;
}

int* filtriraj(int* niz, int n, int th, int* nth) {
    int velicina = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] < th) {
            velicina++;
        }
    }

    *nth = velicina;

    int* novi_niz = (int*)malloc(velicina * sizeof(int));

    if (novi_niz == NULL) {
        return NULL;
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] < th) {
            novi_niz[j] = niz[i];
            j++;
        }
    }

    return novi_niz;
}

int** podijeli(int* niz, int n) {
    int polovica = n / 2;

    int** dijelovi = (int**)malloc(2 * sizeof(int*));

    if (dijelovi == NULL) {
        return NULL;
    }

    dijelovi[0] = (int*)malloc(polovica * sizeof(int));
    dijelovi[1] = (int*)malloc(polovica * sizeof(int));

    if (dijelovi[0] == NULL || dijelovi[1] == NULL) {
        free(dijelovi[0]);
        free(dijelovi[1]);
        free(dijelovi);
        return NULL;
    }

    for (int i = 0; i < polovica; i++) {
        dijelovi[0][i] = niz[i];
    }

    for (int i = 0; i < polovica; i++) {
        dijelovi[1][i] = niz[polovica + i];
    }

    return dijelovi;
}

void ispisi_niz(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");
}

int main(void) {
    printf("Zadatak 1 - podniz\n");

    int niz1[] = { 10, 20, 30, 40, 50 };
    int start = 1;
    int stop = 3;
    int velicina_podniza = stop - start + 1;

    int* rezultat_podniz = podniz(niz1, start, stop);

    if (rezultat_podniz != NULL) {
        printf("Podniz: ");
        ispisi_niz(rezultat_podniz, velicina_podniza);
        free(rezultat_podniz);
    }

    printf("\nZadatak 2 - filtriraj\n");

    int niz2[] = { 5, 12, 3, 20, 8, 1 };
    int n2 = 6;
    int th = 10;
    int nova_velicina = 0;

    int* rezultat_filter = filtriraj(niz2, n2, th, &nova_velicina);

    if (rezultat_filter != NULL) {
        printf("Filtrirani niz: ");
        ispisi_niz(rezultat_filter, nova_velicina);
        printf("Nova velicina: %d\n", nova_velicina);
        free(rezultat_filter);
    }

    printf("\nZadatak 3 - podijeli\n");

    int niz3[] = { 10, 20, 30, 40, 50, 60 };
    int n3 = 6;
    int polovica = n3 / 2;

    int** rezultat_podijeli = podijeli(niz3, n3);

    if (rezultat_podijeli != NULL) {
        printf("Prvi dio: ");
        ispisi_niz(rezultat_podijeli[0], polovica);

        printf("Drugi dio: ");
        ispisi_niz(rezultat_podijeli[1], polovica);

        free(rezultat_podijeli[0]);
        free(rezultat_podijeli[1]);
        free(rezultat_podijeli);
    }

    return 0;
}