#include<iostream>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

set< pair<long long,long long> > hash;
map<long long,long long> last[100005];

int len[105];
long long L;
int n;
set< pair<long long,long long> >::iterator it;
map<long long,long long>::iterator mit;

inline bool check( long long a,long long b )
{
	long long t = a/len[n];
	mit = last[ a%len[n] ].upper_bound(t);
	if( mit==last[a%len[n]].begin() ) return true;
	mit--;
	return ( t - (mit->first) + mit->second > b );
}
inline void insert( long long a,long long b )
{
	if( check(a,b) )
	{
		hash.insert( make_pair(b,a) );
		last[ a%len[n] ].insert( make_pair( a/len[n],b ) );
	}
}
int main()
{
	int TT;
	cin>>TT;
	int T = 0;
	long long ans;
	long long na,nb;

	
	while(TT--)
	{
		
		cout<<"Case #"<<++T<<": ";
		cin>>L>>n;
		for(int i=1;i<=n;i++) cin>>len[i];
		sort(len+1,len+n+1);
		hash.clear();
		for(int i=0;i<len[n];i++) last[i].clear();
		
		//cout<<L<<" "<<n<<endl;
		ans = L+1;
		insert(0,0);
		while( !hash.empty() )
		{
			it = hash.begin();

			na = (*it).second;
			nb = (*it).first;
		//	cout<<na<<" "<<nb<<endl;
			hash.erase(it);


			if( na==L ) ans = min(ans,nb);else
			if( (L-na-1)/len[n] +1 <(ans-nb) )
			{
				if( (L-na)%len[n]==0 )
					ans = (L-na)/len[n] + nb;

				for(int i=1;i<=n;i++) if( na+len[i]<=L ) insert( na+len[i],nb+1 );
			}
		}

		if( ans>L ) cout<<"IMPOSSIBLE"<<endl;else
			cout<<ans<<endl;
	}
	return 0;
}
