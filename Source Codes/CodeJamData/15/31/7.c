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

	unsigned long test_cases,test_case_var,answer,r,c,w;
	test_cases=fast_unsigned();
	for(test_case_var=1;test_case_var<=test_cases;test_case_var++)
	{
		r=fast_unsigned();
		c=fast_unsigned();
		w=fast_unsigned();
		answer=r*(c/w)+w-1;
		if(c%w)
			answer+=1;
		printf("Case #%lu: %lu\n",test_case_var,answer);
	}
	return 0;
}