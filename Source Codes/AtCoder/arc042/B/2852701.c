//3D point and line conflict judge
//not conflict with math.h template
//int -> leading i
//max -> imax
//
//llround -> ll_round

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int imax(int a,int b){if(a>b){return a;}return b;}
int imin(int a,int b){if(a<b){return a;}return b;}
int izt(int a,int b){return imax(a,b)-imin(a,b);}
int iround(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int iceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int igcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int ilcm(int a,int b){int c=igcd(a,b);a/=c;return a*b;}
int inCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int ifact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int ipow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long ll_round(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
int isortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int isortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int strsortfncsj(const void *a,const void *b){return strcmp((char *)a,(char *)b);}
int strsortfnckj(const void *a,const void *b){return strcmp((char *)b,(char *)a);}

typedef struct{
	double x;
	double y;
	double z;
}Vertex3D;

#define Vector3D Vertex3D

double distance_vertex(Vertex3D p1, Vertex3D p2) {
	return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y) + (p2.z-p1.z) * (p2.z-p1.z));
}

double length_vector(Vector3D v) {
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vector3D cross_vector(Vector3D vl, Vector3D vr) {
	Vector3D ret;
	ret.x=(vl.y*vr.z) - (vl.z*vr.y);
	ret.y=(vl.z*vr.x) - (vl.x*vr.z);
	ret.z=(vl.x*vr.y) - (vl.y*vr.x);
        //printf("<%.12lf %.12lf %.12lf>\n",ret.x,ret.y,ret.z);
	return ret;
}

double Distance_DotAndLine(Vertex3D P,Vertex3D A,Vertex3D B){
	Vector3D AB,AP;
	AB.x=B.x-A.x;
	AB.y=B.y-A.y;
	AB.z=B.z-A.z;
	AP.x=P.x-A.x;
	AP.y=P.y-A.y;
	AP.z=P.z-A.z;
	double D=length_vector(cross_vector(AB,AP));
	double L=distance_vertex(A,B);
	double H=D/L;
        //printf("%.12lf %.12lf %.12lf\n",D,L,H);
	return H;
}

int main(void){
    int i,j,n,m,k,b,c,w,r=0,l,t;
    double d,res=inf;
    char s[524288];
    Vertex3D a,p[16];
    scanf("%lf%lf%d",&a.x,&a.y,&n);
    a.z=0.0f;
    //l=strlen(s);
    for(i=0;i<n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[i].z=0.0f;
        //printf("%lf\n",p[i].x);
    }
    for(i=0;i<n;i++){
        res=dbmin(res,Distance_DotAndLine(a,p[i],p[(i+1)%n]));
    }
    //shuffledget(a,n);
    //qsort(a,n,sizeof(int),sortfncsj);
    printf("%.12lf\n",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:95:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf%d",&a.x,&a.y,&n);
     ^
./Main.c:99:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%lf",&p[i].x,&p[i].y);
         ^