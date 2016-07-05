#include "RomanCAL.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX 4096


void calculateoneplusone(void){
	char ostring1[] = "I";
	char ostring2[] = "I";
	char result[]="II";
	add(ostring1,ostring2);     	     //The result is returned in ostring1
	assert(strcmp(result, ostring1)==0); //Comparing the expected result with the result obtained from add function.
}

int main()
{	
	calculateoneplusone();
	printf("/n Test passed"); 
	return 0;
}

