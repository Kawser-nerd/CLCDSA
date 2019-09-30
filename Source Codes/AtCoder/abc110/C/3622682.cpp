#define _CRT_SECURE_NO_WARNINGS
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
#include <climits>
#include <cstdlib>
#include <cstring>
#include <map>
#include <ctime>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 100001
#define MACRO(a) for(int a = 1; a < 1001; a++)

using namespace std;

int alpha[26];

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	vector<int> vec1, vec2;
	string str; cin >> str;
	for (int i = 0; i < str.size(); i++)
		alpha[str[i] - 'a'] += 1;
	for (int i = 0; i < 26; i++)
		vec1.push_back(alpha[i]);
	for (int i = 0; i < 26; i++)
		alpha[i] = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		alpha[str[i] - 'a'] += 1;
	for (int i = 0; i < 26; i++)
		vec2.push_back(alpha[i]);
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	for (int i = 0; i < vec1.size(); i++)
	{
		if (vec1[i] != vec2[i])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}