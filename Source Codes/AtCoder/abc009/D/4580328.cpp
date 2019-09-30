#include<cstdio>
typedef long long ll;
using namespace std;
ll k,m,a[100],c[100],p,b[30][100][100]={},d[100];
int main(){
    scanf("%lld %lld",&k,&m);
    for(int i=0;i<k;i++){
        scanf("%lld",&a[k-1-i]);
    }
    for(int i=0;i<k;i++){
        scanf("%lld",&c[i]);
        b[0][0][i]=c[i];
    }
    for(int i=0;i<k-1;i++){
        b[0][i+1][i]=(ll)(1<<32)-1;
    }
    if((m-1)%2==1){
        for(int i=0;i<k;i++){
            d[i]=0;
            for(int j=0;j<k;j++){
                d[i]^=b[0][i][j]&a[j];
            }
        }
        for(int i=0;i<k;i++){
            a[i]=d[i];
        }
    }
    for(int i=1;i<30;i++){
        for(int j=0;j<k;j++){
            for(int l=0;l<k;l++){
                for(int o=0;o<k;o++){
                    b[i][j][l]^=b[i-1][j][o]&b[i-1][o][l];
                }
            }
        }
        if((m-1)&(1<<i)){
            for(int j=0;j<k;j++){
                d[j]=0;
                for(int l=0;l<k;l++){
                    d[j]^=b[i][j][l]&a[l];
                }
            }
            for(int j=0;j<k;j++){
                a[j]=d[j];
            }
        }
    }
    printf("%lld\n",a[k-1]);
} ./Main.cpp:15:28: warning: shift count >= width of type [-Wshift-count-overflow]
        b[0][i+1][i]=(ll)(1<<32)-1;
                           ^ ~~
1 warning generated.