#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
long long llmax(long long a,long long b){return a>b?a:b;}
long long llmin(long long a,long long b){return a<b?a:b;}
char lowcmp[26]="abcdefghijklmnopqrstuvwxyz";
char upcmp[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
long long mod=1000000007;
int gcd(int a,int b){return min(a,b)==0?(max(a,b)):gcd(min(a,b),(max(a,b)%min(a,b)));}
long long llgcd(long long a,long long b){return llmin(a,b)==0?(llmax(a,b)):llgcd(llmin(a,b),(llmax(a,b)%llmin(a,b)));}
int assort(const void *a,const void *b){return *(int*)a-*(int*)b;}
int dessort(const void *a,const void *b){return *(int*)b-*(int*)a;}
int llassort(const void *a,const void *b){return *(long long*)a-*(long long*)b;}
int lldessort(const void *a,const void *b){return *(long long*)b-*(long long*)a;}
int charassort(const void *a,const void *b){return strcmp((char*)a ,(char*)b);}
int chardessort(const void *a,const void *b){return strcmp((char*)b ,(char*)a);}
void swap(int *a,int *b){int tmp;tmp=*a;*a=*b;*b=tmp;}
void llswap(long long *a,long long *b){long long tmp;tmp=*a;*a=*b;*b=tmp;}
int ntoi(char c){return c-'0';}
int ltoi(char c){return c-'a';}
int utoi(char c){return c-'A';}
long long ncr(int a,int b){long long ans=1;for(int i=0;i<b;i++){ans=ans*(a-i)/(i+1);}return(ans);}
long long npr(int a,int b){long long ans=1;for(int i=0;i<b;i++){ans=ans*(a-i);}return(ans);}

int main(void){
    int n;
    scanf("%d",&n);
    long long a[300030],ar[n+1],al[n+1],tmp,R[100005]={},L[100005]={};
    ar[0]=-1;
    al[0]=10e10;
    for (int i=0; i<n*3; i++){
        scanf("%lld",&a[i]);
    }
    for (int i=0; i<n; i++){
        ar[i+1]=a[i];
        R[0]+=ar[i+1];
    }
    qsort (ar,n+1,sizeof(long long),assort);
    
    for (int i=0; i<n; i++){
        long long NewNode=a[i+n];
        if (NewNode>ar[1]){
            R[i+1]=R[i]-ar[1]+NewNode;
            
            ar[1]=NewNode;
            long long Downheap=1;
            while(1){
                if (Downheap*2>n){
                    break;
                }
                if (ar[Downheap*2]<=ar[Downheap*2+1] || Downheap*2+1>n){
                    if (ar[Downheap]>ar[Downheap*2]){
                        llswap(&ar[Downheap],&ar[Downheap*2]);
                        Downheap=Downheap*2;
                    } else {
                        break;
                    }
                } else {
                    if (ar[Downheap]>ar[Downheap*2+1]){
                        llswap(&ar[Downheap],&ar[Downheap*2+1]);
                        Downheap=Downheap*2+1;
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
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:38:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^