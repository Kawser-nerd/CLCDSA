#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <cmath>
#include <sstream>
#include <set>  

using namespace std;

int main()
{
	int n, a;
	set<int> st;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		st.insert(a);
		
	}

	cout << n - st.size() << endl;
	return 0;
}