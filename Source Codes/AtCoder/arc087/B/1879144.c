//set many funcs template
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}
int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int sortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}

int main(void){
    int i,j,x,y,l,f=-1,n;
    int tf,tk=0,tm[8192]={0},ts=0,tfl;
    bool tate[8192];
    int yf,yk=0,ym[8192]={0},ys=0,yfl;
    bool yoko[8192];
    char s[8192];
    for(i=0;i<8192;i++){tate[i]=false;yoko[i]=false;}
    scanf("%s%d%d",s,&x,&y);
    l=strlen(s);
    s[l]='T';
    for(i=0;i<=l;i++){
        if(s[i]=='F'){
            if(f==-1){x--;}
            else if(f==0){ys++;n++;}
            else{ts++;n++;}
        }
        else{
            if(f==-1){f=0;n=0;}
            else if(f==0){
                yk++;
                ym[yk]=n;
                n=0;
            f=1;}
            else{
                tk++;
                tm[tk]=n;
                n=0;
            f=0;}
        }
    }
    tate[0]=true;
    for(i=1;i<=tk;i++){
        for(j=8191-tm[i];j>=0;j--){
            if(tate[j]){tate[j+tm[i]]=true;}
        }
    }
    yoko[0]=true;
    for(i=1;i<=yk;i++){
        for(j=8191-ym[i];j>=0;j--){
            if(yoko[j]){yoko[j+ym[i]]=true;}
        }
    }
    //printf("%d %d %d %d\n",ts,x,ys,y);
    if(!(-ts<= x && x <= ts) || ts%2 != zt(x,0)%2){printf("No\n");return 0;}
    else{tfl=(x+ts)/2;}
    if(!(-ys<= y && y <= ys) || ys%2 != zt(y,0)%2){printf("No\n");return 0;}
    else{yfl=(y+ys)/2;}
    //printf("%d %d\n",tfl,yfl);
    if(tate[tfl] == true && yoko[yfl] == true){printf("Yes\n");}else{printf("No\n");}
    return 0;
} ./Main.c:14:5: warning: conflicting types for built-in function ‘round’
 int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
     ^
./Main.c:15:5: warning: conflicting types for built-in function ‘ceil’
 int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
     ^
./Main.c:20:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
     ^
./Main.c:24:11: warning: conflicting types for built-in function ‘llround’
 long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
           ^
./Main.c: In function ‘main’:
./Main.c:49:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d%d",s,&x,&y);
     ^