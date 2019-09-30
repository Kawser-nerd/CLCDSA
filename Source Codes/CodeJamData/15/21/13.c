#include "stdio.h"

int getFilpNumber(int n){
    int num = 0;
    while(n){
        num *= 10;
        num += n%10;
        n /= 10;
    }
    return num;
}

int min(int a, int b){
    return a<b?a:b;
}

int t,k,i,filp,n;
int step[1000002];
int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d",&n);
        for(i = 2; i <= n; i++) step[i] = 0;
        step[1] = 1;
        for(i = 1; i<=n; i++){
            filp = getFilpNumber(i);
            if(filp<=n&&(!step[filp]||step[i]+1<step[filp])) step[filp] = step[i]+1;
            if(!step[i+1]||step[i]+1<step[i+1]) step[i+1] = step[i]+1;
        }
        printf("Case #%d: %d\n",k,step[n]);
    }
}
