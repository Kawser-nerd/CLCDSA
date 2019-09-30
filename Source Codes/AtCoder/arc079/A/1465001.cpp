#include <iostream>
using namespace std;

const int MAXN=200100;
bool node1[MAXN],node2[MAXN];
int main() {
	memset(node1,0,sizeof(node1));
	memset(node2,0,sizeof(node2));
	int n,m; cin>>n>>m;
	for (int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		if (a==1)
			node1[b]=1;
		if (b==1)
			node1[a]=1;
		if (a==n)
			node2[b]=1;
		if (b==n)
			node2[a]=1;
	}
	for (int i=2;i<n;i++)
		if (node1[i] && node2[i]) {
			cout<<"POSSIBLE"<<endl;
			return 0;
		}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}