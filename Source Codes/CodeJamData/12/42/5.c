#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1024
using namespace std;

int idx[maxn];
int R[maxn];
int X[maxn],Y[maxn];

int cmp(const int &a,const int &b){
    return R[a]>R[b];
}

void sol(int cas){
    int N,W,H;
    int i,j;
    int L,S,M;
    scanf("%d%d%d",&N,&W,&H);
    for (i=0;i<N;i++){
        scanf("%d",R+i);
        idx[i]=i;
    }
    sort(idx,idx+N,cmp);
    L = -1; S = -1; M = -1;
    for (i=0;i<N;i++){
        j = idx[i];
        if (L<0){
            if (S<0){
                X[j]=0;
                Y[j]=0;
                S=R[j];
                M=R[j];
            }else if (S+R[j]<=W){
                X[j]=S+R[j];
                Y[j]=0;
                S+=R[j]*2;
            }else{
                // new line
                L = M;
                S = R[j];
                X[j]=0;
                Y[j]=L+R[j];
                M = R[j];
            }
        }else{
            if (S+R[j]<=W){
                X[j]=S+R[j];
                Y[j]=L+R[j];
                S+=R[j]*2;
            }else{
                L+=2*M;
                S = R[j];
                X[j]=0;
                Y[j]=L+R[j];
            }
        }
    }
    printf("Case #%d:",cas);
    for (i=0;i<N;i++) printf(" %d %d",X[i],Y[i]);
    printf("\n");
}

int main(){
    int t,cas;
    scanf("%d",&t);
    for (cas=1;cas<=t;cas++)
        sol(cas);
    return 0;
}

