#include <stdio.h>
#include <stdlib.h>

long long gcd(long long x, long long y)
{
	if(x < y) 
		return gcd(y,x);  // x>y
	if( y == 0) 
		return x;  // if y=0, x is GCD 
	else
	{
		if( !(x%2) )
		{                 
			if( !(y%2) )  //x,y both even
				return 2*gcd(x >> 1, y >> 1);    
			else      // x is even, y is odd
				return gcd(x >> 1, y );  
		}
		else 
		{
			if( !(y%2) )  // x is  odd,  y is even
				return gcd(x, y >> 1);
			else       // x, y both odd
				return gcd(y,x-y); 
		}
	}
}

int main(int argc, char *argv[])
{
	int T, i, cnt;
	int cases = 0;
	long long P, Q, common;
	char str[100];
	scanf("%d", &T);
	while(T-- > 0)
	{
		cases++;
		scanf("%s", str);
		i = 0;
		while(str[i] != '/')
			i++;
		str[i] = '\0';
		P = atoll(str);
		Q = atoll(str+i+1);
		common = gcd(P, Q);
//		printf("P = %lld, Q = %lld, gcd = %lld\n", P, Q, common);
		P /= common;
		Q /= common;
		if((Q & (Q-1)) != 0) // if Q is not pound of 2, impossible
		{
			printf("Case #%d: impossible\n", cases);
			continue;
		}
		else
		{
			cnt = 0;
			while(P < Q)
			{
				cnt++;
				Q >>= 1;
			}
			printf("Case #%d: %d\n", cases, cnt);
		}
	}
	return 0;
}
