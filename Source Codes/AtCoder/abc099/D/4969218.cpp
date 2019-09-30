#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int N,C;
    cin >> N >> C;
    vector< vector<int> > Dtable(C, vector<int> (C));
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            cin >> Dtable[i][j];//i??j?????????????
        }
    }
    vector< vector<int> > now(N, vector<int> (N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> now[i][j];
            now[i][j]--;
        }
    }

    vector< vector<int> > sums(3, vector<int> (C));//sums[i][j]?3???????i??????j?????????
    for(int i=0; i<3; i++){
        for(int j=0; j<C; j++){
            sums[i][j]=0;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((i+j)%3==0){
                for(int c0=0; c0<C; c0++){
                    sums[0][c0]+=Dtable[now[i][j]][c0];
                }
            }else if((i+j)%3==1){
                for(int c0=0; c0<C; c0++){
                    sums[1][c0]+=Dtable[now[i][j]][c0];
                }
            }else{
                for(int c0=0; c0<C; c0++){
                    sums[2][c0]+=Dtable[now[i][j]][c0];
                }
            }
        }
    }
    int ans=1000000000;
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            if(i==j) continue;
            for(int k=0; k<C; k++){
                if(i==k || j==k) continue;
                ans = min(ans, sums[0][i]+sums[1][j]+sums[2][k]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}