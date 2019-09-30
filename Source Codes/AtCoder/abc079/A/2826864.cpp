#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
	string s;
	cin >> s;
	if ((s[0]==s[1] && s[1]==s[2]) || (s[1]==s[2] && s[2]==s[3])) cout << "Yes" << endl;
	else cout << "No" << endl;
}