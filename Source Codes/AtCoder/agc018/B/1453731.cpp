#include <iostream>
#include <set>
#include <cassert>
using namespace std;

const int MAXN=310;
struct Node {
	Node *before=NULL,*next=NULL;
	int key;
	Node(int v) {
		key = v;
	}
}*tail[MAXN];

set<Node*> position[MAXN];
void removeNode(Node *p) {
	if (p->before)
		p->before->next = p->next;
	if (p->next)
		p->next->before = p->before;
	delete p;
}
void pushback(int no,int val) {
	Node *p = new Node(val);
	p->before = tail[no];
	if (tail[no])
		tail[no]->next = p;
	tail[no] = p;
	position[val].insert(p);
}
int n,m;
void debug() {
	for (int i=0; i<n; i++,cout<<endl) {
		cout<<"tail "<<i<<" :";
		for (Node *p=tail[i]; p; p=p->before) {
			if (p->before)
				assert(p->before->next==p);
			cout<<p->key<<" - ";
		}
	}
	cout<<endl;
}
int main()
{
	memset(tail,0,sizeof(tail));
	cin>>n>>m;
	for (int i=0;i<n;i++) {
		int tmp[MAXN];
		for (int j=0;j<m;j++)
			cin>>tmp[j];
		for (int j=m-1;j>=0;j--)
			pushback(i,tmp[j]);
	}
	int ans=MAXN;
	for (int t=0,cnt[MAXN],anst=MAXN; t<m&&tail[0]; t++,anst=MAXN) {
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++)
			cnt[tail[i]->key]++;
		int mmax=0;
		set<int> maxsport;
		for (int i=1;i<=m;i++) {
			if (cnt[i] > mmax) {
				maxsport.clear();
				mmax = cnt[i];
			}
			if (cnt[i] == mmax)
				maxsport.insert(i);
		}
		if (ans > mmax)
			ans = mmax;
		for (int i=0;i<n;i++) {
			for (Node *p=tail[i]; p&&(maxsport.find(p->key)!=maxsport.end()); p=p->before)
				tail[i] = p->before;
		}
		for (auto it=maxsport.begin(); it!= maxsport.end(); it++) {
			for (auto p=position[*it].begin(); p!=position[*it].end(); p++ )
				removeNode(*p);
		}
	}
	cout<<ans<<endl;
}