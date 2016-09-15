#ifndef UNIPOSTADT_H_INCLUDED
#define UNIPOSTADT_H_INCLUDED

struct UniPost
{
    char *userId;
    char *network;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    char *post;
};

struct UniPost posts[100];
//struct UniPost *posts;

int postSize=0;
int postCounter=0;			//copy 25 up to int//

char *ltrim(char *s);
char *trim(char *s);
char *rtrim(char *s);


int IsNullOrEmpty(char *str);
int compareDate(struct UniPost post1,struct UniPost post2);

void CommonUNIPOST_sort(char *key);
void CompareAndSwap_Post(char *str1,char *str2,int j);
void Swap_Post(int j);
void UNIPOST_matchFirst(char *key,char *matchValue);

#endif // UNIPOSTADT_H_INCLUDED
