#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int c[100], s[100], t[100];
bool taken[100];
int nInit, nTotal, curCards;

int get_best_card() { // gets c[i] == 1, maximise s[i]
	int ret = -1;
	int best = -1;
	for (int i = 0; i < curCards; i++) {
		if (taken[i] || c[i] == 0) continue;
		if (s[i] > best) {
			best = s[i];
			ret = i;
		}
	}
	return ret;
}

int get_best_time() { // maximise t[i]
	int ret = -1;
	int best = 0;
	for (int i = 0; i < curCards; i++) {
		if (taken[i]) continue;
		if (t[i] > best) {
			best = t[i];
			ret = i;
		}
	}
	return ret;
}

int endgame(int curCards, int curTime) {
	int ret = 0;
	int curScore = 0;
	bool endgametaken[100];
	for (int i = 0; i < nTotal; i++) endgametaken[i] = taken[i];
	while (1) {
		//try greedying the rest
		vector<int> scoresleft;
		for (int i = 0; i < curCards; i++) {
			if (!endgametaken[i]) scoresleft.push_back(s[i]);
		}
		sort(scoresleft.begin(),scoresleft.end());
		reverse(scoresleft.begin(),scoresleft.end());
		int tmp = curScore;
		for (int i = 0; i < scoresleft.size() && i < curTime; i++) tmp += scoresleft[i];
		ret = max(ret,tmp);
		
		int next = -1, bestscore=-1;
		for (int i = 0; i < curCards; i++) {
			if (endgametaken[i]) continue;
			if (c[i] == 0) continue;
			if (s[i] > bestscore) {
				bestscore = s[i];
				next = i;
			}
		}
		if (next == -1) break;
		curCards = min(curCards+c[next],nTotal);
		curScore += s[next];
		curTime += t[next]-1;
		endgametaken[next] = 1;

		if (curScore > ret) ret = curScore;

		if (curTime == 0) break;
	}
	return ret;
}

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);

		scanf("%d",&nInit);
		for (int i = 0; i < nInit; i++) {
			scanf("%d %d %d",&c[i],&s[i],&t[i]);
		}
		scanf("%d",&nTotal);
		nTotal += nInit;
		for (int i = nInit; i < nTotal; i++) {
			scanf("%d %d %d",&c[i],&s[i],&t[i]);
		}
		for (int i = 0; i < nTotal; i++) {
			taken[i] = 0;
		}

		int bestScore=0;
		int curScore=0, curTime=1;
		curCards=nInit;
		while (1) {
			// attempt endgame
			int possScore = endgame(curCards,curTime) + curScore;
			if (possScore > bestScore) bestScore = possScore;

			// otherwise, continue greedy
			int next = get_best_time();
			if (next == -1) next = get_best_card();
			if (next == -1) break;

			curCards = min(curCards+c[next],nTotal);
			curScore += s[next];
			curTime += t[next]-1;
			taken[next] = 1;

			if (curScore > bestScore) bestScore = curScore;
			if (curTime == 0) break;
		}
		
		printf("Case #%d: %d\n",test,bestScore);
	}
}
