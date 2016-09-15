#ifndef UNIPOST_H_INCLUDED
#define UNIPOST_H_INCLUDED

/*

SOUMIL VERMA
	UniPost API Header File

    DO NOT MODIFY! We will use this file (as is) to test your program. If you
    change it, your program will not compile properly when we compile using the
    original.
 */

#define UNIPOST_SUCCESS        0
#define UNIPOST_BAD_ARGUMENTS  1
#define UNIPOST_FAILURE        2
#define UNIPOST_FILE_ERROR     3
#define UNIPOST_FILE_CORRUPT   4



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

int UNIPOST_addPost(char *userId, char *network, int year, int month, int day, int hour, int min, int sec, char *post);

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

int UNIPOST_read(char *filename);


/* UNIPOST_write

 Arguments:
 ----------
 filename: string that holds a filename

 Return Values:
 --------------
 UNIPOST_SUCCESS     : File loaded successfully.
 UNIPOST_FILE_ERROR  : File not found or other error
 */

int UNIPOST_write(char *filename);


/* UNIPOST_print
   Print the contents of the data structure to stdout.
 */

void UNIPOST_print();


/* UNIPOST_sortByDate
 Arguments:
 ----------
 chronology : integer value that indicates the order for sorting.
			   0=normal, oldest events come first, newest last
              !0=reverse, newest first and oldest latest

 No return value.
 */

void UNIPOST_sortByDate(int chronology);

/* UNIPOST_sortByUser
 Arguments:
 ----------
 userId: string for userId to match. If it has a non-NULL value, all
		 posts from that user should be first. Otherwise, the order among
         other posts is irrelevant.  If userId is NULL, then the posts should be
         in alphabetical order by userId.

 No return value.

 */

void UNIPOST_sortByUser(char *userId);

/* UNIPOST_sortByNetwork
 Arguments:
 ----------
 network: string for network to match. If it has a non-NULL value, all
          posts from the same network should be first. Otherwise, the order among
          other posts is irrelevant.  If network is NULL, then the posts should be
          in alphabetical order by network name.

 No return value.
 */

void UNIPOST_sortByNetwork(char *network);

/* UNIPOST_sortByTag
 Arguments:
 ----------
 hashtag: string for hashtag. If it has a non-NULL value, all
 posts that contain the hashtag should be first. Otherwise, the order among
 other posts is irrelevant.  If hashtag is NULL, no action is taken.

 No return value.

 */

void UNIPOST_sortByTag(char *hashtag);










#endif // UNIPOST_H_INCLUDED
