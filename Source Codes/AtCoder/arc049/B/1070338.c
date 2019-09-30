#include<stdio.h>
double zettaichi(double);
int main(void){
    int N,i,j,l;
    double answer,x[1000],y[1000],c[1000];
    scanf("%d",&N);
    for(i = 0;i < N;i++){
        scanf("%lf%lf%lf",&x[i],&y[i],&c[i]);
    }
    answer = 0;
    for(i = 0;i < N;i++){
        for(j = i + 1;j < N;j++){
            if(answer < zettaichi((x[i] - x[j]) * c[i] * c[j] / (c[i] + c[j]))){
                answer = zettaichi((x[i] - x[j]) * c[i] * c[j] / (c[i] + c[j]));
            }
        }
    }
    for(i = 0;i < N;i++){
        for(j = i + 1;j < N;j++){
            if(answer < zettaichi((y[i] - y[j]) * c[i] * c[j] / (c[i] + c[j]))){
                answer = zettaichi((y[i] - y[j]) * c[i] * c[j] / (c[i] + c[j]));
            }
        }
    }
    printf("%f\n",answer);
    return 0;
}
double zettaichi(double f){
    if(f < 0){
        f = -f;
    }
    return f;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%lf%lf",&x[i],&y[i],&c[i]);
         ^