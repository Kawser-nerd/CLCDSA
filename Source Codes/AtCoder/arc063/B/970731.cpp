#include <cstdio>

const int MAXN = 1E5 + 10;

int n, T;
int a[MAXN];

int main(){
	scanf("%d%d", &n, &T);
	scanf("%d", &a[0]);
	int val = a[0], diff = 0, cnt = 0;
	for (int i = 1; i < n; ++i){
		scanf("%d", &a[i]);
		if (diff < a[i] - val)
			diff = a[i] - val, cnt = 1;
		else if (diff == a[i] - val)
			++cnt;
		if (a[i] < val)
			val = a[i];
	}
	printf("%d\n", cnt);
	return 0;
}