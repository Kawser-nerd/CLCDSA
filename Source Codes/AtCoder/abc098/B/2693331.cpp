#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool letter[26][2];

int main()
{
	int l,total,answer;
	char str[105];
	scanf("%d%s",&l,&str);
	answer = 0;
	for (int i = 0; i < l; i++)
	{
		memset(letter,0,sizeof(letter));
		total = 0;
		for (int j = 0; j < i; j++)
		{
			letter[str[j] - 'a'][0] = 1;
		}
		for (int k = i; k < l; k++)
		{
			letter[str[k] - 'a'][1] = 1;
		}
		for (int m = 0; m < 26; m++)
		{
			total += (letter[m][0] & letter[m][1]);
		}
		answer = max(answer,total);
	}
	printf("%d\n",answer);
	return 0;
} ./Main.cpp:12:18: warning: format specifies type 'char *' but the argument has type 'char (*)[105]' [-Wformat]
        scanf("%d%s",&l,&str);
                 ~~     ^~~~
1 warning generated.