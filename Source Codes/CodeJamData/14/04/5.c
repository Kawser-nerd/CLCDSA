#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int t,T;
int n;
double A[1234],B[1234];
int cmp(const void*a,const void*b){
    double p = *(double*)a;
    double q = *(double*)b;
    return (p>q)?(-1):(p<q);
}

void printNum(){
    int i;
    for(i=0;i<n;++i)printf("%lf ",A[i]);
    puts("");
    for(i=0;i<n;++i)printf("%lf ",B[i]);
    puts("");
}

int solveB(){
    int i,j=0;
    int ans = 0;
    for(i=0;i<n;++i){
        if(A[i]>B[j]){
            ++ans;
        }else if(A[i]<B[j]){
            ++j;
        }
    }
    return ans;
}
int solveA(){
    int i,j;
    int ans = 0;
    //printNum();
    for(i=j=0;j<n;++j){
        //printf("%lf %lf\n",A[i],B[j]);
        if(A[i]>B[j]){
            ++ans;
            ++i;
        }
    }
    return ans;
}
int main(){
    int i;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d",&n);
        for(i=0;i<n;++i)scanf(" %lf",&A[i]);
        for(i=0;i<n;++i)scanf(" %lf",&B[i]);
        qsort(A,n,sizeof(A[0]),cmp);
        qsort(B,n,sizeof(B[0]),cmp);
        printf("Case #%d: %d %d\n",t,solveA(),solveB());

    }

    return 0;
}
