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
int nTest;
string a;

int main() {
    ifstream cin("b.inp");
    ofstream cout("b.out");
    std::cin.rdbuf(cin.rdbuf());
    std::cout.rdbuf(cout.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> nTest;
    for(int iTest = 1; iTest <= nTest; iTest++) {
    	cin >> a;
    	for(int i = 1; i < a.size(); i++) {
    		if(a[i] < a[i - 1]) {
    			int j = i;
    			while(j > 0 && a[j] <= a[j - 1]) {
    				j--;
    			}
    			a[j]--;
    			for(int k = j + 1; k < a.size(); k++) {
    				a[k] = '9';
    			}
    			break;
    		}
    	}
    	while(a[0] == '0') {
    		a.erase(a.begin());
    	}
    	cout << "Case #" << iTest << ": " << a << "\n";
    }
    return 0;
}
