#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int T;

	cin >> T;

	for (int t=1;t<=T;t++) {
		int C, D;
		cin >> C >> D;
		vector<pair<int,int> > vs;
		for (int i=0;i<C;i++) {
			int p,v;
			cin >> p >> v;
			vs.push_back(pair<int,int>(p,v));
		}
		sort(vs.begin(),vs.end());

		// now find worst case among all possible subsequences
		double maxdist=0;
		for (unsigned int i=0;i<vs.size();i++) {
			double minp, maxp;
			double nvendors=0;
			minp=vs[i].first;
			for (unsigned int j=i;j<vs.size();j++) {
				nvendors+=vs[j].second;
				maxp=vs[j].first;

				double distrequired=D*(nvendors-1);
				double distmoved=(distrequired-(maxp-minp))/2;
				//cout << distmoved << endl;
				if (maxdist<distmoved) maxdist=distmoved;
			}
		}
		cout << "Case #" << t << ": ";// << maxdist;
		printf("%.2lf",maxdist);
		cout << endl;

	}

	return 0;
}