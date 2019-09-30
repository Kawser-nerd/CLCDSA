#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Frequency {
	int L;
	int F;
};
static struct Frequency *F;
int readint(char *c) {
int r,s;
	r = 0;
	if (*c == '-') {
		*c = (char)fgetc(stdin);
		s = -1;
	}
	else {
		s = 1;
	}
	for (; *c >= '0' && *c <= '9'; *c = (char)fgetc(stdin)) {
		r = r > 0 ? 10*r+(*c-'0'):*c-'0';
	}
	return r*s;
}
void readend(char *c,char e) {
	for (; *c != e; *c = (char)fgetc(stdin));
	*c = (char)fgetc(stdin);
}
void swap(int i1,int i2) {
struct Frequency swap;
	memcpy(&swap,&F[i1],sizeof(struct Frequency));
	memcpy(&F[i1],&F[i2],sizeof(struct Frequency));
	memcpy(&F[i2],&swap,sizeof(struct Frequency));
}
void quicksort(int i1,int i2) {
int i3,i4,pivot;
	i3 = i1;
	i4 = i2;
	if (i2 > i1) {
		pivot = F[i1].F;
		while (i4 > i3) {
			for (; F[i3].F >= pivot && i3 <= i2 && i3 < i4; i3++);
			for (; F[i4].F < pivot && i4 >= i1 && i4 >= i3; i4--);
			if (i4 > i3) {
				swap(i3,i4);
			}
		}
		swap(i1,i4);
		quicksort(i1,i4-1);
		quicksort(i4+1,i2);
	}
}
int main() {
char c;
int n,P,K,L,i,j;
long long M;
	c = (char)fgetc(stdin);
	n = readint(&c);
	readend(&c,'\n');
	for (i = 1; i <= n; i++) {
		P = readint(&c);
		readend(&c,' ');
		K = readint(&c);
		readend(&c,' ');
		L = readint(&c);
		readend(&c,'\n');
		F = (struct Frequency *)malloc(sizeof(struct Frequency)*L);
		for (j = 0; j < L-1; j++) {
			F[j].L = j;
			F[j].F = readint(&c);
			readend(&c,' ');
		}
		F[j].L = j;
		F[j].F = readint(&c);
		readend(&c,'\n');
		quicksort(0,L-1);
		M = 0;
		for (j = 0; j < L; j++) {
			M += (long long)(F[j].F*((j/K)+1));
		}
		fprintf(stdout,"Case #%i: %lld\n",i,M);
		fflush(stdout);
		free(F);
	}
	return 0;
}
