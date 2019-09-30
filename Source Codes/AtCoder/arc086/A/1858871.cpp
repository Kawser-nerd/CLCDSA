#include <iostream>
using namespace std;

int cnt[200005];
int main() {
	memset(cnt,0,sizeof(cnt));
	int n,k;
	cin>>n>>k;
	for (int i=0,tmp; i<n; i++) {
		cin>>tmp;
		cnt[tmp]++;
	}
	sort(cnt,cnt+n+1);
	int typeCnt=0, ans=0;
	for (int i=1; i<=n; i++)
		if (cnt[i])
			typeCnt++;//,cout<<"("<<i<<")="<<cnt[i]<<endl;
	for (int i=1; i<=typeCnt-k; i++)
		ans += cnt[ n-typeCnt+i];
	cout<<ans<<endl;
	return 0;
}