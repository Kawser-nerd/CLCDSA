#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char *D,*C;
static int L;
static long long U;
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
char *readstring(char *c) {
char *r;
int i;
	r = (char *)malloc(sizeof(char));
	i = 0;
	for (; (*c >= '0' && *c <= '9'); *c = (char)fgetc(stdin)) {
		r[i] = *c;
		i++;
		r = (char *)realloc(r,sizeof(char)*(i+1));
	}
	r[i] = '\0';
	return r;
}
void readend(char *c,char e) {
	for (; *c != e; *c = (char)fgetc(stdin));
	*c = (char)fgetc(stdin);
}
void compute(i,j) {
char o;
int k;
long long e,r;
	if (i < L) {
		C[j] = D[i];
		compute(i+1,j+1);
		if (i > 0) {
			C[j] = '+';
			C[j+1] = D[i];
			compute(i+1,j+2);
			C[j] = '-';
			C[j+1] = D[i];
			compute(i+1,j+2);
		}
	}
	else {
		C[j] = D[i];
		C[j+1] = '\0';
		e = 0;
		r = 0;
		o = '+';
		for (k = 0; k < strlen(C); k++) {
			if (C[k] >= '0' && C[k] <= '9') {
				r = r > 0 ? 10*r+(C[k]-'0'):C[k]-'0';
			}
			else if (C[k] == '+' || C[k] == '-') {
				if (o == '+') {
					e += r;
				}
				else if (o == '-') {
					e -= r;
				}
				r = 0;
				o = C[k];
			}
		}
		if (o == '+') {
			e += r;
		}
		else if (o == '-') {
			e -= r;
		}
		if (e%2 == 0 || e%3 == 0 || e%5 == 0 || e%7 == 0) {
			U++;
		}
	}
}
int main() {
char c;
int n,i;
	c = (char)fgetc(stdin);
	n = readint(&c);
	readend(&c,'\n');
	for (i = 1; i <= n; i++) {
		D = readstring(&c);
		L = strlen(D);
		C = (char *)malloc(sizeof(char)*(L*2+1));
		readend(&c,'\n');
		U = 0;
		compute(0,0);
		fprintf(stdout,"Case #%i: %llu\n",i,U);
		fflush(stdout);
		free(C);
		free(D);
	}
	return 0;
}
