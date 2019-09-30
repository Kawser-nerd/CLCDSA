#include <stdio.h>

void swap(int*, int*);

int main(){
    
    int a[3];
    int cost = 0;
    int i, j;
    for(i = 0; i < 3; i++){
        scanf("%d",&a[i]);
    }
    for(i=0; i<3; i++){
        for(j=i; j<3; j++){
            if(a[i] > a[j]){
                swap(&a[i], &a[j]);
            }
        }
    }
    cost = a[2] - a[0];
    printf("%d\n",cost);
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
} ./Main.c: In function ‘main’:
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^