#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ctime>
#define N 55
using namespace std;

int TC,n,m,cnt;
char s[N][N];

int main(){
	scanf("%d",&TC);
	for (int C=1;C<=TC;C++){
		scanf("%d%d",&n,&m);
		
		for (int i=0;i<n;i++)
			scanf("%s",s[i]);
			
		for (int i=0;i<n-1;i++)
			for (int j=0;j<m-1;j++){
				if (s[i][j]=='#' && s[i+1][j]=='#' && s[i][j+1]=='#' && s[i+1][j+1]=='#'){
					s[i][j] = s[i+1][j+1] = '/';
					s[i+1][j] = s[i][j+1] = 92;
				}
			}
			
		cnt = 0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (s[i][j]=='#') cnt++;
		
		printf("Case #%d:\n",C);
		if (!cnt){
			for (int i=0;i<n;i++)
				printf("%s\n",s[i]);
		}
		else printf("Impossible\n");
			
	}
	//scanf("\n");
	return 0;
}
