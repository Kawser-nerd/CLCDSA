#include <stdio.h>
#include <math.h>
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large-output.txt", "w", stdout);
	int t, out, r, c, w, x;
	double add;
	scanf("%d", &t);
	for(x=1;x<=t;++x){
		scanf("%d %d %d", &r, &c, &w);
		add = ceil((c-w)/(double)w);
		out = w + (int)add;
		out += (r-1) * (c/w);
		printf("Case #%d: %d\n", x, out);
	}
	return 0;
}
