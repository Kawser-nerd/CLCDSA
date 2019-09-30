#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
vector<int> e[111111];
long long int A[111111];
bool dfs(int x,int fat){
	if(e[x].size() == 1){
		return true;
	}
	long long int sum = 0, mx = 0;
	for(vector<int>::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = *it;
		if(y == fat)continue;
		if(!dfs(y, x))
			return false;
		sum += A[y];
		mx = max(mx, A[y]);
	}
	mx = min(sum - mx, sum/2);

	long long int dec = sum - A[x];
	if(dec < 0 || dec > mx)
		return false;
	A[x] -= dec;
	if(x == fat)return A[x] == 0;
//	A[fat] -= dec;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		A[i] = x;
	}
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if(n == 2){
		puts(A[1] == A[2] ? "YES" : "NO");
		return 0;
	}
	int r = -1;
	for(int i=1; i<=n; i++)
		if(e[i].size() != 1){
			r = i;
			break;
		}
	puts(dfs(r,r) ? "YES" : "NO");
	return 0;
}