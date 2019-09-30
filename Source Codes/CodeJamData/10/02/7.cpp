#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
#include <gmp.h>
#include <stdio.h>
#include <gmpxx.h>

//Uses gmplib library. See http://gmplib.org/

using namespace std;

mpz_t nums[1005];
mpz_t diff[1005];
				
int main()
{	
	FILE *ip, *op;
	ip = fopen("./B-large.in","r");
	op = fopen("./B-large.out","w");
	
		
	int T;
	fscanf(ip,"%d",&T);
	for(int i = 0; i < T; i++)
	{
		int N;
		fscanf(ip,"%d",&N);
		
		for(int j = 0; j < N; j++)
		     gmp_fscanf(ip,"%Zd", nums[j]);

		for(int t = 0; t < N-1; t++)
		{
			mpz_t rop;
			mpz_init(rop);
			mpz_sub(rop,nums[t],nums[t+1]);
			mpz_abs(diff[t],rop);
		}
				
		mpz_t g;
		mpz_init(g);
		mpz_set(g,diff[0]);
				
		for(int t = 1; t < N-1; t++)
			mpz_gcd(g,g,diff[t]);
	
		mpz_t rem;
		mpz_init(rem);
		mpz_mod(rem,nums[0],g);
		mpz_sub(rem,g,rem);
		if(mpz_cmp(rem,g) == 0) mpz_init(rem);
		
		gmp_fprintf(op,"Case #%d: %Zd\n", i+1, rem);
	}
	
	fclose(ip);
	fclose(op);

	return 0;
}
		
