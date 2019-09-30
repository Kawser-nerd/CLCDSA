#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

typedef unsigned long long Num;
typedef vector<Num> Vec;

int main()
{
	int cases;
	cin >> cases;
	for (int ii = 0; ii<cases; ++ii)
	{
		Num P,K,L;
		cin >> P >> K >> L;
		Vec w;
		for ( Num i = 0 ; i<L; ++i)
		{
			Num fr;
			cin >> fr;
			w.push_back(fr);
		}
		sort(w.begin(),w.end(),greater<Num>());

		Num presses = 0;
		for ( Num i = 0 ; i<L; ++i)
		{
			presses += w[i]*((i)/K+1);
		}

		cout << "Case #" << ii+1 << ": " << presses << endl;
	}
	return 0;
}
