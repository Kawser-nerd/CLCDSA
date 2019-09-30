#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() {

	int T;

	cin >> T;

	for (int t=1;t<=T;t++) {
		int N;
		vector<double> WP, OWP, OOWP;
		vector<vector<int> > opponents;
		vector<string> rslt;
		cin >> N;

		for (int i=0;i<N;i++) {
			vector<int> olist;
			double wins=0;
			string str;
			cin >> str;
			rslt.push_back(str);
			for (int j=0;j<N;j++) {
				if (str[j]!='.') {
					olist.push_back(j);
					if (str[j]=='1') wins++;
				}
			}
			WP.push_back(wins/olist.size());
			opponents.push_back(olist);
		}
		for (int i=0;i<N;i++) {
			double owp=0;
			for (unsigned int j=0;j<opponents[i].size();j++) {
				char c=rslt[i][opponents[i][j]]; // rslt played against you
				double ngames=opponents[opponents[i][j]].size(); // # games opponent played
				owp+=(WP[opponents[i][j]]*ngames-double(c=='0'))/(ngames-1);
				//cout << WP[opponents[i][j]]*ngames << " " << double(c=='0') << endl;
				//cout << ": " << (WP[opponents[i][j]]*ngames-double(c=='0'))/(ngames-1) << endl;
			}
			OWP.push_back(owp/opponents[i].size());
		}
		for (int i=0;i<N;i++) {
			double oowp=0;
			for (unsigned int j=0;j<opponents[i].size();j++) oowp+=OWP[opponents[i][j]];
			OOWP.push_back(oowp/opponents[i].size());
		}
		cout << "Case #" << t << ":" << endl;
		for (int i=0;i<N;i++) {
			//cout << WP[i] << " " << OWP[i] << " " << OOWP[i] << " " << 0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i] << endl;
			printf("%.12lf\n",0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i]);
		}
	}


	return 0;
}