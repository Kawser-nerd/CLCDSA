// @AUTHOR ajay yadav//
#include<stdio.h>
#include<math.h>
#define LL long long
inline void S(LL *);
inline void S(LL *a)
{
char c = 0;
while(c<33)
//c = fgetc_unlocked(stdin);
c = getc(stdin);
*a = 0;
while(c>33)
{
*a = *a*10 + c - '0';
//c = fgetc_unlocked(stdin);
c = getc(stdin);
}
}
int main()
{
int test,i=1;
int r,t,temp;
scanf("%d",&test);
for(i=1;i<=test;i++)
{
    printf("Case #%d: ",i);
    scanf("%d %d",&r,&t);
    r=2*r-1;
    temp=(sqrt((r*r)+8*t)-r)/4;
    printf("%d\n",temp);
}
return 0;
}
