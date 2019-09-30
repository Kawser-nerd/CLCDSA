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
    #define endl '\n'
    #define ll long long
    #define mod 1000000007
    #define NCONS 201
    #define PLUS 0
    #define MINUS 1
     
    using namespace std;
     
    int main(void)
    {
    	cin.tie(NULL); ios_base::sync_with_stdio(false);
     
    	string str; cin >> str;
     
    	if ((str[0] == str[1] && str[1] == str[2]) || (str[1] == str[2] && str[2] == str[3]))
    		cout << "Yes";
    	else
    		cout << "No";
     
    	return 0;
    }