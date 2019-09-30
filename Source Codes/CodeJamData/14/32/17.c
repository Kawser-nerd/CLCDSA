#include <stdio.h>
#include <string.h>

int N;
char str[11][101]; // for small case
char long_str[1100];
char long_temp[1100];
int len_str;
int used[11];
int count[27]; // # of occurrences of a ~ z
int cnt;

void process_str(char str[])
{
	int i = 0;
	int k = 0;
	int j;
	int flag = 0;
	int len = strlen(str);
	char ch;
	memset(count, 0, sizeof(count));
	while(i <= len)
	{
		ch = str[i];
		long_temp[k++] = ch;
		j = i+1;
		while(ch == str[j])
			j++;
		i = j;
	}
	long_temp[k] = '\0';
	for(i = 0; i < k-1; i++)
	{
		count[long_temp[i]-'a']++;
		if(count[long_temp[i]-'a'] > 1)
			flag = 1;
	}
	if(flag == 0)
		cnt++;
}


// assert(used[i] == 1)
void DFS(int num_left)
{
	int k;
	if(num_left == 0)
	{
		long_str[len_str] = '\0';
//		printf("long_str = %s\n", long_str);
		process_str(long_str);
		return;
	}
	for(k = 1; k <= N; k++)
	{
		if(used[k] == 0)
		{
			used[k] = 1;
			strcpy(long_str + len_str, str[k]);
			len_str += strlen(str[k]);
			DFS(num_left-1);
			used[k] = 0; // backtrace
			len_str -= strlen(str[k]);
		}
	}
}

int main(int argc, char *argv[])
{
	int T, i;
	int cases = 0;
	scanf("%d", &T);
	while(T-- > 0)
	{
		cases++;
		scanf("%d", &N);
		memset(used, 0, sizeof(used));
		len_str = 0;
		cnt = 0;
		for(i = 1; i <= N; i++)
			scanf("%s", str[i]);
		DFS(N);
		printf("Case #%d: %d\n", cases, cnt);
	}
	return 0;
}
