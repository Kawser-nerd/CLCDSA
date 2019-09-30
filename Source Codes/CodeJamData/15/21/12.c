#include <stdio.h>
long p10[15];
long flip(long n){
	long ans = 0;
	while(n) {
		ans = ans*10+(n%10);
		n/=10;
	}
	return ans;
}
int main() {
	p10[0]=1;
	int t,p;
	for(t=1;t<15;t++)
		p10[t]=10ll*p10[t-1];
	scanf("%d", &t);
	for (p=1;p<=t;p++){
		long n;
		scanf("%ld", &n);
		int digits = 1;
		long now = 1;
		long steps = 1;
		while(now*10 <= n) {
			steps += p10[digits/2]-1;
			long tmp = now+p10[digits/2]-1;
			//printf("%ld->%ld, %ld\n", now, tmp, p10[digits/2]-1);
			//Then flip
			if (digits > 1) {
				//printf("%ld->%ld, 1\n", tmp, flip(tmp));
				steps++;
				tmp = flip(tmp);
			}
			steps += p10[(digits+1)/2]-1;
			//printf("%ld->%ld, %ld\n", tmp, tmp+p10[(digits+1)/2]-1, p10[(digits+1)/2]-1);
			now*=10;
			digits++;
		}
		if (digits == 1) {
			printf("Case #%d: %ld\n", p, n);
			continue;
		}
		if (now == n) {
			printf("Case #%d: %ld\n", p, steps);
			continue;
		}
		//Now we have same digits, we get the higher half right
		//Flip, then the lower half
		long hi = flip(n/p10[(digits+1)/2]);
		long lo = n%p10[(digits+1)/2];
		if (lo != 0) {
			long tmp = now+hi;
			steps += hi;
			//printf("%ld->%ld, %ld\n", now, now+hi, hi);
			if (hi!=1) {
			//	printf("%ld->%ld, 1\n", tmp, flip(tmp));
				steps ++;
				tmp = flip(tmp);
			}
			//printf("%ld->%ld, %ld\n", tmp, tmp+lo-1, lo-1);
			steps += lo-1;
		} else {
			hi = flip(n/p10[(digits+1)/2]-1);
			long tmp = now+hi;
			steps += hi;
			//printf("%ld->%ld, %ld\n", now, now+hi, hi);
			if (hi!=1) {
			//	printf("%ld->%ld, 1\n", tmp, flip(tmp));
				steps ++;
				tmp = flip(tmp);
			}
			//printf("%ld->%ld, %ld\n", tmp, tmp+lo+p10[(digits+1)/2]-1, lo+p10[(digits+1)/2]-1);
			steps += lo+p10[(digits+1)/2]-1;
		}
		printf("Case #%d: %ld\n", p, steps);
	}
}
