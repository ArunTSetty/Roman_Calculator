#include "RomanCAL.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 4096
#define ROMANORDER 7
char* subfrom[]= {"IV","IX","XL","XC","CD","CM"};
char* subwith[]={"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};
char* groupfrom[]= {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
char* groupwith[]={"V","X","L","C","D","M"};

char* Group(char* groupfrom[],char* groupwith[],char* originalstring) //To group IIIII->V, VV-->X, XXXXX->L etc.
{
    int j;    
    for (j=0;j<6;j++){
    Replace(originalstring, groupwith[j], groupfrom[j]);
    }
    return originalstring;
}

 char* Sort(char* originalstring)
 {
    char str[4096] = "MDCLXVI" ;
    char temp[4096]="0";
    int i,j,count[7];
    int length =strlen(originalstring);
    
    

    for( i=0; i<7; i++)
    {   
        for( j=0; j<length ;j++)
        {
            if(originalstring[j]== str[i])
            {count[i]++;
            }
        }
    }
    j=0;
    for ( i=0;i<7 ;i++)
    { 
            while(count[i])
        {   temp[j++]= str[i];
            count[i]--;
        }
    }
    strcpy(originalstring, temp);
    return originalstring;
 }



char* ReplaceSubtractives(char* subfrom[],char* subwith[],char* originalstring) //To replace Subtractives (IV-->IIII and vice versa)
{
    int j;    
    for (j=5;j>-1;j--){
    Replace(originalstring, subwith[j], subfrom[j]);
    }
    return originalstring;
}
/**
 * The replace function
 *
 * Searches all of the occurrences using recursion and replaces with the given string
 * Parameters: 
 * char * o_string : The original string
 * char * s_string : The search string to search for
 * char * r_string : The replace string
 */

void Replace(char * o_string, char * s_string, char * r_string) 
{
    char buffer[MAX]; //a buffer to execute replace 
    char * ch; // Store the pointer returned from strstr
    if(!(ch = strstr(o_string, s_string))) //exit condition
    return;
    strncpy(buffer, o_string, ch-o_string); //copy all the content before the first occurrence of the search string to buffer
    buffer[ch-o_string] = 0; //prepare the buffer for appending by adding a null to the end of it
    sprintf(buffer+(ch - o_string), "%s%s", r_string, ch + strlen(s_string)); //append using sprintf function
    o_string[0] = 0; //empty o_string for copying
    strcpy(o_string, buffer);
    return Replace(o_string, s_string, r_string);//pass recursively to replace other occurrences
 }
 
char* add(char* ostring1, char* ostring2) {		
    ReplaceSubtractives(subwith,subfrom,ostring1); //Replace Subtractives for the first Roman numeral (IV-->IIII) 
puts(ostring1);
    ReplaceSubtractives(subwith,subfrom,ostring2); //Replace Subtractives for the second Roman numeral (V)
puts(ostring2);
    strcat(ostring1,ostring2); //Concatenate the two numerals(IIII+V=IIIIV)
puts(ostring1);
    Sort(ostring1);  //Sort in Descending order(VIIII)
puts(ostring1);
    Group(groupwith,groupfrom,ostring1); // Grouping of numerals eg: XXXXX=L, IIIII=V etc.
puts(ostring1);
    ReplaceSubtractives(subfrom,subwith,ostring1); //Replace Reverse Subtractives (VIIII-->IX)
puts(ostring1);
    return ostring1;
}
