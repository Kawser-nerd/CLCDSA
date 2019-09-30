#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int bestFound, bestID;
vector<pair<int, pair<vector<int>,int> > > mod_words;
void dfs(int upto, int score, int lo, int hi) {
	//looking at range [lo,hi)
	//printf("[%d %d %d %d]\n",upto,score,lo,hi);
	if (lo+1 == hi) {
		if (score > bestFound) {
			bestFound = score;
			bestID = mod_words[lo].second.second;
		}
		if (score == bestFound) {
			bestID = min(bestID,mod_words[lo].second.second);
		}
		return;
	}
	bool anything = 0;
	for (int i = lo+1; i < hi; i++) {
		if (mod_words[i].second.first[upto] != mod_words[i-1].second.first[upto]) {
			anything = 1;
		}
	}
	if (!anything) {
		dfs(upto+1,score,lo,hi);
		return;
	}
	int lastThing=lo;
	for (int i = lo+1; i <= hi; i++) {
		if (i==hi || mod_words[i].second.first[upto] != mod_words[i-1].second.first[upto]) {
			int newscore = score;
			if (mod_words[i-1].second.first[upto] == 0) newscore++;
			dfs(upto+1,newscore,lastThing,i);
			lastThing = i;
		}
	}
}

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		int nWords, nLists;
		scanf("%d %d ",&nWords,&nLists);
		char wordcontents[nWords][15];
		vector<pair<int, pair<vector<int>,int> > > words;

		for (int i = 0; i < nWords; i++) {
			scanf("%s ",wordcontents[i]);
			vector<int> new_word = vector<int>(26,0);
			for (int j = 0; j < strlen(wordcontents[i]); j++) {
				new_word[wordcontents[i][j]-'a'] += 1<<j;
			}
			words.push_back(make_pair(strlen(wordcontents[i]),make_pair(new_word,i)));
		}
		printf("Case #%d:",test);
		
		for (int i = 0; i < nLists; i++) {
			char list[30];
			scanf("%s ",list);
			mod_words = words;
			for (int j = 0; j < nWords; j++) {
				for (int k = 0; k < 26; k++) {
					mod_words[j].second.first[k] = words[j].second.first[list[k]-'a'];
				}
			}
			sort(mod_words.begin(),mod_words.end());
			/*for (int j = 0; j < nWords; j++) {
				printf("%d: %s\n",j,wordcontents[mod_words[j].second.second]);
			}*/
			bestFound = -1;
			bestID = -1;
			int lastgap=0;
			for (int j = 1; j <= nWords; j++) {
				if (j!=nWords&&mod_words[j].first == mod_words[j-1].first) continue;
				dfs(0,0,lastgap,j);
				lastgap=j;
			};
			printf(" %s",wordcontents[bestID]);
		}
		printf("\n");
	}
}
