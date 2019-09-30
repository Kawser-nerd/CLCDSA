#include <stdio.h>
int n,c,C,i;
int ugl[210];
int ugly(int x) { return ugl[(x<0?-x:x)%210]; };
char t[200];
int ugl1[48][48];
int main() {
	for(i=0;i<210;i++) {
		if(!(i%2) || !(i%3) || !(i%5) || !(i%7)) ugl[i] = 1;
	}
//	printf("%d %d %d %d %d\n",ugly(13),ugly(14),ugly(0),ugly(-14),ugly(121));
	scanf("%d",&C);
	for(c=1;c<=C;c++) {
		int i,j,max = 1,res = 0;
		scanf("%s",t);
		n = strlen(t);
		for(i=0;i<n;i++) {
			long long k = 0;
			if(i) max *= 3;
			for(j=i;j<n;j++) {
				k = k * 10 + t[j] - '0';
//				printf("%d - %d: %lld\n",i,j,k);
				ugl1[i][j] = k%210;
			}
		}
//		printf("max: %d\n",max);
		for(i=0;i<max;i++) {
			int v = i, sum = 0, last = n - 1;
			for(j=1;j<n;j++,v/=3) switch(v%3) {
			case 1: sum = sum + ugl1[n-j][last]; sum %= 210; last = n - j - 1; break;
			case 2: sum = sum + 210 - ugl1[n-j][last]; sum %= 210; last = n - j - 1; break;
			}
			sum = sum + ugl1[0][last]; sum %= 210;
			res += ugl[sum];
		}
		printf("Case #%d: %d\n",c,res);
//		break;
	}
	return 0;
}
