#include<stdio.h>
#include<math.h>

int N;
int dp[10];


int loop(int a,int b,int c){
    if (b == 0){
        if (a == 0){
            return 0;
        }
        return 1;
    }

    if (a/c == 0){
        return loop(a%c,b-1,c/10);
    }

    int res = 0;
    
    res += loop(a%c,b-1,c/10);
    
    if (a/c == 1){
        res += dp[b-1] + a%c+1;
    }else{
        int k = a/c;
        res += dp[b-1] * k + c;
    }

    return res;
}


int main(void){
    scanf("%d",&N);

    dp[0] = 1;
    int i;
    int v = 9;
    for (i=1;i<10;i++){
        dp[i] = v + 1 + dp[i-1] * 10;
        v = v * 10 + 9;
    }
    printf("%d\n",loop(N,(int)log10(N),pow(10,(int)log10(N))));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^