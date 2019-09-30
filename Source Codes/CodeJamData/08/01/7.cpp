#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(const vector<string>& S, const vector<string>& Q) // O(QSS + QS|Q[i]|)
{
	vector< vector<bool> > match(Q.size(), vector<bool>(S.size()));
	for(int iq=0; iq!=Q.size(); ++iq)
		for(int is=0; is!=S.size(); ++is)
			match[iq][is] = (Q[iq]==S[is]);

	vector<int> cost(S.size(), 0);
	for(int iq=0; iq!=Q.size(); ++iq)
	{
		vector<int> cost_prev = cost;
		for(int is=0; is!=S.size(); ++is)
			if( match[iq][is] )
			{
				int mincost = 0x7fffffff;
				for(int js=0; js!=S.size(); ++js)
					if( is != js )
						mincost = min(mincost, cost_prev[js]+1);
				cost[is] = mincost;
			}
	}

	return *min_element(cost.begin(), cost.end());
}

int main()
{
	int N; cin >> N;
	for(int i=1; i<=N; ++i)
	{
		string tmp;

		vector<string> s;
		{
			int S; cin >> S; getline(cin, tmp);
			while(S--)
			{
				getline(cin, tmp);
				s.push_back(tmp);
			}
		}

		vector<string> q;
		{
			int Q; cin >> Q; getline(cin, tmp);
			while(Q--)
			{
				getline(cin, tmp);
				q.push_back(tmp);
			}
		}

		cout << "Case #" << i << ": " << solve(s, q) << endl;
	}
}
