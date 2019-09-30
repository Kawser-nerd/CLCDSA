#include <stdio.h>

int main(void)
{
	int c;
	scanf("%u", &c);
	
	for (int ic = 1; ic <= c; ++ic)
	{
		_Bool field[101][101] = { 0 };
		
		int r;
		scanf("%u", &r);
		
		for (int i = 0; i < r; ++i)
		{
			int x1, y1, x2, y2;
			scanf("%u%u%u%u", &x1, &y1, &x2, &y2);
			
			for (int x = x1; x <= x2; ++x)
			{
				for (int y = y1; y <= y2; ++y)
				{
					field[x][y] = 1;
				}
			}
		}
		
		int m = 0;
		
		for (_Bool changed = 1; changed; )
		{
			++m;
			changed = 0;
			
			for (int x = 100; x; --x)
			{
				for (int y = 100; y; --y)
				{
					if (field[x][y])
					{
						if (!field[x-1][y] && !field[x][y-1])
						{
							field[x][y] = 0;
							changed = 1;
						}
					}
					else
					{
						if (field[x-1][y] && field[x][y-1])
						{
							field[x][y] = 1;
							changed = 1;
						}
					}
				}
			}
		}
		
		printf("Case #%u: %u\n", ic, m-1);
	}
	
	return 0;
}
