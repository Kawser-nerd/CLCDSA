#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define max(X,Y) ((X)>(Y)?(X):(Y))
#define min(X,Y) ((X)<(Y)?(X):(Y))
#define isVowel(C) ((C)=='a' || (C)=='e' || (C)=='i' || (C)=='o' || (C)=='u')

#define MAXL 1000005


int main()
{
	int i,s,tcase,T,n,wlen,counter;
	unsigned long long res;
	char * word, * b;

	word = malloc(MAXL * sizeof(char));
	b = malloc(MAXL * sizeof(char));
	require(word!=NULL,"Out of memory!");
	require(b!=NULL,"Out of memory!");
	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		res = 0;
		scanf("%s %d",word,&n);
		wlen = strlen(word);

		counter=0;
		for(i=0;i<n;i++)
		{
			if(isVowel(word[i]))
				counter=0;
			else
				counter++;
		}
		b[0]=(counter>=n);
		for(i=n;i<wlen;i++)
		{
			if(isVowel(word[i]))
				counter=0;
			else
				counter++;
			b[i-n+1]=(counter>=n);
		}

		s=0;
		for(i=0;i+n<=wlen;i++)
		{
			if(b[i])
			{
				res += ((unsigned long long)(i-s+1))*(wlen - i - n + 1);
				s = i+1;
			}
		}
		printf("Case #%d: %llu\n",tcase,res);
		//printf("word:'%s'\nwlen: %d\nn: %d\n\n",word,wlen,n);
	}
	return 0;
}
