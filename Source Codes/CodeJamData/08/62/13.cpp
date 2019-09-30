#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int data[100][55][55];

int dfx[]={-1,0,0,1};
int dfy[]={0,-1,1,0};

int n,m,px,py;
int res;

void lalala(int time){
    if (data[time][px][py]){
        res>?= time;
        int adj=0;
            for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                if (i && data[time][i][j]&&data[time][i-1][j]) adj++;
                if (j && data[time][i][j]&&data[time][i][j-1]) adj++;                
            }
        if (!adj){ 
            res = 1000000;
            return;
        }
    }
    else return;
    // choose one
    for (int dd=0;dd<4;dd++){
        int tx = px+dfx[dd];
        int ty = py+dfy[dd];
        
        if (tx>=0 && tx<n && ty>=0 && ty<m){
            // do the day
            // recurse
            for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                data[time+1][i][j] = data[time][i][j];
                        
            for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                if (i==px && j==py){
                    data[time+1][tx][ty]-=data[time][px][py];
                    data[time+1][tx][ty]>?=0;
                } else if (data[time][i][j]) {
                    int mmax = -1;
                    int mres = 0;
                    for (int cc = 0; cc<4;cc++){
                        int ppx = i+dfx[cc];
                        int ppy = j+dfy[cc];
                        if (ppx>=0 && ppx<n && ppy>=0 && ppy<m){
                            if (data[time][ppx][ppy]>mres){
                                mmax = cc;
                                mres = data[time][ppx][ppy];
                            }
                        }
                    }
                    if (mmax>=0){
                        data[time+1][i+dfx[mmax]][j+dfy[mmax]]-=data[time][i][j];
                        data[time+1][i+dfx[mmax]][j+dfy[mmax]]>?=0;
                    }
                }
            }
            lalala(time+1);
        }
    }
}

int main(){
    int ntc, ttc=0;
    scanf("%d", &ntc);
    while (ntc--){
            scanf("%d%d%d%d", &m,&n,&py,&px);
            
            px--;py--;
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    scanf("%d", &data[0][i][j]);
                }
            }
            res = 0;
            
            lalala(0);
            
            if (res == 1000000){
                 printf("Case #%d: forever\n",++ttc);            
            } else {
                 printf("Case #%d: %d day(s)\n",++ttc, res);            
            }
            
    }
    return 0;
}
