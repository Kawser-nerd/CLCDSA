#include <stdio.h>
#include <string.h>

int main(void){
    char order[100];
    //char number[1000];
    //char *getInt;
    int x[200];
    int j, q, k = 0;
    
    if(fgets(order, 1000, stdin) == NULL){
        printf("????\n");
    }
    sscanf(order, "%d", &j);
    /*if(fgets(number, 1000, stdin) == NULL){
        printf("???\n");
    }
    getInt = strtok(number, " \n");
    sscanf(getInt, "%d", &x[0]);
    for(int i = 1; i < j; i++){
        getInt = strtok(NULL, " \n");
        sscanf(getInt, "%d", &x[i]);
    }*/
    for(int i = 0; i < j; i++){
        scanf("%d", &x[i]);
    }
    while(1){
        for(q = 0; q < j; q++){
            if(x[q] % 2){
                break;
            }else{
                x[q] /= 2;
            }
        }
        if(q == j){
            k++;
        }else{
            break;
        }
    }
    printf("%d\n", k);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &x[i]);
         ^
In file included from /usr/include/stdio.h:937:0,
                 from ./Main.c:2:
In function ‘fgets’,
    inlined from ‘main’ at ./Main.c:12:8:
/usr/include/x86_64-linux-gnu/bits/stdio2.h:261:9: warning: call to ‘__fgets_chk_warn’ declared with attribute warning: fgets called with bigger size than length of destination buffer
  return __fgets_chk_warn (__s, __bos (__s), __n, __stream);
         ^