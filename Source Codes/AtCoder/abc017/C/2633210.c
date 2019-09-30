#include <stdio.h>
int Min(int a,int b){
    return a<b?a:b;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int score[100001]={0};
    int sum=0;
    int i;
    for(i=0;i<n;i++){
        int l,r,s;
        //*
        scanf("%d %d %d",&l,&r,&s);
        /*/
        l=1,r=1,s=5000;
        //*/
        l--;r--;
        score[l]+=s;
        score[r+1]-=s;
        sum+=s;
    }
    for(i=1;i<m;i++){
        score[i]+=score[i-1];
    }

    int min=1e9;
    for(i=0;i<m;i++){
        min=Min(min,score[i]);
    }
    printf("%d\n",sum-min);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&l,&r,&s);
         ^