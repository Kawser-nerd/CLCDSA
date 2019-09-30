#include <iostream>
#include <algorithm>
using namespace std;

int cum[2][4000][4000];

int cumsum(int c, int lx, int rx, int ly, int ry){
    return cum[c][ry][rx]-(ly!=0?cum[c][ly-1][rx]:0)-(lx!=0?cum[c][ry][lx-1]:0)+((lx&&ly)?cum[c][ly-1][lx-1]:0);
}


int main(){
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        char c;
        cin>>c;
        x%=2*K;y%=2*K;
        cum[c=='B'][y][x]++;
        cum[c=='B'][y][x+2*K]++;
        cum[c=='B'][y+2*K][x]++;
        cum[c=='B'][y+2*K][x+2*K]++;
    }
    for(int i=0;i<4*K;i++){
        for(int j=1;j<4*K;j++){
            cum[0][i][j]+=cum[0][i][j-1];
            cum[1][i][j]+=cum[1][i][j-1];
        }
    }
    for(int i=0;i<4*K;i++){
        for(int j=1;j<4*K;j++){
            cum[0][j][i]+=cum[0][j-1][i];
            cum[1][j][i]+=cum[1][j-1][i];
        }
    }
    int ans = 0;
    for(int i=0;i<2*K;i++){
        for(int j=0;j<2*K;j++){
            // cout<<i<<' '<<j<<endl;
            int sum=0;
            sum+=cumsum(1,i,i+K-1,j,j+K-1);
            sum+=cumsum(0,i+K,i+2*K-1,j,j+K-1);
            sum+=cumsum(0,i,i+K-1,j+K,j+2*K-1);
            sum+=cumsum(1,i+K,i+2*K-1,j+K,j+2*K-1);
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;

    return 0;
}