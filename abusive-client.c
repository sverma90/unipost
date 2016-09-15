
// SOUMIL VERMA

#include <stdio.h>
#include "unipost.h"

int Total_Tests = 0;

#define AMOUNT_OF_ABUSE 20

int main(int argc, char **argv)
{

/*  char *str1="Hey laura! Thank you";
    char *str2 = "Thank you";
    if(strstr(str1,str2) != NULL)
    {
        printf("\n%s is found in %s",str2,str1);
    }
*/


    int success=0;
	int failure=0;

    if ( UNIPOST_addPost("steve","twitter",2013,4,8,8,30,02,"Hey @steve, Happy Birthday!") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;

	if ( UNIPOST_addPost("lucy","facebook",2013,4,4,12,19,00,"Hey Lucy,Happy Birthday!") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;

	if ( UNIPOST_addPost("andrew","linkedin",2013,4,10,9,15,43,"Hey Andrew! Thank you") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;
    if ( UNIPOST_addPost("mike","facebook",2013,4,7,12,19,00,"Hey michael,Happy Birthday!") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;

	if ( UNIPOST_addPost("laura","twitter",2013,4,8,8,30,43,"Hey laura! Thank you") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;

/*	printf("\n----- Printing: posts should be sorted alphabetically by Date -----\n");
	UNIPOST_print(); */
	
    UNIPOST_sortByDate(0);
	printf("\n----- Printing: posts should be sorted alphabetically by Date -----\n");	
	UNIPOST_print(); 


    UNIPOST_sortByUser("mike");
    printf("\n----- Printing: posts should be sorted alphabetically by UserId -----\n");
	UNIPOST_print();


    UNIPOST_sortByNetwork("facebook");
    printf("\n----- Printing: posts should be sorted alphabetically by Network -----\n");
	UNIPOST_print();


    UNIPOST_sortByTag("Thank you");
    printf("\n----- Printing: posts should be sorted alphabetically by Hashtag -----\n");
	UNIPOST_print();

	return 0;
}
