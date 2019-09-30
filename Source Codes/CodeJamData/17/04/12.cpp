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
const int MAXN = 100;
int nTest, n, m, a[MAXN + 9][MAXN + 9], ans;
bool row[MAXN + 9], col[MAXN + 9], dia1[MAXN * 2 + 9], dia2[MAXN * 2 + 9], change[MAXN + 9][MAXN + 9];
vector<tuple<char, int, int> > vAns;

int main() {
    ifstream cin("d.inp");
    ofstream cout("d.out");
    std::cin.rdbuf(cin.rdbuf());
    std::cout.rdbuf(cout.rdbuf());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> nTest;
    for(int iTest = 1; iTest <= nTest; iTest++) {
    	cin >> n >> m;
    	fill(a[0], a[n + 1], 0);
    	fill(change[0], change[n + 1], false);
    	fill(row, row + n + 1, false);
    	fill(col, col + n + 1, false);
    	fill(dia1, dia1 + n * 2, false);
    	fill(dia2, dia2 + n * 2, false);
    	ans = 0;
    	vAns.clear();
    	for(int i = 1; i <= m; i++) {
    		char ch;
    		int x, y;
    		cin >> ch >> x >> y;
    		if(ch == '+') {
    			a[x][y] = 1;
    			dia1[x + y - 1] = true;
    			dia2[x - y + n] = true;
    			ans++;
    		}
    		else if(ch == 'x') {
    			a[x][y] = 2;
    			row[x] = true;
    			col[y] = true;
    			ans++;
    		}
    		else {
    			a[x][y] = 3;
    			row[x] = true;
    			col[y] = true;
    			dia1[x + y - 1] = true;
    			dia2[x - y + n] = true;
    			ans += 2;
    		}
    	}
    	for(int i = 1; i <= n; i++) {
    		for(int j = 1; j <= n; j++) {
    			if(!row[i] && !col[j]) {
    				a[i][j] += 2;
    				change[i][j] = true;
    				row[i] = true;
    				col[j] = true;
    				ans++;
    			}
    		}
    	}
    	for(int i = 1; i <= n; i++) {
    		for(int j = 1; j <= i; j++) {
    			int x = j, y = i - j + 1;
    			if(!dia1[x + y - 1] && !dia2[x - y + n]) {
    				a[x][y]++;
    				change[x][y] = true;
    				dia1[x + y - 1] = true;
    				dia2[x - y + n] = true;
    				ans++;
    			}
    			x = n - j + 1, y = n - i + j;
    			if(!dia1[x + y - 1] && !dia2[x - y + n]) {
    				a[x][y]++;
    				change[x][y] = true;
    				dia1[x + y - 1] = true;
    				dia2[x - y + n] = true;
    				ans++;
    			}
    		}
    	}
    	for(int i = 1; i <= n; i++) {
    		for(int j = 1; j <= n; j++) {
    			if(change[i][j]) {
    				char ch;
    				if(a[i][j] == 1) {
    					ch = '+';
    				}
    				else if(a[i][j] == 2) {
    					ch = 'x';
    				}
    				else {
    					ch = 'o';
    				}
    				vAns.push_back(make_tuple(ch, i, j));
    			}
    		}
    	}
    	cout << "Case #" << iTest << ": " << ans << " " << vAns.size() << "\n";
    	for(int i = 0; i < vAns.size(); i++) {
    		cout << get<0>(vAns[i]) << " " << get<1>(vAns[i]) << " " << get<2>(vAns[i]) << "\n";
    	}
    }
    return 0;
}
