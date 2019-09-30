#include <stdio.h>
int main(void)
{
    long int n;
    scanf("%ld\n",&n);
    long int p[200005]={};
    long int place[200005]={};
    for(int q=0;q<n;q++)
    {
        scanf("%ld\n",&p[q]);
        p[q]-=1;
        place[p[q]]=q;
    }
    long int leng=0;
    long int maxleng=0;
    long int keep=-1;
    long int poi=0;
    while(poi<n)
    {
        if(keep<place[poi])
        {
            keep=place[poi];
            leng++;
            //printf("##%ld,place:%ld##\n",poi,place[poi]);
        }
        else
        {
            if(maxleng<leng)maxleng=leng;
            leng=1;
            keep=place[poi];
            //printf("$$%ld,place:%ld$$\n",poi,place[poi]);
        }
        
        poi++;
    }
    if(maxleng<leng)maxleng=leng;
    printf("%ld\n",n-maxleng);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld\n",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld\n",&p[q]);
         ^