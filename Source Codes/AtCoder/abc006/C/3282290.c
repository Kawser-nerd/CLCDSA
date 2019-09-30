#include<stdio.h>
#include<stdlib.h>
#define rep(i,n) for(i=0;i<n;i++)

int main(void){
    int n, m, i = 0, l, sum, a = -1, b = -1, c = -1;
    scanf("%d%d", &n, &m);
    
    //???a?, ???b?, ???c?
    //??
    //a+b+c = n
    //2a+3b+4c = m
    //?????
    //2n+b+2c = m
    //b + 2c = m-2n
    
    l = m-2*n;
    if(l>=0){
        while((i>l||2*i<l)&&i<n+1){
            i++;
        }
        if(i<n+1){
            int j, k;
            
            //j + k = i
            //j + 2*k = l;
            //i + k = l
            
            k = l - i;
            j = i - k;
            
            a = n - j - k;
            b = j;
            c = k;
        }
    }
    
    printf("%d %d %d\n", a, b, c);
    return 0;

} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &m);
     ^