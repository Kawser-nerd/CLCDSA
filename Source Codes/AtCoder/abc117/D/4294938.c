#include <stdio.h>
int main(void){
    int n,i,j,c[40]={},kb[40];
    long k,a,ans=0;
    scanf("%d%ld",&n,&k);k++;   //K+1??????0?X<K ????
    for(i=0;i<n;i++){
        scanf("%ld",&a);
        for(j=0;j<40;j++){
            c[j]+=a%2;a>>=1;    //j?????1???????
        }
    }
    for(i=0;i<40;i++){          //K?2????
        kb[i]=k%2;k>>=1;
    }
    for(i=0;i<40;i++){
        if(kb[i]){
            //i??1?K????i+1?????K?????i??0?X
            //????1~i-1???????????X
            long s=0; //f(X)?(1<<??)*????1???AxorX???
            //i+1?????k????
            for(j=39;j>i;j--)s+=(1l<<j)*(kb[j]?(n-c[j]):c[j]);
            s+=(1l<<i)*c[j]; //i???0
            //1~i-1???j???1?????0, 0?????1
            for(j=0;j<i;j++)s+=(1l<<j)*(c[j]>n/2?c[j]:n-c[j]);
            ans=ans>s?ans:s;
        }
    }
    printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%ld",&n,&k);k++;   //K+1??????0?X<K ????
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&a);
         ^