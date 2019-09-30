//set many funcs template
//Ver.20180717
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}

void shuffledget(int x[],int n){
    srand(time(0));
    int i,b[524288],p,c;
    for(i=0;i<n;i++){
        b[i]=i;
    }
    for(i=n;i>=1;i--){
        p=rand()%i;
        c=b[i-1];b[i-1]=b[p];b[p]=c;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x[b[i]]);
    }
}

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};
int dx8[8]={-1,-1,-1,0,0,1,1,1};
int dy8[8]={-1,0,1,-1,1,-1,0,1};

int search(int x,int a[],int n){
    int st=0,fi=n-1,te;
    while(st<=fi){
        te=(st+fi)/2;
        if(a[te]<x){st=te+1;}else{fi=te-1;}
    }
    return st;
}

typedef struct{
    long long st;
    long long fi;
    double kr;
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

typedef struct{
long long node;
double cost;
}data;
 
data heap[8388608];
long long hsize=0;
 
void resheap(){
    long long i;
    heap[0].node=-1;
    heap[0].cost=-llinf;
    for(i=1;i<8388608;i++){
        heap[i].node=-1;
        heap[i].cost=llinf;
    }
}
 
int swjud(data high,data low){
    if(high.cost > low.cost){return 1;}
    return -1;
}
 
void pqpush(data x){
    long long a,b;
    data m;
    hsize++;
    heap[hsize]=x;
    a=hsize;
    while(1){
        b=a/2;
        if(swjud(heap[b],heap[a]) == 1){
            m=heap[a];heap[a]=heap[b];heap[b]=m;
        }
        else{break;}
        a=b;
    }
}
 
data pqpop(){
    long long a,b,c;
    data m,sw;
    m=heap[1];
    heap[1]=heap[hsize];
    heap[hsize].node=-1;
    heap[hsize].cost=llinf;
    hsize--;
    a=1;
    while(1){
        b=a*2;c=a*2+1;
        if(swjud(heap[a],heap[b])==-1 && swjud(heap[a],heap[c])==-1){break;}
        if(swjud(heap[b],heap[c])==-1){
            sw=heap[a];heap[a]=heap[b];heap[b]=sw;
            a=b;
        }
        else{
            sw=heap[a];heap[a]=heap[c];heap[c]=sw;
            a=c;
        }
    }
    return m;
}

typedef struct{
double xz;
double yz;
double r;
}pd;

double cdist(pd a,pd b){
    double xd,yd,zd;
    xd=dbzt(a.xz,b.xz);
    yd=dbzt(a.yz,b.yz);
    zd=sqrt(xd*xd+yd*yd);
    return dbmax(0.0f,zd-a.r-b.r);
}

int main(void){
    resheap();
    data pdat,od;
    long long i,j,n,m,k,a,b,c,h,w,r=0,l,t;
    double sx,sy,fx,fy;
    double dst[1024];
    double d;
    rs g[1048576];
    mkj x[1048576];
    bool fl[1024]={0};
    pd pt[1024];
    scanf("%lf%lf",&sx,&sy);
    scanf("%lf%lf",&fx,&fy);
    scanf("%lld",&n);
    pt[0].xz=sx;
    pt[0].yz=sy;
    pt[0].r=0;
    pt[n+1].xz=fx;
    pt[n+1].yz=fy;
    pt[n+1].r=0;
    for(i=1;i<=n;i++){
        scanf("%lf%lf%lf",&pt[i].xz,&pt[i].yz,&pt[i].r);
    }
    w=0;
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n+1;j++){
            if(i==j){continue;}
            g[w].st=i;
            g[w].fi=j;
            g[w].kr=cdist(pt[i],pt[j]);
            w++;
        }
    }
    qsort(g,w,sizeof(g[0]),sortfnc);
    makemkj(g,x,w);
    pdat.node=0;
    pdat.cost=0.0f;
    pqpush(pdat);
    while(hsize>0){
        od=pqpop();
        if(fl[od.node]==1){continue;}
        fl[od.node]=1;
        dst[od.node]=od.cost;
        w=od.node;
        for(i=x[w].st;i<x[w].st+x[w].kz;i++){
            if(fl[g[i].fi]==0){
                pdat.node=g[i].fi;
                pdat.cost=od.cost+g[i].kr;
                pqpush(pdat);
            }
        }
    }
    printf("%.12lf\n",dst[n+1]);
    return 0;
} ./Main.c: In function ‘shuffledget’:
./Main.c:31:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[b[i]]);
         ^
./Main.c: In function ‘main’:
./Main.c:167:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf",&sx,&sy);
     ^
./Main.c:168:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf",&fx,&fy);
     ^
./Main.c:169:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:177:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%lf%lf",&pt[i].xz,&pt[i].yz,&pt[i].r);
         ^