#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[] = " welcome to code jam" ;
int TC, lstr ;

char buffer[510] ;
int count[510][25] ;

int main()
{
    int tc, i, j ;
    lstr = strlen(str) ;
    
    gets(buffer) ;
    sscanf(buffer, "%d", &TC) ;
    
    for (j = 0 ; j < lstr ; ++j) count[0][j] = 0 ;
    for (i = 0 ; i < 510 ; ++i) count[i][0] = 1 ;
    
    for (tc = 1 ; tc <= TC ; ++tc)
    {
	gets(&buffer[1]) ;
	for (i = 1 ; buffer[i] != '\0' ; ++i)
	{
	    for (j = 1 ; j < lstr ; ++j)
	    {
		if (buffer[i] != str[j])
		{
		    count[i][j] = count[i-1][j] ;
		}
		else
		{
		    count[i][j] = (count[i-1][j] + count[i-1][j-1]) % 10000 ;
		}
	    }
	}
	printf("Case #%d: %04d\n", tc, count[i-1][j-1]) ;
    }
    return 0 ;
}
