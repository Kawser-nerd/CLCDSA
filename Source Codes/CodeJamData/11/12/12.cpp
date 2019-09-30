#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

void solve();

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    cout<<"Case #"<<i+1<<":";
    solve();
    cout<<'\n';
  }
}

string best(const vector<string>& dictionary,const string& list);

void solve(){
  int words,lists;
  cin>>words>>lists;
  vector<string> dictionary(words);
  for(int w=0;w<words;w++)
    cin>>dictionary[w];
  for(int i=0;i<lists;i++){
    string list;
    cin>>list;
    cout<<' '<<best(dictionary,list);
  }
}

map<string,int> count(const vector<string>& v);
string reveal(const string& word,char letter,const string& appearance);

string best(const vector<string>& dictionary,const string& list){
  vector<string> appearance(dictionary.size());
  vector<int> points(dictionary.size());
  for(int i=0;i<dictionary.size();i++)
    appearance[i]=string(dictionary[i].size(),' ');
  map<string,int> appearance_count=count(appearance);
  for(int i=0;i<list.size();i++){
    vector<string> next_appearance(appearance.size());
    for(int d=0;d<dictionary.size();d++)
      next_appearance[d]=reveal(dictionary[d],list[i],appearance[d]);
    map<string,int> next_appearance_count=count(next_appearance);
    for(int d=0;d<dictionary.size();d++)
      if(appearance[d]==next_appearance[d] && appearance_count[appearance[d]]!=next_appearance_count[appearance[d]])
        points[d]++;
    swap(appearance,next_appearance);
    swap(appearance_count,next_appearance_count);
  }
  int best_points=-1;
  string ret;
  for(int d=0;d<dictionary.size();d++)
    if(points[d]>best_points){
      best_points=points[d];
      ret=dictionary[d];
    }
  return ret;
}

map<string,int> count(const vector<string>& v){
  map<string,int> ret;
  for(int d=0;d<v.size();d++)
    ret[v[d]]++;
  return ret;
}

string reveal(const string& word,char letter,const string& appearance){
  string ret=appearance;
  for(int i=0;i<word.size();i++)
    if(word[i]==letter)
      ret[i]=letter;
  return ret;
}
