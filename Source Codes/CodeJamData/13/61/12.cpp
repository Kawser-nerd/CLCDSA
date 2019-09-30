#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef long long Int;
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }

Int N, X, C;
Int S[1024], E[1024], T[1024];

Int calc(Int t, Int p)
{
	Int leave = X;
	
	for (int i = 0; i < C; ++i) {
		if (T[i] + E[i] - S[i] < t) {
			continue;
		}
		if (T[i] + E[i] - S[i] == t) {
			if (E[i] % N == p) {
				chmin(leave, t);
			}
			continue;
		}
		
		Int pos, ppos, cur;
		if (T[i] <= t) {
			pos = (S[i] + ((t - T[i]) % N + N) % N) % N;
			ppos = p;
			cur = t;
		} else {
			pos = S[i];
			ppos = (p - (T[i] - t) % N + 2 * N) % N;
			cur = T[i];
		}
		
		if (pos == ppos) {
			chmin(leave, cur - 1);
			continue;
		}

		while (true) {
			if (pos == E[i] % N) {
				cur = X;
				break;
			}
			if ((pos + 1) % N == ppos) break;
			if ((pos + 1) % N == (ppos - 1 + N) % N) break;
			pos = (pos + 1) % N;
			ppos = (ppos - 1 + N) % N;
			++cur;
		}
		
		for (int j = 0; j < C; ++j) {
			if (S[j] == ppos && T[j] == cur) {
				--cur;
				j = -1;
				ppos = (ppos + 1 + N) % N;
			}
		}
		
		chmin(leave, cur);
/*
		Int dist = (ppos - pos + 2 * N) % N;
		
		if ((dist + 1) / 2 <= (E[i] % N - pos + 2 * N) % N) {
			Int stop = (dist - 1) / 2;
			chmin(leave, cur + stop);
		}
		*/
	}
	
	return leave - t;
}

void solve()
{
    cin >> C >> X >> N;
    
    for (int i = 0; i < C; ++i) {
    	cin >> S[i] >> E[i] >> T[i];
    	--S[i]; --E[i];
    	if (S[i] > E[i]) E[i] += N;
    }
    
    Int res = 0;
    for (int x = 0; x <= X; ++x) {
    	for (int i = 0; i < N; ++i) {
    		Int t = calc(x, i);
    		if (res < t) {
				// cerr << "upd: " << x << " " << i << " " << t << endl;
			}
    		chmax(res, t);
    	}
    }
    
    cout << res << endl;
}

int main()
{
    int CASES;
    cin >> CASES;
    
    for (int CASE = 1; CASE <= CASES; ++CASE) {
        cout << "Case #" << CASE << ": ";
        solve();   
    }
    
    return 0;
}


