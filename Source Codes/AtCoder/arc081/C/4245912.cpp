#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=2e5+10;
int dp[L];
char bs[L];
int nx[L];
int last[128];
char A[L];
int main() {
	scanf("%s",A);
	int n=strlen(A);
	for(int i='a';i<='z';i++){
		last[i]=n;
	}
	dp[n]=1;
	bs[n]='a';
	nx[n]=n+1;
	for(int i=n-1;i>=0;i--){
		last[(int)A[i]]=i;
		dp[i]=L;
		for(int j='a';j<='z';j++){
			int w;
			w=1+dp[last[j]+1];
			if(w<dp[i]){
				dp[i]=w;
				bs[i]=j;
				nx[i]=last[j]+1;
			}
		}
	}
	int p=0;
	while(p<=n){
		printf("%c",bs[p]);
		p=nx[p];
	}
	puts("");

	return 0;
}