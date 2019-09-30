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

int x[1000], y[1000], R[1000];

void dfs(int x1, int y1, int W, int H, multiset<pair<int, int> > &c)
{
    int m=min(W, H);
    assert(m>=0);
    multiset<pair<int, int> >::iterator it=c.lower_bound(make_pair(-m, 1000));
    if(it!=c.end())
    {
        int d=-it->first, i=it->second;
        int r=d/2;
        c.erase(it);
        x[i]=x1+r;
        y[i]=y1+r;
        dfs(x1+d, y1+d, W-d, H-d, c);
        dfs(x1+d, y1, W-d, d, c);
        dfs(x1, y1+d, d, H-d, c);
    }
}

void eval(){
    int W,H,N;
    cin>>N>>W>>H;
    int WW=W, HH=H;
    multiset<pair<int, int> > c;
    for(int i=0; i<N; i++){
        int r;
        cin>>r;
        R[i]=r;
        if(2*r>W || 2*r>H){
            if(2*r>H){
                x[i]=W-r;
                W-=2*r;
                y[i]=0;
            }else{
                y[i]=H-r;
                H-=2*r;
                x[i]=0;
            }
        }else
            c.insert(make_pair(-2*r, i));
    }
    dfs(0, 0, W, H, c);
    assert(c.empty());
    for(int i=0; i<N; i++)
        cout<<x[i]<<" "<<y[i]<<" ";
    cout<<endl;
    for(int i=0; i<N; i++){
        assert(0<=x[i] && x[i]<=WW);
        assert(0<=y[i] && y[i]<=HH);
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<i; j++){
            int dx=x[i]-x[j];
            int dy=y[i]-y[j];
            assert(hypot(dx, dy)>=R[i]+R[j]-.00001);
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
