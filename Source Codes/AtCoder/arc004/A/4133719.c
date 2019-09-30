#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double longest(int *N, int *x, int *y){
    double length=0;
    double temp;
    
    for(int i=0; i<*N; i++){
        for(int j=i+1; j<*N; j++){
            temp=(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if(length<temp) length=temp;
        }   
    }

return sqrt(length);
}

int main(void){
    int N, *x, *y; 
    
    scanf("%d", &N);
    
    x=(int *)malloc(N*sizeof(int));
    y=(int *)malloc(N*sizeof(int));
    for(int i=0; i<N; i++){scanf("%d%d", &x[i], &y[i]);}
    
    printf("%10f\n", longest(&N, x, y));

    free(x);
    free(y);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:26:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0; i<N; i++){scanf("%d%d", &x[i], &y[i]);}
                            ^