#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>

#define FOR(x,a,b) for(int x=(a); x<(b); x++)
#define FI(b) FOR(i,0,b)
#define FJ(b) FOR(j,0,b)
#define FK(b) FOR(k,0,b)
#define FC(b) FOR(c,0,b)
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin(); it!=v.end(); it++)

using namespace std;

map<string,vector<string> > tree;
int ans=0;

int go(string node) {
    
    vector<string> children = tree[node];

    vector<int> v;
    for(int i=0; i < children.size(); i++) {
        if (tree.count(children[i])) {
            // Is a mixture
            v.push_back(go(children[i]));
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ret = 1;
    for(int i=0; i<v.size(); i++) {
        ret >?= v[i] + i;
        ans >?= v[i] + i + 1;
    }

    ans >?= ret;
//cout << node << " " << ret<<endl;
    return ret;
}

int main() {
	int cases;
	cin >> cases;
	FC(cases) {
        int mixN;
        cin >> mixN;

        tree.clear();
        vector<string> mixes;
        set<string> notRoot;
        for(int i=0; i<mixN; i++) {
            string mixName;
            cin >> mixName;
            mixes.push_back(mixName);

            int children = 0;
            cin >> children;
            FJ(children) {
                string child;
                cin >> child;
                tree[mixName].push_back(child);
                notRoot.insert(child);
            }
        }

        string root = "";
        FI(mixes.size()) {
            if (notRoot.count(mixes[i]) == 0) {
                if (root != "") cout << "BAD"<<endl;
                root = mixes[i];
                break;
            }
        }

        ans=0;
        go(root);
        cout << "Case #" << (c+1) << ": " << ans<<endl;
	}
}
