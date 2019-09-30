#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 
#include <memory.h>

using namespace std; 

#define rep(i,n) for(int i=0;i<(n);++i)
#define clr(a,b) memset(a,b,sizeof(a)); 
#define all(c) (c).begin(), (c).end() 
#define inf 1000000000 

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

struct Card
{
	int cardDraw;
	int scoreAdd;
	int turnIncrease;
};

int getScore(int showDeck, vector<Card> hand, deque<Card> deck)
{
	int totalScore = 0;
	int turn = 1;

	while (turn > 0)
	{
		bool changed = false;

		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i].turnIncrease > 0)
			{
				totalScore += hand[i].scoreAdd;
				turn += hand[i].turnIncrease - 1;

				while (deck.size() && hand[i].cardDraw)
				{
					hand[i].cardDraw--;
					hand.push_back(deck.front());
					deck.pop_front();
				}

				hand.erase(hand.begin() + i);
				i--;

				changed = true;
			}
		}

		if (showDeck > 0)
		{
			int pos = -1;
			for (int i = 0; i < hand.size(); i++)
			{
				if (hand[i].cardDraw)
				{
					if (pos == -1 || hand[pos].scoreAdd < hand[i].scoreAdd)
					{
						pos = i;
					}
				}
			}

			if (pos != -1)
			{
				showDeck--;

				int i = pos;

				totalScore += hand[i].scoreAdd;
				turn += hand[i].turnIncrease - 1;

				while (deck.size() && hand[i].cardDraw)
				{
					hand[i].cardDraw--;
					hand.push_back(deck.front());
					deck.pop_front();
				}

				hand.erase(hand.begin() + i);

				changed = true;
			}
		}

		if (changed)
			continue;

		{
			int pos = -1;
			for (int i = 0; i < hand.size(); i++)
			{
				if (pos == -1 || hand[pos].scoreAdd < hand[i].scoreAdd)
				{
					pos = i;
				}
			}

			if (pos != -1)
			{
				showDeck--;

				int i = pos;

				totalScore += hand[i].scoreAdd;
				turn += hand[i].turnIncrease - 1;

				while (deck.size() && hand[i].cardDraw)
				{
					hand[i].cardDraw--;
					hand.push_back(deck.front());
					deck.pop_front();
				}

				hand.erase(hand.begin() + i);

				changed = true;
			}
		}

		if (!changed)
			break;
	}

	return totalScore;
}



int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);

	for (int nTest = 1; nTest <= T; nTest++)
	{	
		int N;
		cin >> N;

		vector<Card> hand(N);
		rep(i, N)
		{
			cin >> hand[i].cardDraw >> hand[i].scoreAdd >> hand[i].turnIncrease;
		}
		int M;
		cin >> M;
		deque<Card> deck(M);

		rep(i, M)
		{
			cin >> deck[i].cardDraw >> deck[i].scoreAdd >> deck[i].turnIncrease;
		}

		int bestScore = 0;

		for (int i = 0; i <= M; i++)
		{
			int score = getScore(i, hand, deck);
			bestScore = max(bestScore, score);
		}


		printf("Case #%d: %d\n", nTest, bestScore);
		fflush(stdout);
	} 

 
	return 0;
}


