#include  <cstdio> 
#include  <cstdlib> 
#include  <cstring> 
#include  <string> 
#include  <vector> 
#include  <cmath> 
#include  <algorithm> 
#include  <cassert> 
#include  <set> 
#include  <map> 
#include  <queue> 
#include  <iostream> 
#include <fstream> 
using namespace std; 
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )  

typedef long long LL; 
typedef pair<int,int> pii; 

map<int, int> res;

string mp[1024];
int g[1024][1024];
int next[1024][1024];
int mx[1024][1024];

#define clr(a) memset(a,0,sizeof(a))
#define maxn 1200
int c[maxn][maxn];
int n;
int lowbit(int x){
    return x&(-x);
}
void Update(int x,int y,int t){
    x++;y++;
    int i,j;
    i = x;
    while(i<=n){
        j=y;
        while(j<=n){
            c[i][j]+=t;
            j+=lowbit(j);
        }
        i+=lowbit(i);
    }
}
int Query(int x,int y){
    x++;y++;
    int i,j,s=0;
    i=x;
    while(i>0){
        j=y;
        while(j>0){
            s+=c[i][j];
            j-=lowbit(j);
        }
        i-=lowbit(i);
    }
    return s;
}

int main()
{
    int ce;
    cin>>ce;
    for (int ci = 1; ci <= ce; ci++) {
        int N, M;
        cin>>M>>N;
        cerr<<ci<<" begin "<<M<<' '<<N<<endl;
        n = max(M, N) + 10;
        int B = 0;
        REP(i, M) {
            cin>>mp[i];
            REP(j, N / 4)
                mp[i][j] = mp[i][j] >= 'A' ? mp[i][j] - 'A' + 10 : mp[i][j] - '0';
            REP(j, N) {
                g[i][j] = (mp[i][j / 4] & (1<<(3 - j % 4))) != 0;
            } 
            for (int j = N - 1; j >= 0; j--) {
                next[i][j] = 1;
                if (j != N - 1)
                    if (g[i][j] != g[i][j + 1])
                        next[i][j] = next[i][j + 1] + 1;
                B >?= next[i][j];
                //cout<<next[i][j]<<' ';
            }//cout<<endl;
        }
        memset(c, 0, sizeof c);
        res.clear();
        for (;B >= 1; B--) {
            //cerr<<B<<'y';
            REP(i, M) 
                REP(j, N) 
                    if ((next[i][j] >= B) && (i + B - 1 < M) && (j + B - 1 < N)) {
                        int suc = Query(i + B - 1, j + B - 1);
                        suc -= Query(i- 1, j + B - 1);
                        suc -= Query(i + B - 1, j - 1);
                        suc += Query(i - 1, j - 1);
                        if (!suc) {
                            //cerr<<'z'<<i<<j<<endl;
                            suc = 1;
                            REP(k, B - 1)
                                if ((next[i + k + 1][j] < B) || (g[i + k][j] == g[i + k + 1][j])) {
                                    suc = 0;
                                    break;
                            }
                            if (!suc) continue;
                            //cerr<<'w'<<i<<j<<endl;
                            res[-B]++;
                            //cout<<B<<' '<<i<<' '<<j<<endl;
                            REP(t1, B)
                                REP(t2, B) 
                                    Update(i + t1, j + t2, 1);
                        }
                    }
        }
        printf("Case #%d: %d\n", ci, res.size());
        for (map<int, int>::iterator it = res.begin(); it != res.end(); it++) {
            printf("%d %d\n", -it->first, it->second);
        }
        cerr<<ci<<" end"<<endl;
    }
    return 0;
}
