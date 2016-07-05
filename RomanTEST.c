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

void calculatetwoplusone(void){
	char ostring1[] = "II";
	char ostring2[] = "I";
	char result[]="III";
	add(ostring1,ostring2);     	     //The result is returned in ostring1
	assert(strcmp(result, ostring1)==0); //Comparing the expected result with the result obtained from add function.
}

void calculatethreeplusone(void){
	char ostring1[] = "III";
	char ostring2[] = "I";
	char result[]="IV";
	add(ostring1,ostring2);     	     //The result is returned in ostring1
	assert(strcmp(result, ostring1)==0); //Comparing the expected result with the result obtained from add function.
}

void calculatefourplusfive(void){
	char ostring1[] = "IV";
	char ostring2[] = "V";
	char result[]="IX";
	add(ostring1,ostring2);     	     //The result is returned in ostring1
	assert(strcmp(result, ostring1)==0); //Comparing the expected result with the result obtained from add function.
}

void calculatefortynineplusfiftyone(void){
	char ostring1[MAX] = "XLIX"; //49
	char ostring2[MAX] = "LI";   //51	
	char result[MAX]="C";        //100
	add(ostring1,ostring2);     	     //The result is returned in ostring1
	assert(strcmp(result, ostring1)==0); //Comparing the expected result with the result obtained from add function.
}

void calculateFOURHUNDREDFOURplusONEHUNDREDNINETYSIX(void){
	char ostring1[MAX] = "CDIV"; 
	char ostring2[MAX] = "CXCVI";   	
	char result[MAX]= "DC";        
	add(ostring1,ostring2);     	     //The result is returned in ostring1
	assert(strcmp(result, ostring1)==0); //Comparing the expected result with the result obtained from add function.
}

void calculateFIVEHUNDREDFIFTYFIVEplusONETHOUSANDONEHUNDREDELEVEN(void){
	char ostring1[MAX] = "DLV"; 
	char ostring2[MAX] = "MCXI";   	
	char result[MAX]= "MDCLXVI";        
	add(ostring1,ostring2);     	     //The result is returned in ostring1
	assert(strcmp(result, ostring1)==0); //Comparing the expected result with the result obtained from add function.
}


int main()
{	
	calculateoneplusone();
	calculatetwoplusone();
	calculatethreeplusone();
	calculatefourplusfive();
	calculatefortynineplusfiftyone();
	calculateFOURHUNDREDFOURplusONEHUNDREDNINETYSIX();
	printf("Test passed");           
	return 0;
}

