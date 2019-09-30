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
long long n, k;

int main() {
    ifstream cin("c.inp");
    ofstream cout("c.out");
    std::cin.rdbuf(cin.rdbuf());
    std::cout.rdbuf(cout.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> nTest;
    for(int iTest = 1; iTest <= nTest; iTest++) {
    	cin >> n >> k;
    	long long tmp = n;
    	for(int i = 0; (k >> i + 1) > 0; i++) {
    		if((k >> i & 1) == 0) {
    			tmp /= 2;
    		}
    		else {
    			tmp = (tmp - 1) / 2;
    		}
    	}
    	cout << "Case #" << iTest << ": " << tmp / 2 << " " << (tmp - 1) / 2 << "\n";
    }
    return 0;
}
