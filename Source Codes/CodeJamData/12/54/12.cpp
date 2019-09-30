/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

set<string> s;
map<char,char> m;
map<char,int> out;

char buf[1111];

int main(int argc, char *argv[]){
  int T; 
  m['o'] = '0';
  m['i'] = '1';
  m['e'] = '3';
  m['a'] = '4';
  m['s'] = '5';
  m['t'] = '7';
  m['b'] = '8';
  m['g'] = '9';
  scanf("%d",&T);
  int K;
  REP(t,T){
    scanf("%d",&K);
    scanf("%s",buf);
    int N = strlen(buf);
    s.clear();
    REP(i,N-1){
      string st = "";
      st.push_back(buf[i]);
      st.push_back(buf[i+1]);
      s.insert(st);
      if(m.count(buf[i])){
        st = "";
        st.push_back(m[buf[i]]);
        st.push_back(buf[i+1]);
        s.insert(st);
      }
      if(m.count(buf[i+1])){
        st = "";
        st.push_back(buf[i]);
        st.push_back(m[buf[i+1]]);
        s.insert(st);
      }
      if(m.count(buf[i]) && m.count(buf[i+1])){
        st = "";
        st.push_back(m[buf[i]]);
        st.push_back(m[buf[i+1]]);
        s.insert(st);
      }
    }
    set<string>::iterator it;
    out.clear();
    for(it = s.begin(); it != s.end(); ++it){
      out[(*it)[0]]++;
      out[(*it)[1]]--;
    }
    int add = 0;
    REP(i,26) if(out[i+'a'] > 0) add += out[i+'a'];
    REP(i,10) if(out[i+'0'] > 0) add += out[i+'0'];
    add = max(0,add-1);
    printf("Case #%d: %d\n",t+1,(int)s.size()+1+add);
  }
  return 0;
}
