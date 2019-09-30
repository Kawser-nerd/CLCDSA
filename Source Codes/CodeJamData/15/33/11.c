#include <stdio.h>
int num[1000], map[1000], d;
void check(int cur, int i) {
	int j;
	num[cur+map[i]] = 1;
	for(j=i+1;j<d;++j)
		check(cur+map[i], j);
}
int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0-output.txt", "w", stdout);
	int t, c, v, out, i, j, x;
	scanf("%d", &t);
	for(x=1;x<=t;++x) {
		scanf("%d %d %d", &c, &d, &v);
		for(i=0;i<d;++i)
			scanf("%d", &map[i]);
		for(i=1;i<=v;++i)
			num[i] = 0;
		for(i=0;i<d;++i)
			check(0,i);
		out = 0;
		for(i=1;i<=v;++i) {
			if(num[i] == 0) {
				++out;
				map[d++] = i;
				for(j=0;j<d;++j)
					check(0, j);
			}
		}
		printf("Case #%d: %d\n", x, out);
	}
	return 0;
}
