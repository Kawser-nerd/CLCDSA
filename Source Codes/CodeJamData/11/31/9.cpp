#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <algorithm>
#include <functional>
#include <fstream>
#include <numeric>
#include <string>
#include <valarray>


using namespace std;

int main(){
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    int n,m;
    cin>>n>>m;
    vector<string> all;
    for (int i=1;i<=n;i++){
      string temp;
      cin>>temp;
      all.push_back(temp);
    }
    for (int i=0;i+1<all.size();i++)
      for (int j=0;j+1<all[i].size();j++)
	if (all[i  ][j] == '#' && all[i  ][j+1] == '#' &&
	    all[i+1][j] == '#' && all[i+1][j+1] == '#'){
	  all[i][j]='/';
	  all[i][j+1]='\\' ;
	  all[i+1][j]='\\';
	  all[i+1][j+1]='/';
	}
    bool bad=false;
    for (int i=0;i<all.size();i++)
      for (int j=0;j<all[i].size();j++)
	bad |= all[i][j] == '#';
    if (bad)
      cout<<"Case #"<<ccount<<":"<<endl<<"Impossible"<<endl;
    else{
      cout<<"Case #"<<ccount<<":"<<endl;
      for (int i=0;i<all.size();i++)
	cout<<all[i]<<endl;
    }
  }
}
