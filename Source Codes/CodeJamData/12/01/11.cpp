#include <cstdio>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<char, char> translate;
	string sampleInput  = "zy qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string sampleOutput = "qa zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	for(int i = 0; i < sampleInput.length(); i ++)
	{
		translate[sampleInput[i]] = sampleOutput[i];
	}

	int T;
	char buff[256];
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d",&T);
	for(int testcase = 1; testcase <= T; testcase ++)
	{
		fgets(buff, sizeof(buff), stdin);
		printf("Case #%d: ", testcase);
		for(int i = 0; buff[i] != '\0' && buff[i] != '\n' && buff[i] != '\r'; i ++)
		{
			if(isalpha(buff[i])) printf("%c", translate[buff[i]]);
			else printf("%c", buff[i]);
		}
		printf("\n");
	}
	return 0;
}