#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//i = 2, j = 3, k = 4
int mult(int a, int b)
{
	if (a * a > 16 || b * b > 16 || a == 0 || b == 0)
		return 0;
	if (a * a == 1 || b * b == 1)
		return a * b;
	if (a * a == b * b)
		return - a / b;
	if (a * a == 4) //a = pm i
	{
		if (b * b == 9) //b = pm j
			return (a * b / 6) * 4;
		return (a * b / 8) * (-3); //b = pm k
	}
	if (a * a == 9) //a = pm j
	{
		if (b * b == 4) //b = pm i
			return (a * b / 6) * (-4);
		return (a * b / 12) * (2); //b = pm k
	}
	//a = pm k
	if (b * b == 9) //b = pm j
		return (a * b / 12) * (-2);
	return (a * b / 8) * (3); //b = pm i
}

int ans(int l, long rep, char * str)
{
	int curr = 1, i;
	int begin, end;
	char * newStr;
	for (i = 0; i < l; i++)
	{
		curr = mult(curr, str[i] - 'g');
	}
	if (curr * curr > 2 && rep % 4 != 2)
		return 0;
	else if (curr == 1)
		return 0;
	else if (curr == -1 && rep % 2 == 0)
		return 0;

	if (rep < 10)
	{
		newStr = (char *)malloc(sizeof(char) * (rep * l + 1));
		newStr[0] = '\0';
		for (i = 0; i < rep; i++)
			strncat(newStr, str, l);
		begin = 1e8;
		end = -1;
		curr = 1;
		for (i = 0; i < rep * l; i++)
		{
			curr = mult(curr, newStr[i] - 'g');
			if (curr == 2)
			{
				begin = i;
				break;
			}
		}
		curr = 1;
		for (i = rep * l - 1; i >= 0; i--)
		{
			curr = mult(newStr[i] - 'g', curr);
			if (curr == 4)
			{
				end = i;
				break;
			}
		}
		free(newStr);
		if (begin < end)
			return 1;
		return 0;
	}
	newStr = (char *)malloc(sizeof(char) * (10 * l + 1));
	newStr[0] = '\0';
	for (i = 0; i < 10; i++)
		strncat(newStr, str, l);
	begin = 1e8;
	end = -1;
	curr = 1;
	for (i = 0; i < 10 * l; i++)
	{
		curr = mult(curr, newStr[i] - 'g');
		if (curr == 2)
		{
			begin = i;
			break;
		}
	}
	curr = 1;
	for (i = 10 * l - 1; i >= 0; i--)
	{
		curr = mult(newStr[i] - 'g', curr);
		if (curr == 4)
		{
			end = i;
			break;
		}
	}
	free(newStr);
	if (begin < end)
		return 1;
	return 0;
}

int main()
{
	int cases, l, i;
	long x;
	scanf("%d\n", &cases);
	for (i = 0; i < cases; i++)
	{
		char * str;
		scanf("%d %ld\n", &l, &x);
		str = (char *)malloc(sizeof(char) * (l + 1));
		scanf("%s\n", str);
		if (ans(l, x, str))
			printf("Case #%d: YES\n", i + 1);
		else
			printf("Case #%d: NO\n", i + 1);
		free(str);
	}
}