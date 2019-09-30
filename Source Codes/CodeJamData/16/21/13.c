#include <stdio.h>

void pull(char* str,char* phone)
{
	int let[256]={0},dig[10]={0},len=0;
	char* word[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	int id[10][2]={{'Z',0},{'X',6},{'G',8},{'W',2},{'T',3},{'R',4},{'O',1},{'F',5},{'S',7},{'N',9}};
	while (str[len]) let[str[len++]]++;
	while (len)
	{
		int w=0;while (let[id[w][0]]==0) w++;
		w=id[w][1];dig[w]++;
		for (int i=0;word[w][i];i++) {len--;let[word[w][i]]--;}
	}
	for (int i=0;i<10;i++)
		while (dig[i]--) *phone++='0'+i;
	*phone=0;
}

int main()
{
	int cases;scanf("%d",&cases);
	for (int cs=1;cs<=cases;cs++)
	{
		char s[2003];scanf(" %s",s);
		char p[2003];pull(s,p);
		printf("Case #%d: %s\n",cs,p);
	}
}