#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
int w[1001], C[1001][1001], O[1001];
bool v[1001];
struct A{
	int ord, R;
	bool operator <(const A &p)const{
		return R < p.R;
	}
}p[1000];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, TC, T, n, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < 3000000; i++){
		for (j = 0; j < 1000; j++){
			w[j] = j;
		}
		for (j = 0; j < 1000; j++){
			swap(w[j], w[rand() % 1000]);
		}
		for (j = 0; j < 1000; j++){
			C[j][w[j]]++;
		}
	}
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		scanf("%d", &n);
		p[T].ord = T;
		for (i = 0; i < n; i++){
			scanf("%d", &O[i]);
			p[T].R += C[i][O[i]];
		}
	}
	sort(p + 1, p + TC + 1);
	for (i = 1; i <= 60; i++)v[p[i].ord] = true;
	for (i = 1; i <= TC; i++){
		printf("Case #%d: ", i);
		if (v[i])printf("GOOD\n");
		else printf("BAD\n");
	}
}