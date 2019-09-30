#include<iostream>
#include<string>
using namespace std;
int main()
{
	string S;
	int T,numl = 0 ,numr= 0 ,numu = 0 ,numd = 0,numa = 0; 
	int x, y;
	cin >> S >> T;
	 
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'L') numl++;
		else if (S[i] == 'R') numr++;
		else if (S[i] == 'U') numu++;
		else if (S[i] == 'D') numd++;
		else if (S[i] == '?') numa ++;
	}
	x = numl - numr;
	y = numu - numd;
	 
	if (x <= 0) x = 0 - x;
	if (y <= 0) y = 0 - y;
	 
	if (T == 1) cout << x + y + numa << endl ;
	else {
		if (x + y - numa >= 0) cout << x + y - numa << endl;
		else {
			int d = x + y - numa;
			if (d % 2 == 0)cout << 0 << endl;
			else cout << 1 << endl;
		}
	}



	return 0;
}