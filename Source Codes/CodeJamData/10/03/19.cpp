#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1010

int n,m,r;
int groups[MAXN];
int first[MAXN];
long long earn[MAXN];

int caseN;

int main()
{
	cin>>caseN;
	for (int caseI=1;caseI<=caseN;caseI++)
	{
		cin>>r>>m>>n;
		for (int i=0;i<n;i++)
			cin>>groups[i];
		int cnt=0;
		long long cur=0;
		int head=0;
		memset(first,-1,sizeof(first));
		while (first[head]<0)
		{
			first[head]=cnt;
			earn[cnt]=cur;
			int remain,i;
			remain=m-groups[head];
			cur+=groups[head];
			for (i=(head+1)%n;i!=head && remain>=groups[i];i=(i+1)%n)
			{
				remain-=groups[i];
				cur+=groups[i];
			}
			cnt++;
			head=i;
		}
		long long ans;
		if (r>first[head])
		{
			ans=earn[first[head]];
			r-=first[head];
			int L=cnt-first[head];
			ans+=(cur-earn[first[head]])*(r/L);
			ans+=earn[first[head]+(r%L)]-earn[first[head]];
		}
		else
			ans=earn[r];
		printf("Case #%d: %lld\n",caseI,ans);
	}
	return 0;
}




		
