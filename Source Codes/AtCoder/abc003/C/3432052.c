#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int n,k;
    scanf("%d %d\n",&n,&k);
    int r[n];
    memset(&r,0,sizeof(r));
    //r???????
    char str[5000];
    fgets(str,sizeof(str), stdin);
    char *ptr;

    int *p;
    p = r;
    ptr = strtok(str," ");
    *p = atoi(ptr);

    while(ptr != NULL){
        p++;
        ptr = strtok(NULL," ");

        if(ptr != NULL){
            *p = atoi(ptr);
        }
    }
    int tmp = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(r[i] < r[j]){
                tmp = r[i];
                r[i] = r[j];
                r[j] = tmp;
            }
        }
    }
    double ans = 0;
    for(int i = n -k;i<n;i++){
        ans = (ans+(double)r[i])/2;
        // printf("r %p i %d\n",&r[i],i);
        // printf("r %d i %d\n",r[i],i);
    }
    printf("%f\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n",&n,&k);
     ^
./Main.c:12:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(str,sizeof(str), stdin);
     ^