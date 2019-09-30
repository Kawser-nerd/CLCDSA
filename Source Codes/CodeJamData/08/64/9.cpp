#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;
typedef long long LL;

int main()
{
	int NC; cin >> NC;
	for(int ID=1; ID<=NC; ++ID)
	{
		cout << "Case #" << ID << ": ";

		set< pair<int,int> > connL;
		int N; cin>>N;
		for(int i=0; i<N-1; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			connL.insert( make_pair(a,b) );
			connL.insert( make_pair(b,a) );
		}

		set< pair<int,int> > connS;
		int M; cin>>M;
		for(int i=0; i<M-1; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			connS.insert( make_pair(a,b) );
			connS.insert( make_pair(b,a) );
		}

		bool success = false;
		vector<int> e(N);
		for(int i=0; i<N; ++i) e[i]=i;
		do {
			for(int i=0; i<M; ++i)
			for(int j=0; j<M; ++j)
				if( connS.count(make_pair(i,j)) != connL.count(make_pair(e[i],e[j])) )
					goto Fail;
			success = true;
			break;
		Fail:;
		} while( next_permutation(e.begin(), e.end()) );

		cout << (success ? "YES" : "NO") << endl;
	}
}
