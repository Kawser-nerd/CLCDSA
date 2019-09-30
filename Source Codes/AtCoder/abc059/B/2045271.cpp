#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

char a[10005], b[10005];
int main()
{
	int lena, lenb, flag = 1;
	scanf("%s",a);
	getchar();
	scanf("%s",b);
	lena = strlen(a);
	lenb = strlen(b);
	if(lena == lenb)
	{
		for(int i = 0; i != max(lena, lenb); i++)
		{
			if(a[i] > b[i])
			{
				printf("GREATER\n");
				break;
			}
			else if(a[i] < b[i])
			{
				printf("LESS\n");
				break;
			}
			else
			{
				flag = 0;
				continue;
			}
		}
		if(flag == 0)
		{
			printf("EQUAL\n");
		}
	}
	if(lena > lenb)
	{
		printf("GREATER\n");
	}
	if(lena < lenb)
	{
		printf("LESS\n");
	}
}