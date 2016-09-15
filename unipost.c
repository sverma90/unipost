/*
 
	Soumil Verma
	ECE 209 - 002
	April 25th, 2013
 
   UniPost.c
   Program 3, ECE 209 2013
 */

/*
 UniPost API Header File
 Program 3, ECE 209 Spring 2013

 DO NOT MODIFY! We will use this file (as is) to test your program. If you
 change it, your program will not compile properly when we compile using the
 original.
 */
#include <stdio.h>						/* Defined libraries*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "unipost.h"				// THIS PROGRAM MUST RUN WITH unipost.h and unipostAdt.h 
#include "unipostAdt.h"

/* UNIPOST_addPost

 Arguments:
 ----------
 userId: string for user name or user ID (case sensitive), no longer
 than 32 characters including null terminator.
 network: string for network name (case sensitive), no longer than
 32 characters including null terminator.
 year: integer for the year (any integer)
 month: integer for the month (1 to 12)
 day: integer for the day (1 to 31)
 hour: integer for 24-hour day (0 to 23)
 min: integer for minutes (0 to 59)
 sec: integer for seconds (0 to 59)
 post: string that contains the post, it could be of arbitrary length

 Return Values:
 --------------
 UNIPOST_SUCCESS      : Post added successfully to an internal data structure.
 UNIPOST_BAD_ARGUMENTS: One of the arguments was illegal and could not be
 corrected. No post was added.
 UNIPOST_FAILURE      : UniPost could not support another post for some reason.

 */

int UNIPOST_addPost(char *userId, char *network, int year, int month, int day, int hour, int min, int sec, char *post)
{
    if(IsNullOrEmpty(userId))
    {
        return UNIPOST_BAD_ARGUMENTS;			//if userid or network is null or empty it would return bad arguments.
    }
    if(IsNullOrEmpty(network))			
    {
        return UNIPOST_BAD_ARGUMENTS;
    }
    if(month < 1 || month > 12)					//If date, month, hour, min is less than/greater than what is specified, it would return a -1
    {
        month = -1;
    }

    if(day < 1 || day > 31)
    {
        day = -1;
    }

    if( hour < 1 || hour > 23)
    {
        hour = -1;
    }

    if(min < 0 || min > 59)
    {
        min = -1;
    }

    if(post == NULL)						//If post is null, it would return unipost bad arguments.
    {
        return UNIPOST_BAD_ARGUMENTS;
    }

	struct UniPost po;						//Using struct to define the following and a counter that loads the next value
	po.userId = userId;
    po.network = network;
    po.year = year;
    po.month = month;
    po.day = day;
    po.hour = hour;
    po.min = min;
    po.sec = sec;
    po.post = post;

    posts[postCounter]= po;
    postCounter++;

	return UNIPOST_SUCCESS;
}

int IsNullOrEmpty(char *str)				//if text is empty or null, it returns one otherwise it would load trim function to remove unnecessary text
{
    if(str == NULL)
    {
         return 1;
    }

    str = trim(str);
    int len = strlen(str);
    if(len == 0)
    {
       return 1;
    }

    return 0;
}

char* ltrim(char *s)				//Controls the text on left side and deletes unnecessary space includes a forloop that controls the text
{
    int len=strlen(s);
    if(len == 0)
    {
        return s;
    }
    int i;
    for(i=0;i<len;i++)
    {
        if(!isspace(*s))	//LINE CAUSING WARNING...
            {
                break;
            }
            else
            {
                s++;
            }
    }
    return s;
}


char* rtrim(char *s)					//Controls the text on right side and deletes unnecessary space, includes a for loop that controls the text
{
	int len=strlen(s);

    if(len == 0)
    {
        return s;
    }
    int i,j=0;
    char *retstr=NULL;
    retstr = (char*) malloc(len*sizeof(char));

    for(i=0;i<len;i++)
    {
        if(!isspace(*(s+len-1-i)))
        {
            retstr[len-1-i]=*(s+len-1-i);
            j++;
        }
    }
    retstr[j]='\0';

    return retstr;
}


char* trim(char *s)					//Controls which direction to trim for text
{
    int len=strlen(s);
    if(len == 0)
    {
        return s;
    }
    return rtrim(ltrim(s));				
}


