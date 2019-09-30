#include<stdio.h>
int add(int x, int y) {
	return x + y;
}
int jian(int x, int y) {
	return x - y;
}
int main() {
	int a[10], i, j, k;
	char sign[2] = { '+','-' };
	int(*p[2])(int, int) = { add,jian };
	for (i = 0; i < 4; i++) scanf("%1d", a + i);
    int sum=a[0];
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				sum = p[k](p[j](p[i](sum,a[1]),a[2]),a[3]);
				if (sum == 7) goto label;
				else sum = a[0];
			}
		}
	}
label:
	printf("%d%c%d%c%d%c%d=7", a[0], sign[i], a[1], sign[j], a[2], sign[k], a[3]);
    
}