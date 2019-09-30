#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
static inline unsigned long xabs(unsigned long a, unsigned long b) {
	return a > b ? a-b : b-a;
}
static inline unsigned long myatol(int *x, int len) {
	unsigned long ans = 0;
	for(int i = 0; i < len; i++)
		ans = ans*10+x[i];
	return ans;
}
char buf1[20], buf2[20];
int C[18], J[18];
int bC[18], bJ[18];
int oC[18], oJ[18];
int main() {
	int ca;
	scanf("%d", &ca);
	for(int p = 1; p <= ca; p++) {
		scanf("%s%s", buf1, buf2);
		for(int i = 0; buf1[i]; i++)
			if (buf1[i] == '?')
				C[i] = -1;
			else
				C[i] = buf1[i]-'0';
		for(int i = 0; buf2[i]; i++)
			if (buf2[i] == '?')
				J[i] = -1;
			else
				J[i] = buf2[i]-'0';
		int len = strlen(buf1), i;
		int *big, *small;
		char *bs, *ss;
		for(i = 0; i < len; i++) {
			if (C[i] == -1) {
				if (J[i] == -1)
					J[i] = 0;
				C[i] = J[i];
			} else if (J[i] == -1)
				J[i] = C[i];
			else {
				if (J[i] == C[i])
					continue;
				if (J[i] > C[i]) {
					big = J;
					small = C;
					bs=buf2;
					ss=buf1;
				} else {
					big = C;
					small = J;
					bs=buf1;
					ss=buf2;
				}
				break;
			}
		}
		int bp = i;
		i++;
		for(;i<len;i++) {
			if(big[i] == -1)
				big[i] = 0;
			if (small[i]==-1)
				small[i]=9;
		}

		unsigned long bestc, bestj, best = -1;
		unsigned long c = myatol(C,len), j = myatol(J,len);
		best = xabs(c,j);
		bestc=c;
		bestj=j;
		memcpy(bC, C, sizeof(C));
		memcpy(bJ, J, sizeof(J));
		memcpy(oC, C, sizeof(C));
		memcpy(oJ, J, sizeof(J));

		//Decrease big
		int k;
		for(k = bp-1;k>=0;k--) {
			if (bs[k] == '?' && big[k] != 0) {
				big[k]--;
				break;
			}
		}
		if (k >= 0){
		for(i=k+1;i<len;i++) {
			if(bs[i] == '?')
				big[i] = 9;
			if (ss[i]=='?')
				small[i]=0;
		}
		c = myatol(C,len), j = myatol(J,len);
		if ((xabs(c,j) < best) ||
		    ((xabs(c,j)==best) && c < bestc) ||
		    ((xabs(c,j)==best) && c == bestc && j < bestj)) {
			bestc=c;
			bestj=j;
			best=xabs(c,j);
		memcpy(bC, C, sizeof(C));
		memcpy(bJ, J, sizeof(J));
		}
		}

		memcpy(C, oC, sizeof(C));
		memcpy(J, oJ, sizeof(J));
		//Increase small
		for(k = bp-1;k>=0;k--) {
			if (ss[k] == '?' && small[k] != 9) {
				small[k]++;
				break;
			}
		}
		for(i=k+1;i<len;i++) {
			if(bs[i] == '?')
				big[i] = 9;
			if (ss[i]=='?')
				small[i]=0;
		}
		c = myatol(C,len), j = myatol(J,len);
		if ((xabs(c,j) < best) ||
		    ((xabs(c,j)==best) && c < bestc) ||
		    ((xabs(c,j)==best) && c == bestc && j < bestj)) {
			bestc=c;
			bestj=j;
			best=xabs(c,j);
		memcpy(bC, C, sizeof(C));
		memcpy(bJ, J, sizeof(J));
		}

		printf("Case #%d: ",p);
		for(i=0;i<len;i++)
			printf("%d",bC[i]);
		printf(" ");
		for(i=0;i<len;i++)
			printf("%d",bJ[i]);
		printf("\n");
	}
}
