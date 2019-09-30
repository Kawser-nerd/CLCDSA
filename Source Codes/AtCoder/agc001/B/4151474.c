#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long max(long long a,long long b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int main()
{
    long long n,x;
    scanf("%lld %lld",&n,&x);
    long long counter=0;
    long long len1,len2,val;
    counter+=n;
    len1=n-max(x,n-x);
    len2=max(x,n-x);
    while(1)
    {if(len2%len1== 0)
    {counter +=(len2/len1)*2*len1 - len1;
    break;}
    else
    {counter+=(len2/len1)*2*len1;
    val=len1;
    len1=len2-(len2/len1)*len1;
    len2=val;}}
    printf("%lld\n",counter);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&n,&x);
     ^