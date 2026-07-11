#include <stdio.h>
#include <string.h>

int mystrlen(char* niz) {
    int duzina = 0;
    
    while (niz[duzina] != '\0') {
        duzina++;
    }

    return duzina;
}

void mystrcpy(char* dest, const char* src) {
    int i = 0;
    
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int mystrcmp(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            i++;
        }
        else {
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}

int main(void) {
	char text[] = "Hello";
    char kopija[50];

    printf("Zadatak1:\n");
    printf("Length: %d\n", mystrlen(text));

    mystrcpy(kopija,text);
    printf("Zadatak2:\n");
    printf("Kopirani string: %s\n", kopija);

    printf("Zadatak3:\n");
    printf("abc vs abc: %d\n", mystrcmp("abc", "abc"));
    printf("abc vs abd: %d\n", mystrcmp("abc", "abd"));
    
    return 0;
}