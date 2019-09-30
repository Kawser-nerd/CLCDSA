#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t1, t2;
int a[100][100];
int match1[10000], match2[10000];
char map[100][100];
char g[6500][6500];

int d[4][2] = {{-1,-1},{-1,1},{0,-1},{0,1}};

int match(int n,int m)
{
	int s[6500], t[6500];
	int p, q, i, j, k, ret=0;
	memset(match1,0xff,sizeof(match1));
	memset(match2,0xff,sizeof(match2));
	for (i = 0; i < n; ret += (match1[i]>=0), i++){
		memset(t,0xff,sizeof(t));
		s[p=q=0]=i;
		for(;p<=q&&match1[i]<0;p++)
			for(k=s[p],j=0;j<m&&match1[i]<0;j++)
				if (g[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for(p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	}
	return ret;
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int z, i, j, k, tx, ty;
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z+1);
		scanf("%d%d",&n,&m);
		for (i = 0; i < n; i++) {
			scanf("%s",map[i]);
		}
		t1 = t2 = 0;
		memset(a, 0xff, sizeof(a));
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (map[i][j] == '.') {
					if (j % 2) {
						a[i][j] = t1++;
					}
					else {
						a[i][j] = t2++;
					}
				}
			}
		}
		memset(g,0,sizeof(g));
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (map[i][j] == '.') {
					for (k = 0; k < 4; k++) {
						tx = i + d[k][0];
						ty = j + d[k][1];
						if (tx < 0 || ty < 0 || tx >= n || ty >= m || a[tx][ty] < 0) continue;
						if (j % 2) {
							g[a[i][j]][a[tx][ty]] = 1;
						}
						else {
							g[a[tx][ty]][a[i][j]] = 1;
						}
					}
				}
			}
		}
		printf("%d\n", t1 + t2 - match(t1, t2));
	}
	return 0;
}
