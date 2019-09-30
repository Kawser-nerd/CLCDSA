#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int T,t;
int n,p;
int sum;
int a,b;
int s2;
int check1(int now,int s2){
    now +=1;
    int i=0;
    int tmp=0;
    for(i=0;now/=2;++i,tmp+=s2,s2/=2);
    return tmp;
}
int check2(int now,int s2){
    now = sum-now;
    int i=0;
    int tmp=0;
    for(i=0;now/=2;++i,tmp+=s2,s2/=2);
    return sum-tmp-1;
}
int main(){
    int i,j;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d",&n,&p);
        for(sum=1,i=0;i<n;sum*=2,++i);
        s2 = sum/2;
        for(a=0;a<sum-1&&check1(a+1,s2)<p;++a);
        for(b=sum-1;b>0&&check2(b,s2)>=p;--b);

        printf("Case #%d: %d %d\n",t,a,b);


    }

    return 0;
}
