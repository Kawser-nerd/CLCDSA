// doodhwala
// Mohit Surana

#include <stdio.h>
#include <math.h>

#define fo(a,b,c) for(a = (b); a < (c); a++)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
// macro credits - FrostByte

int main()
{
	int t;
	scanf("%d", &t);
	int r,c,w;
	int cases;
	
	fo(cases, 1, t+1)
	{
		scanf("%d %d %d", &r, &c, &w);
		int i,j;
		
		int xx = 0;
		if(w == 1)
			xx = 1;
		else if(c%w == 0)
			xx = w;
		else
			//xx = w + ((c)&1);
			xx = w + 1;
		
		int guess = (r-1)*(c/w) + (c/w - 1) +  xx;
		//printf("Case #%d: %d %d %d\n", cases, ((r-1)*(c/w)), (c/w - 1), xx );
		
		printf("Case #%d: %d\n", cases, guess );
	}
	return 0;
}
