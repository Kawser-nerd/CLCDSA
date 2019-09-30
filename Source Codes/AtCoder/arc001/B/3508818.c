#include<stdio.h>

int min(int a, int b) {
	if (a >= b) { return b; }
	else { return a; }
}
int max(int a, int b) {
	if (a <= b) { return b; }
	else { return a; }
}
int main() {
	int a,b;
	int change;
	int turn = 0;
	scanf("%d%d",&a,&b);
	if (a >= b) {
		change = a - b;
	}
	else {
		change = b - a;
	}
	if (change == 0) {
		printf("0\n");
		return 0;
	}
	while (change != 0) {
		if (change >= 10) {
			change -= 10;
			turn++;
		}
		else if (change == 9) {
			turn += 2;
			break;
		}
		else if (change == 8) {
			turn += 3;
			break;
		}
		else if (change == 7) {
			turn += 3;
			break;
		}
		else if (change == 6) {
			turn += 2;
			break;
		}
		else if (change == 5) {
			turn += 1;
			break;
		}
		else if (change == 4) {
			turn += 2;
			break;
		}
		else if (change == 3) {
			turn += 3;
			break;
		}
		else if (change == 2) {
			turn += 2;
			break;
		}
		else if (change == 1) {
			turn += 1;
			break;
		}
	}
	printf("%d\n", turn);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^