#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

struct Node{
	long long sohr, png;
	int du;
	
	Node(){}
	Node(long long sohr,long long png,int du):sohr(sohr),png(png),du(du){}
	
	bool operator<(Node n)const{
		long long z1=sohr-png;
		long long z2=n.sohr-n.png;
		if(z1==z2) return du<n.du;
		else return z1<z2;	
	}	
};

long long L;
int n;
int a[101];
long long F[100010];
set<Node>::iterator G[100010];
bool ins[100010];

int main() {
	int st;
	scanf("%d",&st);
	Rep(test,st){
		cerr<<"test="<<test+1<<endl;
		cin>>L>>n;
		Rep(i,n)cin>>a[i];
		
		sort(a,a+n);
		long long result=-1;
		{
			int P = a[n-1];
			set<Node> se;
			memset(F,0x1f,sizeof(F));
			long long inf=F[0];
			se.insert(Node(0,0,0));
			G[0]=se.begin();
			F[0]=0;
			memset(ins,0,sizeof(ins));
			ins[0]=true;
			while(se.size()>0){
				Node z=*se.begin();
				se.erase(se.begin());
				ins[z.du]=false;
				
				for(int i=0;i<n;++i){
					Node t(z.sohr+1,(z.png*P+z.du+a[i])/P,(z.du+a[i])%P);
					if(F[t.du] > t.sohr-t.png){
						F[t.du] = t.sohr-t.png;
						if(ins[t.du]){
							ins[t.du]=false;
							se.erase(G[t.du]);
						}
						se.insert(t);
						G[t.du]=se.find(t);
					}
				}
			}
			if(F[L%P] < inf){
				result = F[L%P]+L/P;
			}
		}
		
		cout<<"Case #"<<test+1<<": ";
		if(result==-1)cout<<"IMPOSSIBLE"<<endl;
		else cout<<result<<endl;
	}	
	return 0;	
}
