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
	char *h,*t,*p,*q;
	int *z;
	z = calloc(sizeof(int),strlen(s));
	for(h = s + 1,t = s;*h;){
		for(p=h+(t-s);*p && *p == *t;p++,t++);
		z[h-s] = t-s;
		if(t == s){h++;continue;}
		for(h++,q=s+1;*h && q + z[q-s] < t;q++,h++) z[h-s] = z[q-s];
		t -= q-s;
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
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^