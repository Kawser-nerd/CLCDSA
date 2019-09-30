#include <stdio.h>
#include <stdlib.h>
#include <math.h>

short p[100];
short pNum;

void makePrimeList(short n);

int main(void)
{
	char n,i,j,k,tmp;
	short b[100]={};
	int ans=0;
	scanf("%hhd",&n);

	makePrimeList(n);
	
	for (i=2;i<=n;i++) {
		for (j=0;j<pNum;j++) {
			if (i < p[j]) break;
			
			tmp = i;
			while (tmp > 1) {
				if (tmp % p[j] != 0) break;
				tmp = tmp / p[j];
				b[j]++;
			}
		}
	}

	// a^2 b^4 c^4
	for (i=0;i<pNum;i++) {
		if (b[i]>=4) {
			for (j=i+1;j<pNum;j++) {
				if (b[j]>=4) {
					for (k=0;k<pNum;k++) {
						if (b[k]>=2 && i!=k && j!=k) ans += 1;
					}
				}
			}
		}
	}

	// a^2 b^24
	for (i=0;i<pNum;i++) {
		if (b[i]>=24) {
			for (j=0;j<pNum;j++) {
				if (b[j]>=2 && i!=j) ans += 1;
			}
		}
	}

	// a^4 b^14
	for (i=0;i<pNum;i++) {
		if (b[i]>=14) {
			for (j=0;j<pNum;j++) {
				if (b[j]>=4 && i!=j) ans += 1;
			}
		}
	}

	// a^74
	for (i=0;i<pNum;i++) {
		if (b[i]>=74) ans += 1;
	}

	printf("%d\n",ans);
	return 0;
}

void makePrimeList(short n)
{
	short i,j,*tmpP;
	tmpP = (short *)malloc(sizeof(short) * n);
	tmpP[0] = 1;
	for (i=1;i<n;i++) tmpP[i] = 0;

	pNum = 0;
	for (i=2;i<=sqrt(n);i++) {
		if (tmpP[i-1]==1) continue;
		
		p[pNum] = i;
		pNum++;
		for (j=i;j<=n;j+=i) {
			tmpP[j-1] = 1;
		}
	}

	for (i=(int)sqrt(n);i<=n;i++) {
		if (tmpP[i-1]==1) continue;

		p[pNum] = i;
		pNum++;
	}

	return;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hhd",&n);
  ^