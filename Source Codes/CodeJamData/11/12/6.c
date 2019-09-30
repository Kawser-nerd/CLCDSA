#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

char dict[10010][12];
char list[128][32];

char res[64][12];
char table[32] = {0};
int N = 0, M = 0;

int cmp(char* x, char* y, int tb[32]){
	int len1 = strlen(x);
	int len2 = strlen(y);
	if (len1 != len2) return 0;
	for (int i = 0; i<len1; i++){
		if (tb[y[i]-'a'] == -1){
			return 0;
		}

		if ((x[i]=='*' && tb[y[i]-'a']==0) || (x[i] == y[i])){
			
		}else{
			return 0;
		}
	}
	return 1;
}

int calc(char* word, char* lst){
	int len = strlen(word);
	char tword[32];


	int ret = 0;
	int tb[32] = {0};

	memset(table, 0, sizeof(table));
	for (int i = 0; i<N; i++){
		int tl = strlen(dict[i]);
		if (tl == len){
			for (int j = 0; j<len;j++){
				table[dict[i][j]-'a'] = 1;
			}
		}
	}
	for (int i = 0; i<len; i++){
		tword[i] = '*';
	}
	tword[len] = 0;

	for (int x = 0; x<26; x++){
		int y = lst[x] - 'a';
		if (table[y]==0){
			continue;
		}

		int flag = 0;
		for (int i = 0; i<len; i++){
			if (word[i] == y + 'a'){
				tb[y] = 1;
				tword[i] = y + 'a';
				flag = 1;
			}
		}

		if (flag == 0){
			ret++;
			tb[y] = -1;
		}

		memset(table, 0, sizeof(table));
		for (int i = 0; i<N; i++){
			if (cmp(tword, dict[i], tb)){
				int tlen = strlen(dict[i]);
				for (int j = 0; j<tlen; j++){
					table[dict[i][j]-'a'] = 1;
				}
			}
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int T = 0, cas = 1;

	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &N, &M);

		memset(table, 0, sizeof(table));
		for (int i = 0; i<N; i++){
			scanf("%s", dict[i]);
			int len = strlen(dict[i]);
			for (int j = 0; j<len; j++){
				table[dict[i][j]-'a'] = 1;
			}
		}

		for (int i = 0; i<M; i++){
			scanf("%s", list[i]);
		}

		memset(res, 0, sizeof(res));
		for (int i = 0; i<M; i++){
			int maxv = -1;
			char tmp[12];
			for (int j = 0; j<N; j++){
				int x = calc(dict[j], list[i]);
				if (x>maxv){
					sprintf(tmp, "%s", dict[j]);
					maxv = x;
				}
			}
			sprintf(res[i], "%s", tmp);
		}

		printf("Case #%d:", cas++);
		for (int i = 0; i<M; i++){
			printf(" %s", res[i]);
		}
		printf("\n");
	}
	return 0;
}