/* UNIPOST_read

 Arguments:
 ----------
 filename: string that holds a filename

 Return Values:
 --------------
 UNIPOST_SUCCESS     : File loaded successfully.
 UNIPOST_FILE_ERROR  : File not found or contained no data
 UNIPOST_FILE_CORRUPT: Some posts were added, but  possibly not the entire file.

 */

int UNIPOST_read(char *filename)					//function reads the file and the print statement below is to check if the function is reading the file
{

    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("\nFile not found.\n");				//If it does not able to read file then it prints error
        return UNIPOST_FILE_ERROR;
    }

    struct UniPost po;
    while(fread(&po,sizeof(po),1,fp) > 0)
    {
        printf("\n%s \t %s \t %d \t %d \t %d \t %d:%d:%d \t %s",po.userId,po.network,po.year,po.month,po.day,po.hour,po.min,po.sec,po.post);
    }

    fclose(fp);

	return UNIPOST_SUCCESS;
}


/* UNIPOST_write

 Arguments:
 ----------
 filename: string that holds a filename

 Return Values:
 --------------
 UNIPOST_SUCCESS     : File loaded successfully.
 UNIPOST_FILE_ERROR  : File not found or other error
 */

int UNIPOST_write(char *filename)				// Function designed to write the output to file, if value is null then it would print error message.
{
    int i;
    FILE *fp = fopen(filename,"w");
    if(fp == NULL)
    {
        printf("\nFile not found or no data saved.");
        return UNIPOST_FILE_ERROR;
    }

    for(i=0; i<postCounter;i++)
    {
        fwrite(&posts[i],sizeof(posts[i]),1,fp);
    }

    fclose(fp);

	return UNIPOST_SUCCESS;
}

/* UNIPOST_print
 Print the contents of the data structure to stdout.
 */

void UNIPOST_print()									//the print function prints to stdout
{
    int i=0;
    printf("\nUser ID  network \t year \t month \t day \t hour:min:sec \t post\n\n");
    for(i=0;i<postCounter;i++)
    {
		printf("%10s %8s  %d/ %d %2d:%d %47s\n", posts[i].userId, posts[i].network, posts[i].month, posts[i].day, posts[i].hour, posts[i].min, posts[i].post);
    }
}

/* UNIPOST_sortByDate
 Arguments:
 ----------
 chronology : integer value that indicates the order for sorting.
 0=normal, oldest events come first, newest last
 !0=reverse, newest first and oldest latest

 If there is nothing to sort, do nothing.

 No return value.
 */

void UNIPOST_sortByDate(int chronology)					//Sorting method for all dates available that includes both outer and inner for loop
{														/*on abusive client file that I submitted, If you set unipost_sortbydate to 0, it prints in ascending order, 1 will print in decending order*/
    int i,j;
    for(i=0;i<postCounter;i++)
    {
        for(j=0;j<postCounter-1;j++)
        {
            if(chronology == 0)
            {
                if(compareDate(posts[j],posts[j+1]) > 0 )
                {
                    Swap_Post(j);
                }
            }
            else
            {
                if(compareDate(posts[j],posts[j+1]) < 0 )
                {
                    Swap_Post(j);
                }
            }
        }
    }
}

/* UNIPOST_sortByUser
 Arguments:
 ----------
 userId: string for userId to match. If it has a non-NULL value, all
 posts from that user should be first. Otherwise, the order among
 other posts is irrelevant.  If userId is NULL, then the posts should be
 in alphabetical order by userId.

 If there is nothing to sort, do nothing.

 No return value.

 */

void UNIPOST_sortByUser(char *userId)				//sorting function for sortbyuser
{

    char *key = "userId";
    if(userId == NULL)
    {
        CommonUNIPOST_sort(key);
    }
    else
    {
       UNIPOST_matchFirst(key,userId);
    }

}

/* UNIPOST_sortByNetwork
 Arguments:
 ----------
 network: string for network to match. If it has a non-NULL value, all
 posts from the same network should be first. Otherwise, the order among
 other posts is irrelevant.  If network is NULL, then the posts should be
 in alphabetical order by network name.

 If there is nothing to sort, do nothing.

 No return value.
 */

