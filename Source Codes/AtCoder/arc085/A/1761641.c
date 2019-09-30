#include <stdio.h>
void solve(void)
{
	int n,m,x;
	scanf("%d %d", &n,&m);
	x = 1800*m + 100*n;
	while(m-->0) x *= 2;
	
	printf("%d\n", x);
}
int main(int argc, char **argv)
{
	solve();
	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n,&m);
  ^