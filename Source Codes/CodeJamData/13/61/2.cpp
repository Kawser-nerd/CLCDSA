#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

#define debug(x) cerr<<#x<<" = "<<(x)<<endl

typedef long long ll;
ll N, X, s[1000], e[1000], t[1000], l[1000];
int C;

ll tryenter(ll startpoint)
{
	ll res=0;
	vector<ll> collides;
	for(int i=0; i<C; i++)
	{
		ll pt=startpoint%N;
		ll ss=s[i], tt=t[i];
		ll cs=(ss+tt)%N;
		if(cs>pt)
			pt+=N;
		for(int j=0; j<3; j++)
		{
			ll coll=(pt-cs+j*N);
			if(coll<=2*l[i]){
				collides.push_back(coll+2*t[i]);
			}
		}
	}
	collides.push_back(2*(X+1));
	sort(collides.begin(), collides.end());
	ll starttime=0;
	for(int i=0; i<collides.size(); i++){
		ll stop=collides[i];
		if(stop&1){
			res=max(res, (stop-1-starttime)/2);
			starttime=stop+1;
		}else{
			res=max(res, (stop-2-starttime)/2);
			starttime=stop+2;
		}
	}
	return res;
}

int main()
{
	int _T;
	string line;
	getline(cin, line);
	istringstream(line)>>_T;
	for(int _t=1; _t<=_T; _t++)
	{
		scanf("%d%lld%lld", &C, &X, &N);
		for(int i=0; i<C; i++){
			scanf("%lld%lld%lld", s+i, e+i, t+i);
			s[i]--;
			e[i]--;
			l[i]=(e[i]-s[i]+N)%N;
			assert(l[i]>0);
		}
		ll res=tryenter(0);
		
		for(int c=0; c<C; c++)
		{
			res=max(res, tryenter(l[c]+t[c] + (e[c]+1)));
			res=max(res, tryenter(l[c]+t[c]-1 + e[c]));
			res=max(res, tryenter(t[c] + (s[c]+N-1)));
			res=max(res, tryenter(t[c]+1 + s[c]));
		}
		printf("Case #%d: %lld\n", _t, res);
	}
}
