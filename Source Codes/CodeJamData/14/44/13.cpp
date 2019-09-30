#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int m,n;

struct Node
{
	int ownWord;
	int wordCnt;
	int trieChildCnt;
	int children[26];

	int cost;
	int numberOf;
};

const int mod = 1000000007;

Node trie[1000*100+1];
int tcnt;
int pas[128][128];

void initTrieNode(int ind)
{
	trie[ind].ownWord = 0;
	trie[ind].wordCnt = 0;
	trie[ind].trieChildCnt = 0;
	for(int i = 0; i < 26; i++) {
		trie[ind].children[i] = -1;
	}

	trie[ind].cost = 0;
	trie[ind].numberOf = 1;
}

void makeTrie(string word)
{
	int node = 0;
	trie[node].wordCnt++;

	for(int i = 0; i < word.length(); i++) {
		int cind = word[i] - 'A';
		if (trie[node].children[cind] == -1) {
			initTrieNode(tcnt);
			trie[node].children[cind] = tcnt;
			trie[node].trieChildCnt++;
			tcnt++;
		}
		node = trie[node].children[cind];
		trie[node].wordCnt++;
	}
	trie[node].ownWord = 1;
}

int main(){
	int T;
	for(int i = 0; i < 128; i++) {
		pas[i][0]= pas[i][i] = 1;
		for(int j = 1; j < i; j++) {
			pas[i][j] = (pas[i-1][j-1] + pas[i-1][j]) % mod;
		}
	}
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		scanf("%d%d",&m,&n);

		initTrieNode(0);
		tcnt = 1;

		for(int i = 0; i < m; i++) {
			char buffer[128];
			scanf("%s", buffer);
			makeTrie(buffer);
		}

		for(int i = tcnt - 1; i >= 0; i--) {
			if (trie[i].trieChildCnt == 0) { // terminal
				trie[i].cost = 1;
				trie[i].numberOf = 1;
				continue;
			}
			int totColorCnt = min(n, trie[i].wordCnt);
			if (trie[i].trieChildCnt == 1 && trie[i].ownWord == 0) { // single and none
				for(int j = 0; j < 26; j++) {
					int child = trie[i].children[j];
					if (child != -1) {
						trie[i].cost = trie[child].cost;
						trie[i].numberOf = trie[child].numberOf;
						break;
					}
				}
				trie[i].cost += totColorCnt;
				continue;
			}
			int dt[2][102]={0,};
			if (trie[i].ownWord) {
				dt[0][1] = 1;
			} else {
				dt[0][0] = 1;
			}

			int li = 0, ci = 1;

			for(int j = 0; j < 26; j++) {
				int child = trie[i].children[j];
				if (child == -1) continue;
				
				trie[i].cost += trie[child].cost;

				int colorCnt = min(n, trie[child].wordCnt);

				// final color count
				for(int k = colorCnt; k <= totColorCnt; k++) {
					// from l -> k
					int minL = max(0, k - colorCnt);
					for(int l = minL; l <= k; l++) {
						int overlapCount = l - (k - colorCnt);
						dt[ci][k] = (dt[ci][k] +
							dt[li][l] *
							(long long)pas[l][overlapCount] % mod *
							(long long)pas[k][l] % mod *
							(long long)trie[child].numberOf % mod) % mod;
					}
				}

				ci = li;
				li ^= 1;
				memset(dt[ci], 0, sizeof(dt[ci][0]) * (totColorCnt+1));
			}
			trie[i].cost += totColorCnt;
			trie[i].numberOf = dt[li][totColorCnt];
		}

		printf("Case #%d: %d %d\n", testcase, trie[0].cost, trie[0].numberOf);
	}
	return 0;
}
