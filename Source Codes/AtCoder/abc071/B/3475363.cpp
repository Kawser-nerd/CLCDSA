#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <unordered_set>
#include <cmath>
#define endl '\n'
#define ll long long
//#define mod 1000000007
#define NCONS 100001

using namespace std;

int alpha[26];

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++)
		alpha[str[i] - 'a'] += 1;
	for (int i = 0; i < 26; i++)
		if (alpha[i] == 0)
		{
			cout << (char)(i + 'a');
			return 0;
		}
	cout << "None";

	return 0;
}