#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


struct item {
	double pr;
	string feat;
	int l, r;
	item() { }
	item (double pr, string feat, int l, int r)
		: pr(pr), feat(feat), l(l), r(r)
	{ }
};

vector<item> t;

int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	for (int ttt=0; ttt<ts; ++ttt) {
		int l;
		cin >> l;

		t.clear();
		t.push_back (item (0, "", -1, -1));
		
		string s;
		getline (cin, s);
		string tt;
		for (int i=0; i<l; ++i) {
			getline (cin, s);
			tt += s + ' ';
		}

		vector<int> st;
		st.push_back (0);
		for (size_t i=0; i<tt.length(); ++i)
			if (tt[i] == '(') {
				++i;
				while (tt[i] == ' ')  ++i;
				double pr;
				sscanf (tt.c_str()+i, "%lf", &pr);
				t[st.back()].pr = pr;
				while (tt[i] != ' ' && tt[i] != ')')  ++i;
				while (tt[i] == ' ')  ++i;
				if (tt[i] == ')') {
					t[st.back()] = item (pr, "", -1, -1);
					st.pop_back();
				}
				else {
					string feat;
					while (tt[i] != ' ') {
						feat += tt[i];
						++i;
					}
					while (tt[i] == ' ')  ++i;
					int my = st.back();
					t[my].r = (int) t.size();
					t.push_back (item());
					t[my].l = (int) t.size();
					t.push_back (item());
					t[my].feat = feat;
					st.push_back (t[my].r);
					st.push_back (t[my].l);
					--i;
				}
			}
			else if (tt[i] == ')')
				st.pop_back();

		int n;
		cin >> n;
		getline (cin, s);
		cout << "Case #" << ttt+1 << ":\n";
		for (int i=0; i<n; ++i) {
			string s;
			getline (cin, s);
			istringstream iss (s);
			iss >> s;
			int m;
			iss >> m;
			set<string> fs;
			for (int j=0; j<m; ++j) {
				iss >> s;
				fs.insert (s);
			}
			double pr = 1;
			for (int v=0; ; ) {
				pr *= t[v].pr;
				if (t[v].l == -1)
					break;
				if (fs.count(t[v].feat))
					v = t[v].l;
				else
					v = t[v].r;
			}
			printf ("%.10lf\n", pr);
		}
	}

}
