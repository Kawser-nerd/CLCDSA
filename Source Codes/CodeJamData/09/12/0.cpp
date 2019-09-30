#include <iostream>
#include <queue>
using namespace std;
long long grid[20][20][3];
long long besttime[40][40];
bool seen[40][40];

int delta[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
long long gettime(int a, int b, int delta, long long start) {
    // at (a,b) at time 'start'
    // going in direction delta
    if (delta==0 && a%2==1 || delta==1 && a%2==0 || delta==2 && b%2==1 || delta==3 && b%2==0) return start+2;
    
    int vx=a/2, vy=b/2;
    bool north = (delta==0 || delta==1);
    
    long long s = grid[vx][vy][0];
    long long w = grid[vx][vy][1];
    long long t = grid[vx][vy][2];
    
    long long gap = ((start-t)%(s+w)+s+w)%(s+w);
    if (gap<s) {
        // currently n/s
        if (north) return start+1;
        else return start+s-gap+1;
    } else {
        if (!north) return start+1;
        else return s+w-gap+start+1;
    }
    
    
    
}
int main() {
    int t = 0;
    int T; scanf("%d",&T); while (T--) {t++;
        int N,M; scanf("%d %d",&N,&M);
        for (int i=0; i<2*N; i++)
        for (int j=0; j<2*M; j++) {besttime[i][j]=-1;seen[i][j]=false;}
        
        for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
        for (int k=0; k<3; k++) scanf("%I64d",&grid[N-1-i][j][k]);
        
        besttime[0][0]=0;
        
        priority_queue<pair<long long,int> > pq;
        pq.push(pair<long long,int>(0,0));
        
        while (!pq.empty()) {
            pair<long long,int> next = pq.top();
            pq.pop();
            int x = next.second%100;
            int y = next.second/100;
            seen[x][y]=true;
            long long curtime = -next.first;
            
            if (besttime[x][y]<curtime) continue;
            
            for (int i=0; i<4; i++) {
                int tx = x + delta[i][0];
                int ty = y + delta[i][1];
                if (tx<0 || ty<0 || tx>=2*N || ty>=2*M || seen[tx][ty]) continue;
                long long newtime = gettime(x,y,i,curtime);
                if (besttime[tx][ty]==-1 || besttime[tx][ty]>newtime) {
                    besttime[tx][ty]=newtime;
                    pq.push(pair<long long,int>(-newtime,ty*100+tx));
                }
            }
        }
        
        printf("Case #%d: %I64d\n",t,besttime[2*N-1][2*M-1]);
    }
}