void UNIPOST_sortByNetwork(char *network)			//sort function for sorting by network, targets another function below
{
    char *key = "network";
    if(network == NULL)
    {
        CommonUNIPOST_sort(key);
    }
    else
    {
       UNIPOST_matchFirst(key,network);
    }
}

/* UNIPOST_sortByTag
 Arguments:
 ----------
 hashtag: string for hashtag. If it has a non-NULL value, all
 posts that contain the hashtag should be first. Otherwise, the order among
 other posts is irrelevant.  If hashtag is NULL, no action is taken.

 If there is nothing to sort, do nothing.

 No return value.

 */

void UNIPOST_sortByTag(char *hashtag)				//sorting function by hashtag (based on tthe post)
{
    if(hashtag == NULL)
    {
        return;
    }
    char *key = "post";
    UNIPOST_matchFirst(key,hashtag);
}

int compareDate(struct UniPost post1,struct UniPost post2)			//function controls the date
{
    int ret;

    struct tm date1;
    date1.tm_year = post1.year - 1900;
    date1.tm_mon = post1.month - 1;
    date1.tm_mday = post1.day;
    date1.tm_hour = post1.hour;
    date1.tm_min = post1.min;
    date1.tm_sec = post1.sec;
    date1.tm_isdst = -1;

    time_t total_second1 = mktime(&date1);

    struct tm date2;
    date2.tm_year = post2.year - 1900;
    date2.tm_mon = post2.month - 1;
    date2.tm_mday = post2.day;
    date2.tm_hour = post2.hour;
    date2.tm_min = post2.min;
    date2.tm_sec = post2.sec;
    date2.tm_isdst = -1;

    time_t total_second2 = mktime(&date2);

    if(total_second1 > total_second2)				//controls date value and returns a following values
    {
        ret = 1;
    }
    else if(total_second1 < total_second2)
    {
        ret = -1;
    }
    else if(total_second1 == total_second2)
    {
        ret = 0;
    }
    return ret;
}

void UNIPOST_matchFirst(char *key,char *matchValue)				//matches post by userid network posts and performs the sort method, uses a counter to load the next post
{
    int i,matchedPositions[postCounter];
    int matchCounter=0;
        for(i=0;i<postCounter;i++)
        {
            if(strcmp(key ,"userId") == 0)
            {
                if(strcmp(posts[i].userId,matchValue) == 0)
                {
                    matchedPositions[matchCounter++]=i;
                }
            }
            else if(strcmp(key, "network") == 0)
            {
                if(strcmp(posts[i].network,matchValue) == 0)
                {
                    matchedPositions[matchCounter++]=i;
                }
            }
            else if(strcmp(key, "post") == 0)
            {
                if(strstr(posts[i].post,matchValue) != NULL)
                {
                    matchedPositions[matchCounter++]=i;
                }
            }
        }

        if(matchCounter > 0)								//counter to load the next posts
        {
            int j;
            for(j=0;j<matchCounter;j++)
            {
                struct UniPost tempMatch;
                int matchPos=matchedPositions[j];
                tempMatch = posts[matchPos];
                for(i=matchPos;i>j;i--)
                {
                    posts[i]=posts[i-1];
                }
                posts[j] = tempMatch;
            }
        }
}

void CommonUNIPOST_sort(char *key)				//uses forloop to make the swap and calls on compareandswap to use particular sorting
{
    int i,j;
    for(i=0;i<postCounter;i++)
    {
        for(j=0;j<postCounter-1;j++)
        {
            if(strcmp(key ,"userId") == 0)
            {
                CompareAndSwap_Post(posts[j].userId,posts[j+1].userId,j);
            }
            else if(strcmp(key,"network") == 0)
            {
                CompareAndSwap_Post(posts[j].network,posts[j+1].network,j);
            }
        }
    }

}
void CompareAndSwap_Post(char *str1,char *str2,int j)			//Loads swap post for compareandswap_post
{
    if(strcmp(str1,str2) > 0)
    {
        Swap_Post(j);
    }
}

void Swap_Post(int j)					//Sorting method for swap post
{
    struct UniPost tempPost;
    tempPost = posts[j];
    posts[j]= posts[j+1];
    posts[j+1] =tempPost;
}

