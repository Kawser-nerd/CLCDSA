#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<string>
//#include<string>
//#include<sstream>
using namespace std;
int main()
{
	char s[30];
	int n;
	scanf("%s",&s);
	s[5]=' ';
	s[13]=' ';
	printf("%s\n",s);
} ./Main.cpp:16:13: warning: format specifies type 'char *' but the argument has type 'char (*)[30]' [-Wformat]
        scanf("%s",&s);
               ~~  ^~
1 warning generated.