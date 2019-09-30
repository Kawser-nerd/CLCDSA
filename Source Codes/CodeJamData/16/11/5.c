#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d", &T);
	int test;
	for(test = 1; test <= T; test++)
	{
		char r[1010];
		scanf("%s", r);
		int len = strlen(r);
		int i;
		char used[1010];
		for(i = 0; i < len; i++)
			used[i] = 0;
		char out[1010];
		int outpos = 0;
		int pos = len;
		while(pos > 0)
		{
			int max = 0;
			int maxpos = -1;
			for(i = 0; i < pos; i++)
				if(r[i] >= max)
				{
					max = r[i];
					maxpos = i;
				}
			used[maxpos] = 1;
			out[outpos++] = max;
			pos = maxpos;
		}
		for(i = 0; i < len; i++)
			if(!used[i])
				out[outpos++] = r[i];
		out[outpos++] = 0;
		printf("Case #%d: %s\n", test, out);
	}
}
