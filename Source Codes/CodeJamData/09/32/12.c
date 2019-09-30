#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, N ;
    int t, i ;
    
    int x, y, z, dx, dy, dz ;
    int sx, sy, sz, sdx, sdy, sdz ;
    double fx, fy, fz, fdx, fdy, fdz, f, dmin, s ;
    
    scanf("%d", &T) ;
    for (t=1;t<=T;++t)
    {
	scanf("%d", &N) ;
	sx = sy = sz = sdx = sdy = sdz = 0 ;
	for (i = 0 ; i < N ; ++i)
	{
	    scanf("%d %d %d %d %d %d", &x, &y, &z, &dx, &dy, &dz) ;
	    sx += x ; sdx += dx ; 
	    sy += y ; sdy += dy ;
	    sz += z ; sdz += dz ; 
	}
	fx = sx / (double) N ; fdx = sdx / (double) N ;
	fy = sy / (double) N ; fdy = sdy / (double) N ;
	fz = sz / (double) N ; fdz = sdz / (double) N ;
	
	f = (fdx*fdx + fdy*fdy + fdz*fdz) ;
	
	//	printf("%f\n", f) ;
	s = 1 ; s = 0 ;
	if (fabs(f) > 0.000000001)
	{
	    s = - (fx*fdx + fy*fdy + fz*fdz) / (fdx*fdx + fdy*fdy + fdz*fdz) ;
	    if (s < 0)
	    {
		s = 1 ;
		s = 0 ;
	    }
	}
	
	fx += (s*fdx) ; fy += (s*fdy) ; fz += (s*fdz) ;
	dmin = sqrt((fx*fx) + (fy*fy) + (fz*fz)) ;
	printf("Case #%d: %.8f %.8f\n", t, dmin, fabs(s)) ;
    }
    return 0 ;
}
