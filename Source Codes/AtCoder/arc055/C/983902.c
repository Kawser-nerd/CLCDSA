#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))


void revcpy(char *s,char *r){
	*r = 0;
	r--;
	while(*s){
		*r = *s;
		s++;
		r--;
	}
}
int* z_algolithm(char *s){
	int *z;
	int l = strlen(s);
	z = calloc(sizeof(int),l);
	z[0] = l;
	int i = 1,j = 0;
	while (i < l) {
	while (i+j < l && s[j] == s[i+j]) ++j;
		z[i] = j;
		if (j == 0) { ++i; continue;}
		int k = 1;
		while (i+k < l && k+z[k] < j) z[i+k] = z[k], ++k;
		i += k; j -= k;
	}
	return z;
}

int main(void){
	char *s,*r;

	char m;
	lli res = 0;
	int l;
	int *a,*b;
	int h,t;
	s = calloc(sizeof(char),200001);
	scanf("%s",s);
	l = strlen(s);
	r = calloc(sizeof(char),l+1);
	a = calloc(sizeof(int),l);
	b = calloc(sizeof(int),l);
	revcpy(s,r+l);
	a = z_algolithm(s);
	b = z_algolithm(r);
	/*
	for(int i=0;i<l;i++){
		printf("%d %d\n", a[i],b[i]);
	}
	*/
	h = l / 2 + 1;
	t = (l - 1) / 2;
	//printf("%d %d\n", h,t);
	while(t > 0){
		if(a[h] >= t) a[h] = t-1;
		if(b[t] >= t) b[t] = t-1;
		res += max(0,a[h] + b[t] - t + 1);
		h++;t--;
	}

	printf("%lld\n", res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^