#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int c;
    cin >> c;
    for (int xx = 1; xx <= c; ++xx)
    {
	int n, m;
	cin >> n >> m;
	vector<int> t(m), v(m), o(n);
	vector<list<int> > z(n);
	list<int> q;
	for (int k = 0; k < n; ++k)
	    o[k] = 0;
	for (int i = 0; i < m; ++i) {
	    cin >> t[i];
	    v[i] = -1;
	    for (int j = 0; j < t[i]; ++j) {
		int x, y;
		cin >> x >> y;
		if (y == 1)
		    v[i] = x - 1;
		else
		    z[x - 1].push_back(i);
	    }
	    if (v[i] != -1) --t[i];
	    if (t[i] == 0) q.push_back(i);
	}
	while (!q.empty()) {
	    int i = q.front();
	    q.pop_front();
	    int x = v[i];
	    if (x == -1) goto impossible;
	    if (o[x]) continue;
	    o[x] = true;
	    for (typeof(z[x].begin()) j = z[x].begin(); j != z[x].end(); ++j)
		if (--t[*j] == 0) q.push_back(*j);
	}
	cout << "Case #" << xx << ":";
	for (int k = 0; k < n; ++k)
	    cout << ' ' << o[k];
	cout << endl;
	continue;
    impossible:
	cout << "Case #" << xx << ": IMPOSSIBLE\n";
    }
    return 0;
}
