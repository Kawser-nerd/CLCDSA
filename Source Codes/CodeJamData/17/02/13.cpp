#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

int main()
{
	int T;
	long long int N;
	
	scanf("%d\n", &T);

	REP(t, 1, T)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		cin >> N;
		
		vi d;
		vi e;
		
		while(N)
		{
			d.push_back(N%10);
			N /= 10;
		}
		
		int K = d.size();
		e.resize(K);
		
		for(int i = K-1; i >= 0; i--)
		{
			e[i] = d[i];
			bool ok = true;
			for(int j = i-1; j >= 0; j--)
			{
				if(d[j] < e[i])
				{
					ok = false;
					break;
				}
				else if(d[j] > e[i])
				{
					ok = true;
					break;
				}
			}
			if(!ok)
			{
				e[i]--;
				for(int j = i-1; j >= 0; j--) e[j] = 9;
				break;
			}
		}
		bool start = false;
		for(int i = K-1; i >= 0; i--)
		{
			if(start || e[i])
			{
				cout << e[i];
				cerr << e[i];
				start = true;
			}
		}
		cerr << endl;
		cout << endl;
	}
	
	return 0;
}
