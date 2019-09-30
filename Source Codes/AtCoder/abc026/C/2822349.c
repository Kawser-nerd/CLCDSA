#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int n;
bool boss[25];
int b[25];

int sort(const void *a, const void *b){
    return *(int*)a-*(int*)b ;
}

int wage(int a){
    int count=0,p[25];
    if (boss[a]==false){
        return (1);
    } else {
        for (int i=2; i<n+1; i++){
            if (b[i]==a){
                p[count]=wage(i);
                count++;
            }
        }
        qsort (p,count,sizeof(int),sort); 
        for (int i=0; i<count; i++){
        }
        
        return (p[0]+p[count-1]+1);
    }
}
int main(void){
    scanf("%d",&n);
    for (int i=2; i<n+1; i++){
        scanf("%d",&b[i]);
        boss[i]=false;
    }
    for (int i=2; i<n+1; i++){
        boss[b[i]]=true;
    }
    printf("%d\n",wage(1));
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:36:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&b[i]);
         ^