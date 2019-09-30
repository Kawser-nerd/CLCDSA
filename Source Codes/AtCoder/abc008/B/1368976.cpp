#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  vector<string> s;
  cin>>n;
  for(int i=0;i<n;i++){
    string tmp;
    cin>>tmp;
    s.push_back(tmp);
  }
  sort(s.begin(),s.end());
  int max=0,count=0;
  string name=s[0];
  for(int i=0;i<n;i++){
    if(s[i]!=s[i+1]){
      if(count>max){
        name=s[i];
        max=count;
        }
        count=0;
      }
      if(s[i]==s[i+1]){
        count++;
      }
    }
  cout<<name<<endl;
  return 0;
}