#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <queue>
using namespace std;
int main()
{
    char ch1[4];
    char ch2[4];
    char ch3[4]={0};//1
    char ch4[4]={0};//2
    scanf("%s %s",ch1,ch2);
    int i;
    for(i=0; i<3; i++)
    {
        ch3[i]=ch1[2-i];
        ch4[i]=ch2[2-i];
    }
    if(strcmp(ch3,ch2)==0&&strcmp(ch4,ch1)==0)
    {
        printf("YES\n");
    }
    if(strcmp(ch3,ch2)!=0||strcmp(ch4,ch1)!=0)
    {
        printf("NO\n");
    }
    return 0;
}