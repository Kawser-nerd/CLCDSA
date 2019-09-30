#include <stdio.h>
int play(int a, int b) {
	int temp;
	if(a>b) {
		temp = a;
		a = b;
		b = temp;
	}
	if(a<=0 || b/a > 1) return 1;
	return !(play(b-a, a));

}
int main() {
	int t, T;
	int i, j, ki;
	int a[2], b[2];
	int ans;
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d %d %d", &a[0], &a[1], &b[0], &b[1]);
		ans =0;
		for(i=a[0];i<=a[1];i++)
			for(j=b[0];j<=b[1];j++) {
				ans += play(i, j);	
			}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
