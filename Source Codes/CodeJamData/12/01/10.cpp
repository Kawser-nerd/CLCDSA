#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

char cmap[26];

void ready()
{
	string s1="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv",
		   s2="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	for (int i=0; i<s1.length();i++)
		if (s1[i]!=' ')
			if (cmap[s1[i] - 'a'] == 0) cmap[s1[i]-'a'] = s2[i];
	cmap['q'-'a']='z';
	cmap['z'-'a']='q';
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	ready();
	int n;
	char s1[1000], s2[1000];
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)
	{
		gets(s1);
		for (int j=0; j<strlen(s1)+1; j++) 
		if (s1[j]!=' ') s2[j]=cmap[s1[j]-'a'];
			else s2[j] = s1[j];
		printf("Case #%d: %s\n",i+1,s2);
	}
}
