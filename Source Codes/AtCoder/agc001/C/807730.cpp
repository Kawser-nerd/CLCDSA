#include <cstdio>
#include <vector>

using namespace std;

#define N_MAX 2000



int n,k;
vector<int> nx[N_MAX];


int dfs(int k, int s,int p){
	if(k == 0) return 1;
	k--;
	
	int c = 1;
	for(vector<int>::iterator it = nx[s].begin();it != nx[s].end();++it){
		if(*it != p) c += dfs(k, *it, s);
	}
	return c;
}
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0;i < n-1;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		a--; b--;
		nx[a].push_back(b);
		nx[b].push_back(a);
	}
	int m = 1;
	for(int i = 0;i < n;i++){
		m = max(m, dfs(k/2, i,-1));
	}
	for(int i = 0;i < n;i++){
		for(vector<int>::iterator it = nx[i].begin();it != nx[i].end();++it){
			int j = *it;
			int mm = dfs((k-1)/2,i,j)+dfs((k-1)/2,j,i);
			m = max(m, mm);
		}
	}
	printf("%d\n", n-m);
	return 0;
}