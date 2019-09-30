#include<stdio.h>
char fast_char_var;
#define	fast_unsigned_dtype	unsigned long
fast_unsigned_dtype fast_unsigned_var;
fast_unsigned_dtype fast_unsigned()
{
	fast_char_var=getchar_unlocked();
	while(fast_char_var<48||fast_char_var>57)
		fast_char_var=getchar_unlocked();
	fast_unsigned_var=0;
	while(fast_char_var>47&&fast_char_var<58)
	{
		fast_unsigned_var=(fast_unsigned_var<<1)+(fast_unsigned_var<<3)+fast_char_var-48;
		fast_char_var=getchar_unlocked();
	}
	return fast_unsigned_var;
}
int main()
{

	static unsigned long test_cases,test_case_var,k,l,s,frequency[129],loop_variable,a,b,max_theoretical, viability,prefix[129];
	char characters[102],to_produce[102],p[102];
	long double answer;
	test_cases=fast_unsigned();
	for(test_case_var=1;test_case_var<=test_cases;test_case_var++)
	{
		for(loop_variable=0;loop_variable<129;loop_variable++)
		{
			prefix[loop_variable]=0;
			frequency[loop_variable]=0;
		}
		k=fast_unsigned();
		l=fast_unsigned();
		s=fast_unsigned();
		scanf("%s%s",characters,to_produce);
		//printf("%s %s %lu %lu %lu\n",characters,to_produce,k,l,s);
		for(loop_variable=0;loop_variable<k;loop_variable++)
			frequency[characters[loop_variable]]++;
		answer=1; viability=1;
		for(loop_variable=0;loop_variable<l;loop_variable++)
		{
			viability*=frequency[to_produce[loop_variable]]?1:0;
			answer*=(((double)frequency[to_produce[loop_variable]])/k);
		}
		answer*=(s-l+1);
		max_theoretical=0;
		
		for(loop_variable=0;loop_variable<=l;loop_variable++)
			p[loop_variable+1]=to_produce[loop_variable];
		prefix[1]=0;
		a=0;
		for(b=2;b<=l;b++)
		{
			while(a>0&&p[a+1]!=p[b])
				a=prefix[a];
			if(p[a+1]==p[b])
				a=a+1;
			prefix[b]=a;
		}
		
		if(s>=l)
			max_theoretical=viability*(1+(s-l)/(l-prefix[l]));
		else
		{
			answer=0;
			max_theoretical=0;
		}
		printf("Case #%lu: %0.6Lf\n",test_case_var,max_theoretical-answer);
	}
	return 0;
}