#include <stdarg.h>
#include <stdio.h>

int go(int x);

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		int x;
		scanf("%d",&x);
		printf("Case #%d: ", i);
		if(x == 0) {
			printf("INSOMNIA\n");
		} else {
			printf("%d\n", go(x));
		}
	}
	return 0;
}

int go(int x) {
	int todo = 0x3FF;
	int ans = 0;
	while(todo != 0) {
		ans += x;
		for(int temp = ans; temp != 0; temp = temp/10){
			todo &= ~(1 << (temp%10));
		}
	}
	return ans;
}
