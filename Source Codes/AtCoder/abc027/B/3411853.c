#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int n,i;
    scanf("%d\n",&n);
    int a[n];
    memset(a,'\0',sizeof(a));
    int people = 0;
    
    char str[1024];
    fgets(str,1024, stdin);
    // printf("%s",str);
    char *ptr;


    int *p;
    p = a;
    ptr = strtok(str," ,");
    *p = atoi(ptr);
    // printf("%d\n",*p);

    while(ptr != NULL){
        ptr = strtok(NULL, ", \n");

        if(ptr != NULL ){
            p++;
            *p = atoi(ptr);
            // printf("%d\n",*p);
        }
    }

    for(i = 0;i<n;i++){
        people += a[i];
    }
    int bridge = 0;
    if(people % n != 0){
        printf("-1\n");
    }else{
        int tmp = 0;
        int num = people / n;
        for(i = 0;i<n;i++){
            if(a[i] > num){
                tmp += a[i] - num;
            }else if(a[i] < num){
                tmp += a[i] - num;
            }
            if(tmp != 0){
                bridge++;
            }
            // printf("%d\n",a[i]);
            // printf("%d\n",bridge);
        }
        printf("%d\n",bridge);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n",&n);
     ^
./Main.c:13:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(str,1024, stdin);
     ^