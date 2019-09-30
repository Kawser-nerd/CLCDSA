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

int N, x[2000];
int h[2000];

bool dfs(int start, int stop){
    if(start==stop)
        return true;
    int n=x[start];
    if(n>stop)
        return false;
    h[start]=h[n]=h[stop]=500000000;
    if(!dfs(start+1, n) || !dfs(n, stop))
        return false;
    for(;;)
    {
        bool good=true;
        for(int i=start+1; i<n; i++)
            if(h[i]>=500000000)
                good=false;
        if(!good)
        {
            for(int i=start+1; i<n; i++)
                h[i]-=(n-i);
        }else
            break;
    }
    return true;
}

void eval(){
    cin>>N;
    for(int i=0; i<N-1; i++){
        cin>>x[i];
        x[i]--;
    }
    if(!dfs(0, N-1)){
        cout<<"Impossible"<<endl;
        return;
    }
    for(int i=0; i<N; i++)
        cout<<h[i]<<" ";
    cout<<endl;
    for(int i=0; i<N; i++)
        assert(0<=h[i] && h[i]<=1000000000);
    for(int i=0; i<N-1; i++){
        int hi=N-1;
        for(int j=N-2; j>i; j--){
            if((long long)(h[j]-h[i])*(hi-i) >= (long long)(h[hi]-h[i])*(j-i))
                hi=j;
        }
        assert(hi==x[i]);
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
