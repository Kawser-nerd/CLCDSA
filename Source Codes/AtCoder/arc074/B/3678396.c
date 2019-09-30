#include <stdio.h>
#include <stdlib.h>

int assort(const void *a, const void *b){return *(long long*)a-*(long long*)b;}
int dessort(const void *a, const void *b){return *(long long*)b-*(long long*)a;}

int main(void){
    int n;
    scanf("%d",&n);
    long long a[300030],ar[n+1],al[n+1],tmp,R[100005]={},L[100005]={};
    ar[0]=-10e10;
    al[0]=10e10;
    for (int i=0; i<n*3; i++){
        scanf("%lld",&a[i]);
    }
    
    if (n==1){
        tmp=a[0]-a[1];
        tmp=tmp>(a[1]-a[2])?tmp:(a[1]-a[2]);
        tmp=tmp>(a[0]-a[2])?tmp:(a[0]-a[2]);
        printf("%lld\n",tmp);
        return 0;
    }
    
    for (int i=0; i<n; i++){
        ar[i+1]=a[i];
        R[0]+=ar[i+1];
    }
    qsort (ar,n+1,sizeof(long long),assort);
    for (int i=0; i<n; i++){
        tmp=a[i+n];
        if (tmp>ar[1]){
            R[i+1]=R[i]-ar[1]+tmp;
            ar[1]=tmp;
            long long bf=1;
            while(1){
                if (bf*2>n){
                    break;
                }
                if (ar[bf*2]<=ar[bf*2+1] || bf*2+1>n){
                    if (ar[bf]>ar[bf*2]){
                        tmp=ar[bf];
                        ar[bf]=ar[bf*2];
                        ar[bf*2]=tmp;
                        bf=bf*2;
                    } else {
                        break;
                    }
                } else {
                    if (ar[bf]>ar[bf*2+1]){
                        tmp=ar[bf];
                        ar[bf]=ar[bf*2+1];
                        ar[bf*2+1]=tmp;
                        bf=bf*2+1;
                    } else {
                        break;
                    }
                }
            }
        } else {
            R[i+1]=R[i];
        }
    }
    
    for (int i=0; i<n; i++){
        al[i+1]=a[n*3-i-1];
        L[0]+=al[i+1];
    }
    qsort (al,n+1,sizeof(long long),dessort);
    for (int i=0; i<n; i++){
        tmp=a[2*n-i-1];
        if (tmp<al[1]){
            L[i+1]=L[i]-al[1]+tmp;
            al[1]=tmp;
            long long bf=1;
            while(1){
                if (bf*2>n){
                    break;
                }
                if (al[bf*2]>=al[bf*2+1] || bf*2+1>n){
                    if (al[bf]<al[bf*2]){
                        tmp=al[bf];
                        al[bf]=al[bf*2];
                        al[bf*2]=tmp;
                        bf=bf*2;
                    } else {
                        break;
                    }
                } else {
                    if (al[bf]<al[bf*2+1]){
                        tmp=al[bf];
                        al[bf]=al[bf*2+1];
                        al[bf*2+1]=tmp;
                        bf=bf*2+1;
                    } else {
                        break;
                    }
                }
            }
        } else {
            L[i+1]=L[i];
        }
    }
    tmp=R[0]-L[n];
    for (int i=0; i<=n; i++){
        tmp=tmp>(R[i]-L[n-i])?tmp:(R[i]-L[n-i]);
    }
    printf("%lld\n",tmp);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^