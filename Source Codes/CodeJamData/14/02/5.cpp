#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std ;

int main(void)
{
	int tc ;
	cin >> tc ;
	
	for(int c=1;c<=tc;c++)
	{
		double C, F, X ;
		
		cin >> C >> F >> X ;
		
		double ans = X/2 ;
		double part = 0 ;
		for(int x=0;;x++)
		{
			part += C/(2+x*F) ;
			double tmpans = part + X/(2+(x+1)*F) ;
			if(tmpans < ans && ans-tmpans>=1e-9)
				ans = tmpans ;
			else
				break ;
		}
		printf("Case #%d: %.9f\n", c, ans) ;
	}
	
	return 0 ;
}
