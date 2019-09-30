#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdio>
using namespace std;

class union_find{
	vector<int> parent;
public:
	vector<int> siz;
	int root(int a){return parent[a]==a?a:(siz[a]=siz[parent[a]],parent[a]=root(parent[a]));}
	union_find(int n):parent(n),siz(n){for(int i=0;i<n;i++)parent[i]=i,siz[i]=1;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);if(x==y)return 0;
		parent[x]=y;
		siz[y]+=siz[x];
		return 1;
	}
};

int main(){
	int N,M,x,y,z;
	scanf("%d%d",&N,&M);
	vector<tuple<int,int,int,int>>v;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&x,&y,&z);
		v.push_back(make_tuple(-z,1,x-1,y-1));
	}
	scanf("%d",&M);
	vector<int>r(M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&x,&z);
		v.push_back(make_tuple(-z,0,x-1,i));
	}
	sort(v.begin(),v.end());
	union_find uf(N);
	for(auto &e:v){
		if(get<1>(e)==0){
			r[get<3>(e)]=uf.siz[uf.root(get<2>(e))];
		}else{
			uf.unite(get<2>(e),get<3>(e));
		}
	}
	for(auto &e:r)printf("%d\n",e);
}