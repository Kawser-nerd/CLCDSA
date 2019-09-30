#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  int temp = 0;
  while(cases--){
    cout << "Case #" << ++temp << ": ";
    int n;
    cin >> n;
    map<string,int> dic;
    vector<int> score(n,0);
    int id = 0;
    string dummy;
    getline(cin,dummy);
    for(int i=0;i<n;i++){
      string s;
      getline(cin,s);
      dic[s] = id++;
    }
    int m;
    cin >> m;
    getline(cin,dummy);
    for(int i=0;i<m;i++){
      string ss;
      getline(cin,ss);
      int cur = dic[ss];
      vector<int> next(n, 10000);
      for(int j=0;j<n;j++){
	if(score[j] != 10000){
	  if(j == cur){
	    for(int k=0;k<n;k++){
	      if(k==cur)continue;
	      next[k] = min(next[k], score[j]+1);
	    }
	  } else {
	    next[j] = min(next[j], score[j]);
	  }
	}
      }
      score = next;
    }
    int minimum = 10000;
    for(int i=0;i<n;i++){
      minimum = min(minimum, score[i]);
    }
    cout << minimum << endl;
  }
  return 0;
}
