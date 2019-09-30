#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <exception>
#include <initializer_list>
#include <locale>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int nTest, k, ans;
string s;

int main() {
    ifstream cin("a.inp");
    ofstream cout("a.out");
    std::cin.rdbuf(cin.rdbuf());
    std::cout.rdbuf(cout.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> nTest;
    for(int iTest = 1; iTest <= nTest; iTest++) {
    	cin >> s >> k;
    	s = ' ' + s;
    	ans = 0;
    	for(int i = 1; i < s.size(); i++) {
    		if(s[i] == '-') {
    			if(i + k > s.size()) {
    				ans = -1;
    				break;
    			}
    			ans++;
    			for(int j = i; j < i + k; j++) {
    				if(s[j] == '-') {
    					s[j] = '+';
    				}
    				else {
    					s[j] = '-';
    				}
    			}
    		}
    	}
    	if(ans == -1) {
    		cout << "Case #" << iTest << ": IMPOSSIBLE\n";
    	}
    	else {
    		cout << "Case #" << iTest << ": " << ans << "\n";
    	}
    }
    return 0;
}
