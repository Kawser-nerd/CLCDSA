#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)
#pragma GCC diagnostic ignored "-Wunused-result"

int main(int argc, char** argv)
{
	char	in[4096];
	char	*tmp;
	int		N, K, count;

	fgets(in, sizeof(in), stdin);
	if( in[strlen(in)-1] == '\n' ) in[strlen(in)-1] = '\0';

	tmp = strtok( in, " " );
	N = atoi( tmp );

	tmp = strtok( NULL, " " );
	K = atoi( tmp );

	count = (N - 1)/(K - 1);
	if ( (N - 1)%(K - 1) )
	{
		count++;
	}

	printf("%d\n",count);
	return 0;
}