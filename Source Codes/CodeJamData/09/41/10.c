#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char matrix[40][40] ;
int pos[40], s ;

void swap(int *a, int *b)
{
    int c = *a ;
    *a = *b ;
    *b = c ;
    ++s ;
}

int findone(char *str)
{
    int i, j ;
    for (i = 0, j = 0 ; str[i] != '\0' ; ++i)
    {
	if (str[i] == '1') j = i ;
    }
    return j ;
}

int main()
{
    int T, N ;
    int t, n, i ;
    
    scanf("%d\n", &T) ;
    for (t = 1 ; t <= T ; ++t)
    {
	scanf("%d\n", &N) ;
	for (n = 0 ; n < N ; ++n)
	{
	    scanf("%s\n", matrix[n]) ;
	    pos[n] = findone(matrix[n]) ;
	}
	s = 0 ;
	for (n = 0 ; n < N - 1 ; ++n)
	{
	    if (pos[n] <= n) continue ;
	    for(i = n + 1 ; i < N && pos[i] > n ; ++i) ;
	    for (; i > n ; --i) swap(&pos[i], &pos[i-1]) ;
	}
	printf("Case #%d: %d\n", t, s) ;
    }

    return 0 ;
}
