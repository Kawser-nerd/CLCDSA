#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<"="<<(x)<<endl;

int R, C;
char grid[61][61];
long long mask[61];
set<long long> mem;

bool dfs(long long *cur, const long long *at)
{
    long long hash=0;
    int count=0;
    for(int i=0; i<R; i++)
    {
        hash^=cur[i];
        hash*=7777777;
        count+=__builtin_popcountll(cur[i]);
    }
    if(count==1)
        return true;
    if(mem.count(hash))
        return false;
    mem.insert(hash);

    long long next[61];
    {
        for(int i=0; i<R; i++)
            next[i]=0;
        for(int i=0; i<R-1; i++){
            next[i]|=cur[i]&~mask[i+1];
            next[i+1]|=cur[i]&mask[i+1];
        }
        bool good=true;
        for(int i=0; i<R; i++)
            if(next[i]&~at[i]){
                good=false;
                break;
            }
        if(good && dfs(next, at))
            return true;
    }
    {
        for(int i=0; i<R; i++)
            next[i]=0;
        for(int i=0; i<R; i++){
            next[i]|=(cur[i]<<1)&mask[i];
            next[i]|=cur[i]&(~mask[i]>>1);
        }
        if(dfs(next, at))
            return true;
    }
    {
        for(int i=0; i<R; i++)
            next[i]=0;
        for(int i=0; i<R; i++){
            next[i]|=(cur[i]>>1)&mask[i];
            next[i]|=cur[i]&(~mask[i]<<1);
        }
        if(dfs(next, at))
            return true;
    }
    return false;
}

void solve(const int X, const int Y)
{
    long long at[61]={0};
    at[Y]|=1ll<<X;
    assert(at[Y]&mask[Y]);
    for(int y=Y; y>0; y--)
    {
        for(int i=0; i<60; i++){
            at[y]=at[y]|(at[y]<<1)|(at[y]>>1);
            at[y]&=mask[y];
        }
        at[y-1]=at[y]&mask[y-1];
    }
    int count=0;
    for(int y=0; y<R; y++)
        count+=__builtin_popcountll(at[y]);
    cout<<count<<" ";

    long long cur[61];
    for(int i=0; i<61; i++)
        cur[i]=at[i];
    for(int i=0; i<60; i++){
        for(int y=0; y<=Y; y++){
            cur[y]=((cur[y]<<1)&mask[y])|((~mask[y]>>1)&cur[y]);
        }
    }
    mem.clear();
    cout<<(dfs(cur, at) ? "Lucky" : "Unlucky");

    cout<<endl;
}

void eval(){
    cin>>R>>C;
    for(int i=0; i<R; i++){
        cin>>grid[i];
        mask[i]=0;
        for(int j=0; j<C; j++)
            if(grid[i][j]!='#')
                mask[i]|=1ll<<j;
    }
    cout<<endl;
    for(int d=0; d<10; d++)
    {
        for(int y=0; y<R; y++)
            for(int x=0; x<C; x++)
                if(grid[y][x]==d+'0'){
                    cout<<d<<": ";
                    solve(x, y);
                }
    }
}

int main(){
	int cases;
	string line;
	getline(cin, line);
	istringstream(line)>>cases;
	for(int i=1; i<=cases; i++){
		cout<<"Case #"<<i<<": ";
		eval();
	}
	return 0;
}
