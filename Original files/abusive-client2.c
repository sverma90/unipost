#include <stdio.h>
#include "unipost.h"
#include <string.h>
#include <time.h>

int Total_Tests = 0;

#define AMOUNT_OF_ABUSE 20

int main(int argc, char **argv)
{
	int success=0;
	int failure=0;

	char name[32];
	char network[32];
	char post[100];

	int i,j;
	int ret;
	int actual;

	srand(time(NULL));

	for(i=0; i<AMOUNT_OF_ABUSE; i++)
	  {
	    sprintf(name,"%d:%c%c_%d",i+1,(char)rand()%26+65,(char)rand()%26+65,rand()%10000);
	    
	    sprintf(network,"%c%c_%c",(char)rand()%26+65,(char)rand()%26+65,(char)rand()%26+65);
	    
	    if(i%300==0)
	      network[0]='\0';

	    for(j=0; j<50;j++)
	      sprintf(&post[j],"%c",(char)(rand()%26+65));
	    
	    if (rand()%100 < 10)
	      sprintf(&post[20]," @random stuff ");

	    ret = UNIPOST_addPost(name,network,2013,rand()%12,rand()%31,rand()%25,rand()%61,rand()%100,post);
	    
	    /* sometimes, network is blank */
	    actual = !(strlen(network)>0);

	    if(ret!=actual)
	      {
		printf("******%d Failed\n",i);
		printf("name:%s\n",name);
		printf("network:%s\n",network);
		printf("post:%s\n",post);
		failure++;
	      }
	    else
	      success++;
	    
	    Total_Tests++;
	  }

	//UNIPOST_print();
	
	printf("Part 1 Complete: %d of %d passed.  %d Failed\n", success,Total_Tests,failure);
	
	if (UNIPOST_write("posts.abusive")==UNIPOST_SUCCESS)
	  printf("Part 2 Complete: Check contents of file named posts.abusive\n");

	printf("----- Printing: Do you see anything? -----\n");
	UNIPOST_print();

	UNIPOST_sortByTag("@random");
	printf("----- Printing: @random posts should be first -----\n");
	UNIPOST_print();
	
	UNIPOST_sortByDate(1);
	printf("----- Printing: posts should be sorted most recent first -----\n");
	UNIPOST_print();

	UNIPOST_sortByUser(NULL);
	printf("----- Printing: posts should be sorted alphabetically by user -----\n");
	UNIPOST_print();

	return 0;	   
}
