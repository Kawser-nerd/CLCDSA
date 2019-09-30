#include <stdlib.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    if(*(int *)a> *(int *)b) return -1;
    return 1;
}
int main()
{   int a[5];
    for(int i=0;i<5;i++){
    scanf("%d",&a[i]);
    }
    int b[10]={0},s=0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){
            for(int k=j+1;k<5;k++){
                b[s]=a[i]+a[j]+a[k];
                s++;
            }
        }
    }
    s=0;
    qsort(b,10,sizeof(int),compare);
    for(int i=0;i<9;i++){
        if(b[i]>b[i+1]){
            s++;
        }
        if(s==3){
            printf("%d\n",b[i]);
            break;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^