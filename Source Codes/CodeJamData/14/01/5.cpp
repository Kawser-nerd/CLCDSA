#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std ;

int main(void)
{
	int tc ;
	cin >> tc ;
	
	int possible[20] ;
	int anscnt ;
	int ans ;
	
	for(int c=1;c<=tc;c++)
	{
		memset(possible,0,sizeof(possible)) ;
		anscnt = 0 ;
		
		int rn ;
		int tmp ;
		
		cin >> rn ;
		for(int r=1;r<rn;r++)
			for(int j=0;j<4;j++)
				cin >> tmp ;
		for(int j=0;j<4;j++)
		{
			cin >> tmp ;
			possible[tmp]++ ;
		}
		for(int r=rn;r<4;r++)
			for(int j=0;j<4;j++)
				cin >> tmp ;
		cin >> rn ;
		for(int r=1;r<rn;r++)
			for(int j=0;j<4;j++)
				cin >> tmp ;
		for(int j=0;j<4;j++)
		{
			cin >> tmp ;
			possible[tmp]++ ;
		}
		for(int r=rn;r<4;r++)
			for(int j=0;j<4;j++)
				cin >> tmp ;
		for(int i=1;i<=16;i++)
			if(possible[i]==2)
			{
				anscnt++ ;
				ans = i ;
			}
		if(anscnt>1)
			printf("Case #%d: Bad magician!\n",c) ;
		else if(anscnt==0)
			printf("Case #%d: Volunteer cheated!\n",c) ;
		else
			printf("Case #%d: %d\n",c,ans) ;
	}
	
	return 0 ;
}
