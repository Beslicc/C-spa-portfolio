#include "mystring.h"

int mystrlen(const char* s) {
	int length = 0;

	while (s[length] != '\0') {
		length++;
	}
	return length;
}
