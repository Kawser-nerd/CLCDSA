//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;
typedef double rl;

int K, L, S;
string keyboard;
const int AL='Z'-'A'+1;
int cnt[AL];
rl freq[AL];
string target;

void prepare()
{
    for(int i=0; i<AL; i++) cnt[i]=0;
    for(int i=0; i<K; i++) cnt[keyboard[i]-'A']++;
    for(int i=0; i<AL; i++) freq[i]=((rl)cnt[i])/K;
}

bool possible()
{
    for(int i=0; i<L; i++)
	{
        if(cnt[target[i]-'A']==0) return false;
	}
	return true;
}

int target_overlap()
{
    for(int len=L-1; len>=1; len--)
	{
        string sub_pref=target.substr(0, len);
        string sub_suff=target.substr(L-len, len);

        //cout << len << ' ' << sub_pref << ' ' << sub_suff << endl;

        if(sub_pref==sub_suff) return len;
	}
	return 0;
}

int solve_max_occ()
{
    int over=target_overlap();
    //cout << "OVERLAP: " << over << endl;

    return 1 + (S-L)/(L-over);
}

rl solve_expected()
{
    rl prob=1.0;
    for(int i=0; i<L; i++)
	{
		prob*=freq[target[i]-'A'];
	}
	return prob*(S-L+1);
}

rl solve()
{
	prepare();

	if(!possible()) return 0.0;
	else
	{
		int mx=solve_max_occ();
		rl exp=solve_expected();

        //cout << mx << ' ' << exp << endl;
        return mx-exp;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout << setprecision(10);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
	{
        cin >> K >> L >> S;
        cin >> keyboard;
        cin >> target;

		cout << "Case #" << t << ": ";
		cout << solve();
		cout << "\n";
	}

	return 0;
}
