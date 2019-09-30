#include <stdio.h>
#include <string.h>

long check(long n, long field[1000], long topic[2][1000])
{
	long i, j, x, y;
	
	
	for(i = 0; i < n; ++i)
		if(field[i] == 1)
		{
			for(j = x = y = 0; j < n && !(x && y); ++j)
				if(field[j] == 2)
				{
					if(topic[0][i] == 0 || topic[0][j] == topic[0][i])
						x = 1;

					if(topic[1][i] == 0 || topic[1][j] == topic[1][i])
						y = 1;
				}
				
			if(!(x && y))
				return 0;
		}
	
	return 1;
}

long recursive(long n, long r, long field[1000], long topic[2][1000])
{
	long i, j;
	
	
	if(!r)
		return check(n, field, topic);
	
	for(i = 0; i < n; ++i)
		if(field[i] == 1)
		{
			field[i] = 2;
			
			if(j = recursive(n, r - 1, field, topic))
				return 1;
				
			field[i] = 1;
		}
	
	return 0;
}

long backtrack(long n, long d, long field[1000], long topic[2][1000])
{
	long i;
	
	
	for(i = 1; i < d; ++i)
	{
		if(recursive(n, i, field, topic))
			return i;
	}
	
	return d;
	
}

void function()
{
	char word[42], string[2][1000][21];
	long n, i, j, k, x, y, f = 0, d = 0, topic[2][1000], rep[2][1000], field[1000];
	
	
	scanf("%ld\n", &n);
	
	for(i = 0; i < n; ++i)
		topic[0][i] = topic[1][i] = rep[0][i] = rep[1][i] = field[i] = 0;
	
	
	for(i = x = y = 0; i < n; ++i)
	{
		scanf("%s", word);
		strcpy(string[0][i], word);
		scanf("%s", word);
		strcpy(string[1][i], word);
		
		for(j = 0; j < i; ++j)
			if(!strcmp(string[0][i], string[0][j]))
			{
				topic[0][i] = topic[0][j];
				rep[0][i] = rep[0][j] = 1;
			}
		
		if(!topic[0][i])
				topic[0][i] = ++x;
		
		for(j = 0; j < i; ++j)
			if(!strcmp(string[1][i], string[1][j]))
			{
				topic[1][i] = topic[1][j];
				rep[1][i] = rep[1][j] = 1;
			}
			
		if(!topic[1][i])
			topic[1][i] = ++y;
	}	
	
	for(i = 0; i < n; ++i)
		field[i] = (rep[0][i] && rep[1][i]);
		
	for(i = 0; i < n; ++i)
		if(field[i])
		{
			for(j = x = y = 0; j < n && !(x && y); ++j)
				if(!field[j])
				{
					if(topic[0][j] == topic[0][i])
					{
						x = 1;
						topic[0][i] = 0;
					}
					
					if(topic[1][j] == topic[1][i])
					{
						y = 1;
						topic[1][i] = 0;
					}
				}
				
			if(x && y)
			{
				++f;
				field[i] = 0;
			}
			else
				++d;
		}
	
	if(d)
	{
		f += d - backtrack(n, d, field, topic);
	}
	
	printf("%ld", f);
}

int main()
{
	long i, j, k, count;
	
	
	scanf("%ld", &count);

	for(i = 1; i <= count; ++i)
	{
		printf("Case #%ld: ", i);
		function();		
		printf("\n");
	}
	
	
	return 0;
}
