#include <stdio.h>
#include <math.h>
int main(void){
    int N;
    scanf("%d",&N);
    long long int a[N],b[N];
    double tyux=0.0;
    double tyuy=0.0;
    for(int i=0;i<N;i++){scanf("%lld %lld",&a[i],&b[i]);tyux+=(double)a[i];tyuy+=(double)b[i];}
    tyux/=(double)N;tyuy/=(double)N;
    double maxkyori=-1.0;
    for(int i=0;i<N;i++)if(sqrt((double)((tyux-(double)a[i])*(tyux-(double)a[i])+(tyuy-(double)b[i])*(tyuy-(double)b[i])))>maxkyori)maxkyori=sqrt((double)((tyux-(double)a[i])*(tyux-(double)a[i])+(tyuy-(double)b[i])*(tyuy-(double)b[i])));
    double maxkyoru=maxkyori;
    tyux=0.0;
    tyuy=0.0;
    for(int i=0;i<N;i++){scanf("%lld %lld",&a[i],&b[i]);tyux+=(double)a[i];tyuy+=(double)b[i];}
    tyux/=(double)N;tyuy/=(double)N;
    maxkyori=-1.0;
    for(int i=0;i<N;i++)if(sqrt((double)((tyux-(double)a[i])*(tyux-(double)a[i])+(tyuy-(double)b[i])*(tyuy-(double)b[i])))>maxkyori)maxkyori=sqrt((double)((tyux-(double)a[i])*(tyux-(double)a[i])+(tyuy-(double)b[i])*(tyuy-(double)b[i])));
    printf("%.10f",maxkyori/maxkyoru);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++){scanf("%lld %lld",&a[i],&b[i]);tyux+=(double)a[i];tyuy+=(double)b[i];}
                          ^
./Main.c:16:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++){scanf("%lld %lld",&a[i],&b[i]);tyux+=(double)a[i];tyuy+=(double)b[i];}
                          ^