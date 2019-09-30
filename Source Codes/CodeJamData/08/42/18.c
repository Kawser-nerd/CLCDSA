#include <stdio.h>
#include <stdlib.h>
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
int main() {
char c;
int n,N,M,A,found,x1,y1,x2,y2,x3,y3,i;
	c = (char)fgetc(stdin);
	n = readint(&c);
	readend(&c,'\n');
	for (i = 1; i <= n; i++) {
		N = readint(&c);
		readend(&c,' ');
		M = readint(&c);
		readend(&c,' ');
		A = readint(&c);
		readend(&c,'\n');
		found = 0;
		x1 = 0;
		y1 = 0;
		for (x2 = 0; x2 <= N && !found; x2++) {
			for (y2 = 0; y2 <= M && !found; y2++) {
				for (x3 = 0; x3 <= N && !found; x3++) {
					for (y3 = 0; y3 <= M && !found; y3++) {
						if (abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) == A) {
							found = 1;
							fprintf(stdout,"Case #%i: %i %i %i %i %i %i\n",i,x1,y1,x2,y2,x3,y3);
						}
					}
				}
			}
		}
		if (!found) {
			fprintf(stdout,"Case #%i: IMPOSSIBLE\n",i);
		}
		fflush(stdout);
	}
	return 0;
}
