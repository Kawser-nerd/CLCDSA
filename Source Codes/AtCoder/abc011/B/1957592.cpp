#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
using namespace std;
 
int main()
{
	string S;
 
	cin >> S;
	
	transform(S.begin(), S.end(), S.begin(), ::tolower);
	S[0] = toupper(S[0]);
 
	cout << S << endl;
 
	return 0;
}