#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

int gcd(int x, int y){
	if (x%y==0){
		return y;
	}else{
		return gcd(y,x%y);
	}
}

int divv(int x, int y){
	if (x%y==0)
		return x/y;
	else
		return x/y+1;
}

int main(int argc, char *argv[])
{
	int T = 0, cas = 1;
	int p = 0, q = 0, g = 0, d = 0, n = 0, wd = 0, wg = 0;
	int pd = 0, pg = 0, k = 0;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d %d", &n, &pd, &pg);
		if (pg == 100){
			if (pd != 100){
				printf("Case #%d: Broken\n", cas++);
				continue;
			}else{
				printf("Case #%d: Possible\n", cas++);
				continue;
			}
		}


		if (pg == 0){
			if (pd != 0){
				printf("Case #%d: Broken\n", cas++);
				continue;
			}else{
				printf("Case #%d: Possible\n", cas++);
				continue;
			}
		}

		int flag = 0;
		for (int i = 1;i<=n;i++){
			d = i;
			if (d * pd % 100 == 0){
				flag = 1;
				break;
			}
		}

		if (flag == 0){
			printf("Case #%d: Broken\n", cas++);
		}else{
			wd = d * pd / 100;
			g = gcd(pg, 100);
			p = pg / g;
			q = 100 / g;
			k = divv((d - wd), (q-p));
			if (divv(d,q)>k){
				k = divv(d,q);
			}

			if (divv(wd,p)>k){
				k=divv(wd,p);
			}
			wg = k * p;
			g = k * q;

			if (wd<=d && wg<=g && wd<=wg && d<=g){
				printf("Case #%d: Possible\n", cas++);
			//	printf("%d/%d=%d/100, %d/%d=%d/100\n", wd, d, pd, k*p, k*q, pg);
			}else{
				printf("Case #%d: Broken\n", cas++);
			}
		}
	}
	return 0;
}
