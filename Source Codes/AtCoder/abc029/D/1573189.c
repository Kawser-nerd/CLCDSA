#include <stdio.h>

int keta(int N){
    int i;
    for(i=0;N!=0;i++)N/=10;
    return i;
}

int pau(int N){
    if(N==-1)return 0;
    int ans=1;
    for(int i=0;i<N;i++)ans*=10;
    return ans;
}

int ans(int N){
    if(N==0)return 0;
    int unko=keta(N);
    int po=0;
    int buri=N/pau(unko-1);
    N%=pau(unko-1);
    if(buri==1)po=N+1+(unko-1)*pau(unko-2);
    else po=buri*(unko-1)*pau(unko-2)+pau(unko-1);
    return po+ans(N);
}

int main(void){
    int N;
    scanf("%d",&N);
    printf("%d\n",ans(N));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^