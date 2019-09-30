// doodhwala
// Mohit Surana

#include<stdio.h>

#define fo(a,b,c) for(a = (b); a < (c); a++)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
// macro credits - FrostByte

char ch[16][16];

int main()
{
	int t;
	scanf("%d", &t);
	int r,c,n;
	int cases;
	
	fo(cases, 1, t+1)
	{
		scanf("%d %d %d", &r, &c, &n);
		int i,j;
		
		int uh = 0;
		int rc = r*c; //
		int muh = (r+1)*(c+1);
		
		fi(r)
			fj(c)
				ch[i][j] = '\0';

		fi(1<<rc)
		{
			if(noOfBits(i) == n)
			{
				uh = getUH(i, r, c);
				muh = muh < uh ? muh : uh;
			}
		}
		printf("Case #%d: %d\n", cases, muh);
	}
	return 0;
}

int noOfBits(int n) //
{
	int ctr = 0;
	while(n)
	{
		ctr += n&1;
		n >>= 1;
	}
	return ctr;
}

int getUH(int v, int r, int c)
{
	int i,j;
	fi(r)
	{
		fj(c)
		{
			if(v & 1)
				ch[i][j] = '1';
			else
				ch[i][j] = '0';
			v >>= 1;
		}
	}
/*	
	printf("%d\n", v);
	fi(r)
	{
		fj(c)
			printf("%c ",ch[i][j]);
		printf("\n");
	}
*/	int uh = 0;
	fi(r)
		fj(c-1)
			if(ch[i][j] == '1' && ch[i][j+1] == '1')
				++uh;
	fi(r-1)
		fj(c)
			if(ch[i][j] == '1' && ch[i+1][j] == '1')
				++uh;
	return uh;
}
