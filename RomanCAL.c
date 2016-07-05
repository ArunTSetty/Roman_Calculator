#include "RomanCAL.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* add(char* ostring1, char* ostring2) {		
	strcat(ostring1,ostring2); // Concatenating the two strings, since I+II=III
   	return ostring1;
}
