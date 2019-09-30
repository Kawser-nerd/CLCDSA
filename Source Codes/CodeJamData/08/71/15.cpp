#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cctype>
#include <iostream>
using namespace std;

struct CMP_STRING {
	bool operator()(const char* a, const char* b) const {
		return strcmp(a,b)<0;
	}
};

#define two(n) (1<<(n))
#define foreach(a,it) for(typeof(a.begin()) it=a.begin();it!=a.end();++it)

int TT,N,M;

map<string,int> mapa;

int grafo[1000][1000];
int ng;

int voodoo(int p) {
	int ans=0;
	vector<int> v;
	for(int i=0;i<ng;i++)
		if(grafo[p][i])
			v.push_back(voodoo(i));
	if(v.size()==0)
		return 1;
	sort(v.begin(),v.end(),greater<int>());
	ans=v[0];
	for(int i=1;i<(int)(v.size());i++)
		if(ans-i<v[i])
			ans++;
	if(ans<=(int)v.size())
		ans++;
	return ans;
}

int main(void) {
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++) {
		memset(grafo,0,sizeof(grafo));
		printf("Case #%d: ",T);
		scanf("%d",&N);
		ng=0;
		mapa.clear();

		for(int i=0;i<N;i++) {
			string aux;
			cin >> aux;
			if(mapa.find(aux)==mapa.end())
				mapa[aux]=ng++;
			int naux=mapa[aux];

			scanf("%d",&M);
			for(int j=0;j<M;j++) {
				string aux2;
				cin >> aux2;
				if(isupper(aux2[0])) {
					if(mapa.find(aux2)==mapa.end())
						mapa[aux2]=ng++;
					int naux2=mapa[aux2];
					grafo[naux][naux2]=1;
				}
			}
		}
		printf("%d\n",voodoo(0));
	}
	return 0;
}
