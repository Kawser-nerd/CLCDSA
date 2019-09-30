#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, H, W ;

struct cell
{
  int a, da, dh, dw ;
  char b ;
} ;

struct cell map[102][102] ;
char b ;

void init_cell(int a, int h, int w)
{
    map[h][w].a = a ;
    map[h][w].da = a ;
    map[h][w].dh = h ;
    map[h][w].dw = w ;
    map[h][w].b = 0 ;
}

void flow(int h, int w, int dh, int dw)
{
    if (map[h][w].da > map[dh][dw].a)
    {
	map[h][w].da = map[dh][dw].a ;
	map[h][w].dh = dh ;
	map[h][w].dw = dw ;
    }
}

void basin(int h, int w)
{
    if (map[h][w].b != 0) return ;
    map[h][w].b = b ;
    if (map[h-1][w].dh == h && map[h-1][w].dw == w) basin(h-1,w) ;
    if (map[h+1][w].dh == h && map[h+1][w].dw == w) basin(h+1,w) ;
    if (map[h][w-1].dh == h && map[h][w-1].dw == w) basin(h,w-1) ;
    if (map[h][w+1].dh == h && map[h][w+1].dw == w) basin(h,w+1) ;
}

void sink(int h, int w)
{
    int dh, dw ;
    dh = map[h][w].dh ;
    dw = map[h][w].dw ;
    while (dh != h || dw != w)
    {
	h = dh ; w = dw ;
	dh = map[h][w].dh ;
	dw = map[h][w].dw ;
    }
    ++b ;
    basin(h, w) ;
}

int main()
{
    int a, t, w, h ;
    for (w = 0 ; w < 102 ; ++w)
    {
	init_cell(12345, 0, w) ;
	init_cell(12345, w, 0) ;
    }
    scanf("%d", &T) ;
    for (t = 1 ; t <= T ; ++t)
    {
	scanf("%d %d", &H, &W) ;
	for (h = 1 ; h <= H ; ++h)
	{
	    for (w = 1 ; w <= W ; ++w)
	    {
		scanf("%d", &a) ;
		init_cell(a, h, w) ;
	    }
	    init_cell(12345, h, W+1) ;
	}
	for (w = 1 ; w <= W ; ++w)
	  init_cell(12345, H+1, w) ;
	
	for (h = 1 ; h <= H ; ++h)
	{
	    for (w = 1 ; w <= W ; ++w)
	    {
		flow(h, w, h-1, w  ) ;
		flow(h, w, h  , w-1) ;
		flow(h, w, h  , w+1) ;
		flow(h, w, h+1, w  ) ;
	    }
	}
	
	b = 'a' - 1 ;
	
	for (h = 1 ; h <= H ; ++h)
	{
	    for (w = 1 ; w <= W ; ++w)
	    {
		if (map[h][w].b == 0)
		{
		    sink(h, w) ;
		}
	    }
	      
	}
	printf("Case #%d:\n", t) ;
	for (h = 1 ; h <= H ; ++h)
	{
	    printf("%c", map[h][1].b) ;
	    for (w = 2 ; w <= W ; ++w)
	    {
		printf(" %c", map[h][w].b) ;
	    }
	    printf("\n") ;
	}
    }
    return 0 ;
}
