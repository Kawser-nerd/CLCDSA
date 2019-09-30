#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

using namespace std;

int dp[501][20];
string i2s(int i) { stringstream str; str << i; return str.str(); }

int main()
{
    int N;
    cin >> N;
    string blah = "welcome to code jam";
    cin.ignore();

    for(int z = 1; z <= N; z++)
    {
	string temp;
	memset(dp, 0, sizeof dp);
	getline(cin, temp);

	for(int i = 0; i <= temp.size(); i++)
	    dp[i][19] = 1;

	for(int i = temp.size() - 1; i >= 0; i--)
	    for(int j = 18; j >= 0; j--)
	    {
		if(temp[i] == blah[j])
		    dp[i][j] += dp[i+1][j+1];
		dp[i][j] += dp[i+1][j];

		dp[i][j] %= 10000;
	    }

	string retVal = i2s(dp[0][0]);
	while(retVal.size() < 4) retVal = "0" + retVal;
	cout << "Case #" << z << ": " << retVal << endl;
    }
}
