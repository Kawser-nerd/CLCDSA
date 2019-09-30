
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int tbl[24*60+10][2];

int timeToInt(string s){
	return ((s[0]-'0')*10 + s[1]-'0')* 60 +
		(s[3]-'0')*10 + (s[4]-'0');
}

int main(void){
	int cases;
	cin >> cases;
	for(int case_no = 1; case_no <= cases; case_no++){
		memset(tbl, 0x00, sizeof(tbl));
		int delay, n[2];
		cin >> delay >> n[0] >> n[1];
		for(int i=0; i<2; i++)
			for(int j=0; j<n[i]; j++){
				string s1, s2;
				cin >> s1 >> s2;
				int t1 = timeToInt(s1);
				int t2 = timeToInt(s2);
				t2 += delay;
				tbl[t1][i]--;
				tbl[t2][1-i]++;
			}
		int ans[2] = {0,0};
		int cur[2] = {0,0};
		for(int t=0; t<24*60; t++){
			for(int i=0; i<2; i++){
				cur[i] += tbl[t][i];
				if(cur[i] < 0){
					ans[i] += -cur[i];
					cur[i] = 0;
				}
			}
		}
		cout << "Case #" << case_no << ": " << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}
