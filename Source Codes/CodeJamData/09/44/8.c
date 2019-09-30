#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int X[40], Y[40], R[40] ;

inline double max(double a, double b)
{
    return (a > b ? a : b) ;
}


inline double min(double a, double b)
{
    return (a < b ? a : b) ;
}

inline double min3(double a, double b, double c)
{
    return min(a, min(b,c)) ;
}

inline double dist(int i, int j)
{
    int x = X[i] - X[j] ;
    int y = Y[i] - Y[j] ;
    return(sqrt(x*x + y*y)+R[i]+R[j]) ;
}

int main()
{
    int T, N ;
    int t, n ;
    
    scanf("%d", &T) ;
    for (t = 1 ; t <= T ; ++t)
    {
	printf("Case #%d: ", t) ;
	
	scanf("%d", &N) ;
	for (n = 0 ; n < N ; ++n)
	{
	    scanf("%d %d %d", &X[n], &Y[n], &R[n]) ;
	}
	if (N == 1) printf("%.6f\n", (double) R[0]) ;
	else if (N == 2) printf("%.6f\n", max(R[0],R[1])) ;
	else
	{
	    printf("%.6f\n", min3(max(dist(0,1)/2,R[2]), max(dist(0,2)/2,R[1]), max(dist(1,2)/2,R[0])));
	}
    }
    
    return 0 ;
}
