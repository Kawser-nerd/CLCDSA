#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std ;

double my[1100] ;
double other[1100] ;
int n ;
int used[1100] ;

bool Try(int score)
{
	for(int i=0;i<score;i++)
		if(my[n-i-1]<other[score-i-1])
			return false ;
	return true ;
}

int main(void)
{
	int tc ;
	cin >> tc ;
	
	for(int c=1;c<=tc;c++)
	{
		cin >> n ;
		
		for(int i=0;i<n;i++)
			cin >> my[i] ;
		for(int i=0;i<n;i++)
			cin >> other[i] ;
		sort(my, my+n) ;
		sort(other, other+n) ;
		
		int ans2 = 0 ;
		int ans = 0 ;
		memset(used,0,sizeof(used)) ;
		for(int i=0;i<n;i++)
		{
			double myval = my[i] ;
			int otherid = -1 ;
			for(int i=n-1;i>=0;i--)
				if(used[i]==0 && other[i]>myval)
				{
					otherid = i ;
				}
			if(otherid==-1)
			{
				for(otherid=0;used[otherid]==1;otherid++) ;
				ans2++ ;
			}
			used[otherid] = 1 ;
		}
		for(ans = n;ans>0 && Try(ans)==false;ans--) ;
		printf("Case #%d: %d %d\n",c,ans,ans2) ;
	}
	
	return 0 ;
}
