#include <stdio.h>
#include <stdlib.h>
int N,D;
int X,Y;
double p[1001][1001];

void PascalT(int n){
    int i,j;
    double tmp1,tmp2;
    p[0][0]=1;
    //printf("%f\n",p[0][0]);
    for(i=1;i<=n;i++){
        p[i][0]=p[i-1][0]/2;
        //printf("%f ",p[i][0]);
        for(j=1;j<i;j++){
            p[i][j]=(p[i-1][j-1]+p[i-1][j])/2;
            /*if(j==i/2)
            printf("%f ",p[i][j]);
            //*/
        }
        p[i][i]=p[i-1][i-1]/2;
        //printf("%f\n",p[i][i]);
    }
}

int main(){
    scanf("%d %d",&N,&D);
    scanf("%d %d",&X,&Y);
    if(X%D!=0||Y%D!=0||N-abs(X)/D-abs(Y)/D<0||(N-abs(X)/D-abs(Y)/D)%2!=0){
        printf("0\n");
        return 0;
    }
    X/=D;Y/=D;
    PascalT(N);
    int i,j,k,l;
    double ans=0;
    for(i=0;i<=N;i++){
        double tmp=p[N][i];
        if(i<abs(X)||(i-abs(X))%2!=0)continue;
        if(N-i<abs(Y)||(N-i-abs(Y))%2!=0)continue;;
        //printf("i=%d i-abx(X)=%d N-i=%d (N-i)-abs(Y)=%d\n",i,i-abs(X),N-i,(N-i)-abs(Y));
        tmp*=p[i][abs(X)+(i-abs(X))/2];
        tmp*=p[N-i][abs(Y)+(N-i-abs(Y))/2];
        ans+=tmp;
    }
    printf("%.10f\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&D);
     ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&X,&Y);
     ^