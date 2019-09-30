#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 1000005;
bool prime[maxn];

long long n,ans;
int main()
{
	for(int i = 2;i<maxn;i++ ) prime[i] = true;
	for( int i = 2;i<maxn;i++ ) if( prime[i] )
	for( int j = i+i;j<maxn;j+=i ) prime[j] = false;

	int TT,T=0;
	for( cin>>TT;TT;TT-- )
	{
		cout << "Case #"<<++T<<": ";
		cin>>n;ans = 0;
		for( long long i = 2;i*i<=n;i++ ) if( prime[i] )
			for( long long j = i*i;j<=n;j*=i ) ans++;

		cout << ans + (n>1) << endl;
	}
	return 0;
}
