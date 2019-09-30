#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
 
 
int main(void){
    double PI=M_PI;
    double p=PI*2/1000000;

    int N;
    double x[100],y[100];
    int kakuritu[100] ={};

    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%lf %lf",&x[i],&y[i]);

    for(int i=0; i<1000000; i++) {
        double max = cos(i*p)*x[0]+sin(i*p)*y[0];
        int maxj=0;
        for(int j=0; j<N; j++) {
            if(max < cos(i*p)*x[j]+sin(i*p)*y[j]) {
                max = cos(i*p)*x[j] + sin(i*p)*y[j];
                maxj=j;
            }
        }
        kakuritu[maxj]++;
    }
    for(int i=0;i<N;i++){
        printf("%.10f\n",(double)kakuritu[i]/1000000.0f);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf %lf",&x[i],&y[i]);
         ^