#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;
#define mygc(c) (c)=getchar()
void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;} }for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}

int64_t A[5000];
int B[5000][200];

int main(){
    int N,M;
    reader(&N); reader(&M);
    for(int i=1;i<N;i++){
        int a;
        reader(&a);
        A[i]=(int64_t)a+A[i-1];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            reader(&B[i][j]);
        }
    }
    int64_t ans=0;
    for(int i=0;i<N;i++){
        int32_t T[200] = {};
        for(int j=i;j<N;j++){
            int64_t temp=A[i]-A[j];
            for(int k=0;k<200;k++){
                T[k]=max(T[k],B[j][k]);
            }
            for(int k=0;k<200;k++){
                temp+=T[k];
            }
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}