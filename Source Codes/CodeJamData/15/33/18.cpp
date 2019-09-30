//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

const int MAX=111;

int D;
ll C, V;
ll have[MAX];

int solve()
{
	sort(have, have+D);
    ll sum=0;
    int result=0;

	int iter_have=0;
    if(have[0]==1)
	{
		iter_have++;
	}
	else
	{
        result++;
	}
	sum+=1;

	//for(int i=0; i<D; i++) cout << have[i] << endl;

    while(C*sum < V)
	{
		//cout << result << ' ' << sum << endl;

        if(iter_have < D && have[iter_have]<= C*sum + 1LL)
		{
			//cout << "Taking from stack: " << have[iter_have] << endl;

            sum+=have[iter_have];
            iter_have++;
		}
		else
		{
			result++;

			//cout << "Taking new: " << C*sum+1 << endl;
            sum+=(C*sum+1LL);
		}
	}

	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
	{
        cin >> C >> D >> V;
        for(int i=0; i<D; i++) cin >> have[i];

		cout << "Case #" << t << ": ";
		cout << solve();
		cout << "\n";
	}

	return 0;
}
