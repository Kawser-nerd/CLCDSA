#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN=2010;
int a[MAXN], n;
int Qorder[MAXN];
bool cmp(const int x, const int y) {
	return a[x]<a[y];
}
int slotspace[MAXN]; // query space = slotspace[slotid];
int belong[MAXN]; //belong[x] = slot_i; query x's slot id which x is using in a[x].
void updateslot(int threshould) {
	int slotid = 0;
	int space=0;
	for (int i=0; i<n; i++) {
		if (a[i] <= threshould) {
			slotspace[slotid] = space;
			space = 0;
			slotid++;
		}else {
			belong[i] = slotid;
			space++;
		}
	}
	slotspace[slotid] = space;
}
int main() {
	int K,Q;
	cin>>n>>K>>Q;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		Qorder[i]=i;
	}
	sort(Qorder, Qorder+n, cmp);

	int ans = 2000000000;
	for (int lastpos=-1, lastnum=0; lastpos+1<n; ) {
		updateslot(lastnum);
		int succ=0;
		for (int p=lastpos+1; p<n; p++) {
			int slotid = belong[Qorder[p]];
			if (slotspace[slotid] >= K)
				succ++, slotspace[slotid]--;
			if (succ == Q) {
				int X = a[Qorder[lastpos+1]];
				int Y = a[Qorder[p]];
				ans = min(ans, Y-X);
				break;
			}
		}
		if (succ != Q)
			break;
		//update var 'lastpos'
		lastnum = a[Qorder[++lastpos]];
		while (lastpos+1 < n) {
			if (a[Qorder[lastpos]] != a[Qorder[lastpos+1]])
				break;
			lastpos++;
		}
	}

	cout<<ans<<endl;
	return 0;
}