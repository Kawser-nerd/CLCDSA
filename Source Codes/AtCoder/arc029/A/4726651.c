#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int MIN(int a,int b){
    return a<b?a:b;
}
int compare(const void *a,const void *b){
    if(*(int *)a>*(int *)b)return 1;
    return -1;
}
int MAX(int a,int b){
    return a>b?a:b;}
int main()
{   int n;
    scanf("%d",&n);
    int t[n];
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    if(n==1){
        printf("%d",t[0]);
    }
    if(n==2){
        printf("%d",MAX(t[0],t[1]));
    }
    qsort(t,n,sizeof(int),compare);
    if(n==3){
        printf("%d",MAX(t[2],t[0]+t[1]));
    }
    if(n==4){
        
        if(abs(t[3]-(t[0]+t[1]+t[2]))<abs(t[3]+t[0]-(t[1]+t[2]))){
            printf("%d",MAX(t[3],t[1]+t[0]+t[2]));
        }else{
            printf("%d",MAX(t[3]+t[0],t[1]+t[2]));
        }
    }
    
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t[i]);
         ^