#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int par[60];
int unifind(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}
}
//???????
int unifind_root(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = unifind_root(par[x]);
	}
}
//?????????
bool unifind_same(int x, int y) {
	return unifind_root(x) == unifind_root(y);
}
//??????
int unifind_unite(int x, int y) {
	x = unifind_root(x);
	y = unifind_root(y);
	if (x == y) {
		return 0;
	}
	par[x] = y;
}

main() {
	int n,m;
	int result = 0;
	int s[100][2];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &s[i][0], &s[i][1]);
      s[i][0]--;
      s[i][1]--;
	}
	unifind(n);
	for (int i = 0; i < m; i++) {


		for (int j = 0; j < m; j++) {
			if (j != i) {
				unifind_unite(s[j][0], s[j][1]);
			}
			
		}


		for (int j = 1; j < n; j++) {
			if (unifind_same(0 , j)) {
              
              if(j==n-1){result++; break;}
				continue;
			}
			break;
         
		}
		unifind(n);

	}
	printf("%d", m-result);
} ./Main.c:35:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main() {
 ^
./Main.c: In function ‘main’:
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &m);
  ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &s[i][0], &s[i][1]);
   ^