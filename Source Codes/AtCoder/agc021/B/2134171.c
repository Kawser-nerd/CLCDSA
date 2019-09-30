#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <math.h>
 
 
int main(void){
    double PI=M_PI;
    double po=PI*2/100000;
    int N;
    scanf("%d",&N);
    double x[N],y[N];
    for(int i=0;i<N;i++)scanf("%lf %lf",&x[i],&y[i]);
    int kakuritu[N];
    for(int i=0;i<N;i++)kakuritu[i]=0;
    for(int i=0;i<1000000;i++){
        double max=cos(i*po)*x[0]+sin(i*po)*y[0];
        int maxj=0;
        for(int j=0;j<N;j++){
            if(max<cos(i*po)*x[j]+sin(i*po)*y[j]){max=cos(i*po)*x[j]+sin(i*po)*y[j];maxj=j;}
        }
        kakuritu[maxj]++;
    }
    for(int i=0;i<N;i++){
        printf("%.10f\n",(double)kakuritu[i]/1000000.0f);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:12:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%lf %lf",&x[i],&y[i]);
                         ^