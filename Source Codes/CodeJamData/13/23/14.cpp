#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int mem[5][4001];

int main(){
	int T; cin >> T;
	vector<string> vs;
	ifstream fin("garbled_email_dictionary.txt");
	string str;
	while(fin >> str) vs.push_back(str);
	for(int test=1;test<=T;test++){
		memset(mem, -1, sizeof(mem));
		mem[4][0] = 0;
		cin >> str;
		for(int i=0;i<str.size();i++){
			for(int j=0;j<vs.size();j++){
				int first = 1000, last = -100;
				int cnt = 0;
				bool ok = true;
				if(i+vs[j].size() > str.size()) continue;
				for(int k=0;k<vs[j].size();k++){
					if(vs[j][k] != str[i+k]){
						cnt++;
						if(last == -100) first = k;
						else if(k-last < 5){ ok = false; break; }
						last = k;
					}
				}
				if(!ok) continue;
				for(int k=0;k<5;k++){
					if(mem[k][i] == -1) continue;
					if(first < 4-k) continue;
					int nm = min(4, last != -100 ? (int)vs[j].size()-1-last : k+(int)vs[j].size());
					int np = i+vs[j].size();
					if(mem[nm][np] == -1) mem[nm][np] = mem[k][i] + cnt;
					else                  mem[nm][np] = min(mem[nm][np], mem[k][i]+cnt);
				}
			}
		}
		int res = 1000000;
		for(int i=0;i<5;i++){
			if(mem[i][str.size()] == -1) continue;
			res = min(res, mem[i][str.size()]);
		}
		printf("Case #%d: %d\n", test, res);
	}
}
