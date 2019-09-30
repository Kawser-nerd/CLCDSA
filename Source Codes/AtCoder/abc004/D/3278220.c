#include<stdio.h>
#include<stdlib.h>
#define rep(i,n) for(i=0;i<n;i++)

int min(int a, int b){
    if(a>b) return b;
    else return a;
}

int sum(int n){
    int sum;
    sum=n*(n+1)/2;
    return sum;
}

int num(int a, int num){
    if(a+num<=1000) return sum(1000-a)-sum(1000-a-num);
    else if(a<=1000) return sum(1000-a)+sum(a+num-1001);
    else return sum(a+num-1001)-sum(a-1001);
}

int main(void){
    int i, j, k, draft, draft_1, draft_2, ans = 10000000, r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    rep(i,2000-r-g-b){
        for(j=i+r;j<2000-g-b;j++){
            k = j+g;
            if(k<1100-b/2) k = 1100-b/2;
            draft=num(i+100,r)+num(j,g)+num(k-100,b);
            ans=min(ans, draft);
        }
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &r, &g, &b);
     ^