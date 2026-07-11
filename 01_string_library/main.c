#include <stdio.h>
#include "mystring.h"


int main(void) {
	char text[] = "Hello";

    printf("Text: %s\n", text);
    printf("Length: %d\n", mystrlen(text));

    printf("Length empty: %d\n", mystrlen(""));
    printf("Length abc: %d\n", mystrlen("abc"));
    printf("Length programming: %d\n", mystrlen("programming"));

    return 0;
}