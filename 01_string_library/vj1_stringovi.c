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

void mystrcat(char* dest, const char* src){
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while (src[j]!='\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

char* mystrstr(char* s1, char* s2) {
    if (s2[0] == '\0') {
        return s1;
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        int j = 0;
        while (s1[i + j] != '\0' && s2[j] != '\0' && s1[i + j] == s2[j]) {
            j++;
            if (s2[j] == '\0') {
                return &s1[i];
            }
        }
    }
    return NULL;
}

void reverse(const char* prvi, char* drugi) {
    int duzina = mystrlen(prvi);
    int j = duzina - 1;
    int k = 0;

    while (j >= 0) {
        drugi[k] = prvi[j];
        k++;
        j--;
    }

    drugi[k] = '\0';
}

int main(void) {
	char text[] = "Hello";
    char kopija[50];
    char text2[50] = "World";

    printf("Zadatak1:\n");
    printf("Length: %d\n", mystrlen(text));

    mystrcpy(kopija,text);
    printf("Zadatak2:\n");
    printf("Kopirani string: %s\n", kopija);

    printf("Zadatak3:\n");
    printf("abc vs abc: %d\n", mystrcmp("abc", "abc"));
    printf("abc vs abd: %d\n", mystrcmp("abc", "abd"));
    
    mystrcat(text2, text);
    printf("Zadatak4:\n");
    printf("Spojeni string: %s\n", text2);

    char veliki[] = "abcabbaan";
    char mali[] = "ba";

    char* rezultat = mystrstr(veliki, mali);

    printf("Zadatak5:\n");

    if (rezultat == NULL) {
        printf("Nije pronadeno\n");
    }
    else {
        printf("Pronadeno: %s\n", rezultat);
    }
    return 0;

    char original[] = "Hello";
    char obrnuto[50];

    reverse(original, obrnuto);

    printf("Zadatak6:\n");
    printf("Original: %s\n", original);
    printf("Obrnuto: %s\n", obrnuto);
}