#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 99999999

typedef struct
{
	int x;
	int y;
} Ponto;

Ponto pontos[MAXN];
int topo = 0;

int main()
{
	long long nTestes, t, n, A, B, C, D, x0, y0, X, Y, i, M, i1, i2, i3, qt;
	double cX, cY;
	scanf("%lld", &nTestes);
	
	for(t = 1; t <= nTestes; ++t)
	{
		topo = qt = 0;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &A, &B, &C, &D, &x0, &y0, &M);
		
		X = x0, Y = y0;
		pontos[topo].x = X;
		pontos[topo].y = Y;
		++topo;

		for(i = 1; i < n; ++i)
		{
  			X = (A * X + B) % M;
  			Y = (C * Y + D) % M;
  			pontos[topo].x = X;
			pontos[topo].y = Y;
			++topo;
		}
		
		for(i1 = 0; i1 < topo; ++i1)
		{
			for(i2 = i1 + 1; i2 < topo; ++i2)
			{
				if(i1 == i2) continue;
							
				for(i3 = i2 + 1; i3 < topo; ++i3)
				{					
					if(i1 == i3) continue;
					if(i2 == i3) continue;
					
					cX = (double)(pontos[i1].x + pontos[i2].x + pontos[i3].x) / (double)3;
					cY = (double)(pontos[i1].y + pontos[i2].y + pontos[i3].y) / (double)3;
					
					if(cX == (long long)cX && cY == (long long)(cY))
						++qt;
				}
			}
		}
		
		printf("Case #%lld: %lld\n", t, qt);
	}
	
	return 0;
}
