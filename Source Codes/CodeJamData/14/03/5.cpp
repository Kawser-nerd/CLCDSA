#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std ;

int map[110][110] ;

char getChar(int id)
{
	switch(id)
	{
		case 0 :
			return '.' ;
		case 1 :
			return '*' ;
		default :
			return 'c' ;
	}
}

bool Do(int my, int mx, int tiles)
{
	//my<=mx
	if(tiles==1)
	{
		for(int y=0;y<my;y++)
			for(int x=0;x<mx;x++)
				map[y][x] = 1 ;
		map[0][0] = 2 ;
		return true ;
	}
	if(my==1)
	{
		memset(map,0,sizeof(map)) ;
		for(int x=tiles;x<mx;x++)
			map[0][x] = 1 ;
		map[0][0] = 2 ;
		return true ;
	}
	if(my==2)
	{
		if(tiles>=4 && tiles%2==0)
		{
			memset(map,0,sizeof(map)) ;
			for(int x=tiles/2;x<mx;x++)
				map[0][x] = map[1][x] = 1 ;
			map[0][0] = 2 ;
			return true ;
		}
		return false ;
	}
	if(tiles==2 || tiles==3 || tiles==5 || tiles==7)
		return false ;
	
	for(int y=0;y<my;y++)
		for(int x=0;x<mx;x++)
			map[y][x] = 1 ;
			
	for(int y=0;y<2;y++)
		for(int x=0;x<2;x++)
			map[y][x] = 0 ;
	
	tiles -= 4 ;
	
	if(tiles>0)
	{
		map[2][0] = map[2][1] = 0 ;
		tiles -= 2 ;
	}
	
	if(tiles>0)
	{
		map[0][2] = map[1][2] = 0 ;
		tiles -= 2 ;
	}
	
	for(int y=3;y<my && tiles>=2;y++)
	{
		map[y][0] = map[y][1] = 0 ;
		tiles -= 2 ;
	}
	
	for(int x=3;x<mx && tiles>=2;x++)
	{
		map[0][x] = map[1][x] = 0 ;
		tiles -= 2 ;
	}
	
	for(int y=2;y<my && tiles>0;y++)
		for(int x=2;x<mx && tiles>0;x++)
		{
			map[y][x] = 0 ;
			tiles-- ;
		}
			
	map[0][0] = 2 ;
	
	return true ;
}

int main(void)
{
	int tc ;
	cin >> tc ;
	
	for(int c=1;c<=tc;c++)
	{
		int my, mx, M ;
		cin >> my >> mx >> M ;
		
		int tiles = my*mx - M ;
		
		printf("Case #%d:\n",c) ;
		
		bool swaps = false ;
		if(my>mx)
		{
			swap(mx, my) ;
			swaps = true ;
		}
		
		if(Do(my, mx, tiles)==false)
			printf("Impossible\n") ;
		else if(swaps==false)
		{
			for(int y=0;y<my;y++)
			{
				for(int x=0;x<mx;x++)
					printf("%c",getChar(map[y][x])) ;
				printf("\n") ;
			}
		}
		else
		{
			for(int x=0;x<mx;x++)
			{
				for(int y=0;y<my;y++)
					printf("%c",getChar(map[y][x])) ;
				printf("\n") ;
			}
		}
	}
	
	return 0 ;
}
