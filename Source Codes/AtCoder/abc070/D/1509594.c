#include<stdio.h>
#include<stdlib.h>

typedef struct{
    long long st;
    long long fi;
    long long kr;
}rs;

typedef struct{
    long long st;
    long long kz;
}mkj;

int sortfnc(const void *a,const void *b){
if(((rs*)a)->st == ((rs*)b)->st){return 0;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
return 1;
}

void makemkj(rs g[],mkj x[],long long n){
    long long i,ms=0,nst=g[0].st;
    for(i=1;i<n;i++){
        if(g[i].st!=g[i-1].st){
            x[nst].kz=i-ms;
            x[nst].st=ms;
            nst=g[i].st;ms=i;
        }
    }
    x[nst].kz=n-ms;
    x[nst].st=ms;
}

void calcdif(rs g[],mkj x[],long long nc,long long ndif,long long dif[]){
    long long i;
    for(i=x[nc].st;i<x[nc].st+x[nc].kz;i++){
        if(dif[g[i].fi] != -1){continue;}
        dif[g[i].fi]=ndif+g[i].kr;
        calcdif(g,x,g[i].fi,dif[g[i].fi],dif);
    }
}

int main(void){
    long long n,a[131072],b[131072],c[131072],i;
    long long q,k;
    long long z[131072],y[131072];
    long long dif[131072];
    rs g[262144];
    mkj x[131072];
    scanf("%lld",&n);
    for(i=0;i<n-1;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        g[2*i].st=a[i];g[2*i].fi=b[i];g[2*i].kr=c[i];
        g[2*i+1].st=b[i];g[2*i+1].fi=a[i];g[2*i+1].kr=c[i];
    }
    qsort(g,2*n,sizeof(rs),sortfnc);
    makemkj(g,x,2*n);
    scanf("%lld%lld",&q,&k);
    for(i=0;i<=131071;i++){dif[i]=-1;}
    dif[k]=0;
    calcdif(g,x,k,0,dif);
    for(i=1;i<=q;i++){
        scanf("%lld%lld",&z[i],&y[i]);
        printf("%lld\n",dif[z[i]]+dif[y[i]]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:52:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
         ^
./Main.c:58:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&q,&k);
     ^
./Main.c:63:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&z[i],&y[i]);
         ^