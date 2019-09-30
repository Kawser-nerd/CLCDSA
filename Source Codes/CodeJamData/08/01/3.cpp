
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void){
	int cases;
	cin >> cases;
	for(int case_no = 1; case_no <= cases; case_no++){
		int S, Q;
		cin >> S;
		vector<string> Ss(S);
		map<string,int> dict;
		string s;
		getline(cin, s);
		for(int i=0; i<S; i++){
			getline(cin, Ss[i]);
			dict[Ss[i]] = i;
		}
		vector<int> tbl(S, 0);
		cin >> Q;
		getline(cin, s);
		int INF = 1000000;
		for(int i=0; i<Q; i++){
			getline(cin, s);
			if(dict.find(s) == dict.end()) continue;
			int id = dict[s];
			int low = INF;
			for(int j=0; j<S; j++)
				if(j != id){
					low = min(low, tbl[j]);
					tbl[j] = min(tbl[j],tbl[id]+1);
				}
			tbl[id] = low+1;
		}
		int ans = INF;
		for(int i=0; i<S; i++)
			ans = min(ans, tbl[i]);
		cout << "Case #" << case_no << ": " << ans << endl;
	}
	return 0;
}
