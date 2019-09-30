#include<stdio.h>
#include<stdlib.h>

int longest(int *N, int *d){
    int length=0;
        
    for(int i=0; i<*N; i++){
        length+=d[i];
    }

return length;
}

int shortest(int *N, int *d){
    int length=0;
    int temp=0;
    int sum_without_max=0;

    for(int i=0; i<*N; i++){
        for(int j=i+1; j<*N; j++){
            if(d[i]<d[j]){
                temp=d[i];
                d[i]=d[j];
                d[j]=temp;
            }   
        }   
    }

    for(int i=1; i<*N; i++){
        sum_without_max+=d[i];
    }
    
    if(sum_without_max<d[0]) length=d[0]-sum_without_max;

return length;
}

int main(void){
    int N, *d; 
        
    scanf("%d", &N);
    
    d=(int *)malloc(N*sizeof(int));
    for(int i=0; i<N; i++){scanf("%d", &d[i]);}
    
    printf("%d\n", longest(&N, d));
    printf("%d\n", shortest(&N, d));

    free(d);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:44:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0; i<N; i++){scanf("%d", &d[i]);}
                            ^