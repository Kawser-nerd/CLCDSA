#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int cases;
  cin >> cases;
  int temp = 0;
  while(cases--){
    cout << "Case #" << ++temp << ": ";
    int T;
    int na, nb;
    cin >> T >> na >> nb;
    vector<pair<pair<int,int>,int> > dic;
    string dummy;
    getline(cin,dummy);
    for(int i=0;i<na;i++){
      string s;
      getline(cin,s);
      int from,to;
      from = ((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+s[4]-'0';
      to = ((s[6]-'0')*10+(s[7]-'0'))*60+(s[9]-'0')*10+s[10]-'0';
      dic.push_back(make_pair(make_pair(from,to),0));
    }
    for(int i=0;i<nb;i++){
      string s;
      getline(cin,s);
      int from,to;
      from = ((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+s[4]-'0';
      to = ((s[6]-'0')*10+(s[7]-'0'))*60+(s[9]-'0')*10+s[10]-'0';
      dic.push_back(make_pair(make_pair(from,to),1));
    }
    sort(dic.begin(), dic.end());
    vector<vector<int> > pools(2);
    int a = 0, b = 0;
    for(int i=0;i<na+nb;i++){
      pair<pair<int,int>,int> cur = dic[i];
      int from = dic[i].first.first;
      int to = dic[i].first.second;
      int which = dic[i].second;
      
      int id = -1;
      for(int j=0;j<(int)pools[which].size();j++){
	if(pools[which][j] <= from){
	  id=j;
	}
      }
      if(id==-1){
	if(which==0)a++;
	else b++;
      } else {
	pools[which].erase(pools[which].begin()+id);
      }
      pools[which?0:1].push_back(to+T);
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
