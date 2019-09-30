#include <stdio.h>
#include <math.h>

#define DIST(x, y) sqrt( (x)*(x) + (y)*(y) )
#define MAX(x, y) ( (x) > (y) ) ? (x) : (y) 
#define MIN(x, y) ( (x) < (y) ) ? (x) : (y)

void a1() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", c);
}

void a2() {
	int a, b, c, d;
	scanf("%d%d%d", &a, &b, &c);
	scanf("%d%d%d", &a, &b, &d);
	printf("%d\n", MAX(c, d));
}

void a3() {
	int a[3][3], i;
	float c1, c2, c3;
	
	for (i=0; i<3; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);  
	}
	
	c1 = MAX(a[2][2], (float)(DIST(a[0][0]-a[1][0], a[0][1]-a[1][1]) + a[0][2] + a[1][2]) / 2);
	c2 = MAX(a[1][2], (float)(DIST(a[0][0]-a[2][0], a[0][1]-a[2][1]) + a[0][2] + a[2][2]) / 2);
	c3 = MAX(a[0][2], (float)(DIST(a[1][0]-a[2][0], a[1][1]-a[2][1]) + a[1][2] + a[2][2]) / 2);
	
	printf("%f\n", MIN(MIN(c1, c2), c3)); 
}

void single_case() {
	int i;
	scanf("%d", &i);
	
	switch (i) {
		case 1: a1(); break;
		case 2: a2(); break;
		case 3: a3(); break;
	}
}

int main() {
	int i, t;
	
	scanf("%d", &t);
	
	for (i=1; i<=t; i++) {
		printf("Case #%d: ", i);
		single_case();
	}
	
	return 0;
}
