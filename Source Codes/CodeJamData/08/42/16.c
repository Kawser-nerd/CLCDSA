#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x, y, x2, y2, x3, y3 ;

int N, M, A ;

int calcarea()
{
    x = 0 ;

    for (y = 0 ; y <= M ; y++)
    {
	for (x2 = 0 ; x2 <= N ; x2++)
	{
	    for (y2 = 0 ; y2 <= y ; y2++)
	    {
		for (x3 = 0 ; x3 <= N ; x3++)
		{
		    for (y3 = y2 ; y3 <= M ; y3++)
		    {
			if (abs(x*y2 + x2*y3 + x3*y - x*y3 - x2*y - x3*y2) == A)
			  return 1 ;
		    }
		}
	    }
	}
    }
    return 0 ;
}


void getinput()
{
    scanf("%d %d %d", &N, &M, &A) ;
}

int main()
{
    int ncase, icase ;
    
    scanf("%d", &ncase) ;
    //    printf("ncase %d\n", ncase) ;
    for(icase = 1; icase <= ncase ; icase++)
    {
	getinput() ;
	if (calcarea() == 1)
	{
	    printf("Case #%d: %d %d %d %d %d %d\n", icase, x, y, x2, y2, x3, y3) ;
	}
	else
	{
	    printf("Case #%d: IMPOSSIBLE\n", icase) ;
	    
	}
    }
}

