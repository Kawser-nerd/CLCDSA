#include<stdio.h>
#include<stdlib.h>
int main(void){
    int n,i;
    double total,temp;
    char *s;
    s=(char*)malloc(sizeof(char)*10);
    scanf("%d",&n);
    total=0;
    for(i=0;i<n;i++){
        scanf("%lf %s",&temp,s);
        if(s[0]=='J'){
            total+=temp;
        }else{
            total+=temp*380000.0;
        }
    }
    printf("%lf\n",total);
    free(s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf %s",&temp,s);
         ^