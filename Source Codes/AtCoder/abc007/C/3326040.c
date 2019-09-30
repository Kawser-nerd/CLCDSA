#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r);
#define TYPE long long
#define MEMSET(a) memset(a,0,sizeof(a))
const int mod=(int)1e09+7;

int in(void){
    int i;scanf("%d",&i);
    return i;
}
double din(void){
    double i;scanf("%lf",&i);
    return i;
}
void chin(char s[]){
    scanf("%s",s);
}
void print(int a){
    printf("%d\n",a);
}
void llprint(long long a){
    printf("%lld\n",a);
}
void dprint(double a){
    printf("%.10f\n",a);
}
void print2(int a,int b){
    printf("%d %d\n",a,b);
}
double dmax(double a,double b){
    return a>b?a:b;
}

int char_cmp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}
int char_cmp_r(const void *a,const void *b){
    return strcmp((char *)b,(char *)a);
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}


int main(void){
    int i, j, k, r, c, sy, sx, gy, gx;    //r:??, c:??, (sy, sx):start
    r=in();
    c=in();
    sy=in();
    sx=in();
    gy=in();
    gx=in();
    int ch[r][c];
    int dp[r][c];
    rep(i, r){
        rep(j, c){
            dp[i][j]=100;
        }
    }
    char c_0[c];
    rep(i,r){
        scanf("%s",c_0);
        rep(j,c){
            if(c_0[j]=='.') ch[i][j]=0;
            else ch[i][j]=-1;
            dp[i][j]=0;
        }
    }
    dp[sy-1][sx-1]=0;
    ch[sy-1][sx-1]=1;
    int x[4]={-1,1,0,0}, y[4]={0,0,-1,1};
    int val=0;
    while(val==0){
        rep(i,r){
            rep(j,c){
                if(ch[i][j]==1){
                    rep(k,4){
                        if(ch[i+x[k]][j+y[k]]==0){
                            dp[i+x[k]][j+y[k]]=dp[i][j]+1;
                            ch[i+x[k]][j+y[k]]++;
                        }
                    }
                    if(ch[gy-1][gx-1]==1) val++;
                }
            }
        }
    }
    print(dp[gy-1][gx-1]);
    return 0;
} ./Main.c: In function ‘in’:
./Main.c:22:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int i;scanf("%d",&i);
           ^
./Main.c: In function ‘din’:
./Main.c:26:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     double i;scanf("%lf",&i);
              ^
./Main.c: In function ‘chin’:
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c: In function ‘main’:
./Main.c:78:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",c_0);
         ^