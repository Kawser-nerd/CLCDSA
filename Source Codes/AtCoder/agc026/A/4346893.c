#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))

int main() {
    long n,pre = -1,count = 0;
    long array[100];

    //input
    scanf("%ld",&n);

    for(int i = 0; i < n; i++){
        scanf("%ld",&array[i]);
        if(array[i] == pre){
            count++;
            pre = -1;
        }else{
            pre = array[i];
        }
    }

    printf("%ld\n", count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&n);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&array[i]);
         ^