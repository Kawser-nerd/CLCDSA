#include <ctime>
#include <queue>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef pair<int,int> pt;

int n;
vector<pt> p;

void readData()
{
	cin >> n;
    p.resize(n);
    forn(i, n)
    	cin >> p[i].first >> p[i].second;
}

int answer;

typedef map<map<int,int>, int> state;

void solve()
{
	state from;
    from[map<int,int>()] = 0;

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    map<int,int> has;

    forn(i, n)
    {
    	state to;

        int minc = 1 << 30;

        for (state::iterator it = from.begin(); it != from.end(); it++)
        {
        	int col = it->second;
        	minc = min(minc, col);
            map<int,int> way = it->first;

            if (col <= 3)
            forn(j, col)
            {
            	bool fail = false;

                for (int d = -1; d <= 1; d++)
                	if (has[p[i].second + d])
                    {
                    	if (way[p[i].second + d] == j)
                        {
                        	fail = true;
                            break;
                        }
                    }

                if (!fail)
                {
                	map<int,int> next = way;
                    next[p[i].second] = j;
                    if (col <= 3)
                    {
                    if (to.count(next))
                    {
	                    to[next] = min(col, to[next]);
                    }
                    else
    	                to[next] = col;
                    }
                }
            }

            if (to.size() == 0 || col < 3)
            {
                	map<int,int> next = way;
                    next[p[i].second] = col;
                    if (to.count(next))
                    {
	                    to[next] = min(col+ 1, to[next]);
                    }
                    else
    	                to[next] = col + 1;
            }
        }
        from = to;

        if (to.size() == 0)
        {
        	answer = 4;
            return;
        }

    	has[p[i].second]++;
        if (minc >= 4)
        {
        	answer = 4;
            return;
        }
    }

    answer = 1 << 20;

    for (state::iterator it = from.begin(); it != from.end(); it++)
    {
    	answer = min(answer, it->second);
    }
}

int main(int argc, char* argv[])
{
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int beginIndex = atoi(argv[1]);
	int endIndex = atoi(argv[2]);

	int testCount;

	string s;
	getline(cin, s);
	sscanf(s.c_str(), "%d", &testCount);
	
	for (int tt = 1; tt <= testCount; tt++)
	{
		readData();

		if (beginIndex <= tt && tt <= endIndex)
		{
            cerr << "[" << clock() << "]\tRunning test " << tt << " (" << tt - beginIndex + 1 
                << " out of " << endIndex - beginIndex + 1 << ")..." << endl;
            int from = clock();
			
            solve();

            cerr << "\tCompleted in " << clock() - from << " ms." << endl;

			printf("Case #%d: %d", tt, answer);
            printf("\n");
		}
	}

	fclose(stdin);
    fclose(stdout);
	
    return 0;
}
