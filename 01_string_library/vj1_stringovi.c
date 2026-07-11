#include <stdio.h>
#include <string.h>

int mystrlen(char* niz) {
    int duzina = 0;
    
    while (niz[duzina] != '\0') {
        duzina++;
    }

    return duzina;
}

void mystrcpy(char* dest, char* src) {
    int i = 0;
    
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int main(void) {
	char text[] = "Hello";
    char kopija[50];

    printf("Zadatak1:\n");
    printf("Length: %d\n", mystrlen(text));

    mystrcpy(kopija,text);
    printf("Zadatak2:\n");
    printf("Kopirani string: %s\n", kopija);

    return 0;
}