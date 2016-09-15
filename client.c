#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "unipost.h"

const int Total_Tests = 5;

int main(int argc, char **argv)
{
	int success=0;
	int failure=0;
	
	if ( UNIPOST_addPost("steve","twitter",2013,4,8,8,30,02,"Hey @andrew, Happy Birthday! #andrewbday") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;

	if ( UNIPOST_addPost("andrew","twitter",2013,4,8,9,15,43,"Thanks @steve!") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;

	if ( UNIPOST_addPost("lucy","facebook",2013,4,8,12,19,00,"Happy Birthday!") != UNIPOST_SUCCESS )
		failure++;
	else
		success++;
	
	if ( UNIPOST_write("posts.txt") != UNIPOST_SUCCESS )
		failure++;
	else 
		success++;
	
	if ( UNIPOST_read("posts.txt") != UNIPOST_SUCCESS )
		failure++;
	else 
		success++;
	
	printf("-------\n");
	UNIPOST_print();
	printf("-------\n");
	
	printf("%d of %d passed.  %d Failed\n", success,Total_Tests,failure);
	
	return 0;
	   
}
