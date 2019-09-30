#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1005], b[1005];
int main()
{
	scanf("%s %s",a,b);
	int lena = strlen(a);
	int lenb = strlen(b);
	if(lena > lenb)
	{
		printf("GREATER\n");
		return 0;
	}
	else if(lena < lenb)
	{
		printf("LESS\n");
		return 0;
	}
	else 
	{
		int flag = 0;
		for(int i = 0;i < lena;i++)
		{
			if(a[i] > b[i])
			{
				printf("GREATER\n");
				flag = 1;
				return 0;
			}
			else if(a[i] < b[i])
			{
				printf("LESS\n");
				flag = 1;
				return 0;
			}
		}
		if(flag == 0) printf("EQUAL\n");
	}
	return 0;
}