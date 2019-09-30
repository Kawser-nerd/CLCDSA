#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
long long MAX(long long a,long long b){
    return a>b?a:b;
}
long long MIN(long long a,long long b){
    return a<b?a:b;
}
int compare(const void *a,const void *b){
    return *(long long *)a>*(long long *)b?1:-1;
}
long long factrial(int w){
    long long num=1;
    for(int i=1;i<=w;i++){
        num*=i;
        num%=1000000007;
    }    
    return num;
} 
int main()
{   int a,b,n,m,k,x,y,i;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int alp[26]={0};
    long long ans=1,sub=0;
    int letter=0;
    for(i=0;i<n;i++){
        if(alp[s[i]-'a']==0){
            letter++;
        }
        alp[s[i]-'a']++;
        
    }
    for(i=0;i<26;i++){
            ans*=(alp[i]+1);
            ans%=1000000007;
        
    }
    ans-=1;
    
    
    printf("%lld",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^