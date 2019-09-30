#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<pii,ll>pi3;
ll mod=1000002013;
int main()
{
	FILE *fr=fopen("a-large.in","r");
	FILE *fw=fopen("out0.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		ll cit,way;
		fscanf(fr,"%lld%lld",&cit,&way);
		vector<pi3>vec;
		ll ans=0;
		for(int i=0;i<way;i++)
		{
			ll za,zb,zc;
			fscanf(fr,"%lld%lld%lld",&za,&zb,&zc);
			ans+=(((2*cit+1-(zb-za))*(zb-za)/2)%mod)*zc;
			ans%=mod;
			vec.push_back(make_pair(make_pair(za,0),zc));
			vec.push_back(make_pair(make_pair(zb,1),zc));
		}
		ll ret=0;
		sort(vec.begin(),vec.end());
		stack<pii>st;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i].first.second==0)
			{
				st.push(make_pair(vec[i].first.first,vec[i].second));
			}
			else
			{
				ll now=vec[i].second;
				for(;;)
				{
					pii zan=st.top();
					if(zan.second<now)
					{
						ret+=(((2*cit+1-(vec[i].first.first-zan.first))*(vec[i].first.first-zan.first)/2)%mod)*zan.second;
						ret%=mod;
						now-=zan.second;
						st.pop();
					}
					else
					{
						ret+=(((2*cit+1-(vec[i].first.first-zan.first))*(vec[i].first.first-zan.first)/2)%mod)*now;
						ret%=mod;
						st.top().second-=now;
						break;
					}
				}
			}
		}
		fprintf(fw,"Case #%d: %lld\n",p+1,(ans+mod-ret)%mod);
	}
}
