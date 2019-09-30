/*
  regex_dfa
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cctype>
#include<cassert>
#include<map>
#include<queue>
#include<stack>
#include<cstring>
#include<set>
#include<bitset>

/* automaton.h */

#define __AUTOMATON_H__

#define N 55 //a-zA-Zep^$
#define Epsilon -1

struct Automaton{
  std::vector<Automaton*> nextNodes[N]; // a-zA-Zep
  bool endState;

  Automaton();

  void addEdge(int charId, Automaton *next);
};

int isCharacter(char c);
int getId(char c);


/* makeEpsilonNfa.h */

#define __MAKE_EPSILON_NFA_H__

Automaton *make_epsilon_nfa(const char *pattern);


/* makeNfa.h */

#define __MAKE_NFA_H__

Automaton *make_nfa(Automaton* epsilon_nfa);


/* makeDfa.h */

#define __MAKE_DFA_H__

Automaton *make_dfa(Automaton* nfa);


/* automaton.cpp */

Automaton::Automaton():
  endState(false)
{}

void Automaton::addEdge(int charId, Automaton *next){
  assert(0 <= charId && charId < N);
  nextNodes[charId].push_back(next);
  //printf("%lld %lld %d\n", this, next, charId);
}

int isCharacter(char c){
  return  isalpha(c) || c == '^' || c == '$';
}

int getId(char c){
  if(c == Epsilon) return 0;
  if(islower(c)) return c - 'a' + 1;
  if(isupper(c)) return c - 'A' + 1 + 26;
  if(c == '^') return 1 + 26 * 2;
  if(c == '$') return 2 + 26 * 2;

  assert(0);
  return -1;
}

/* makeEpsilonNfa.cpp */

using namespace std;

struct Data{
  Automaton *start;
  Automaton *end;

  Data():start(NULL), end(NULL){}
};

/* ????? */
// char *p = str; res = expr(p);

Data term(const char* &s);
Data character(const char* &s);
Data factor(const char* &s);
Data expr(const char* &s);
Data bracket(const char* &s);

Data star(Data data){
  Data newData;

  newData.start = new Automaton;
  newData.end = new Automaton;

  newData.start->addEdge(getId(Epsilon), newData.end);
  newData.start->addEdge(getId(Epsilon), data.start);
  data.end->addEdge(getId(Epsilon), data.start);
  data.end->addEdge(getId(Epsilon), newData.end);

  return newData;
}

Data question(Data data){
  data.start->addEdge(getId(Epsilon), data.end);
  return data;
}

//??
Data character(const char* &s){
  Data res;

  if(s[0] == '['){
    res = bracket(++s);
    s++;
  }else{
    assert(isCharacter(s[0]));

    res.start = new Automaton;
    res.end = new Automaton;
    res.start->addEdge(getId(s[0]), res.end);
    s++;
  }

  if(s[0] == '*'){
    res = star(res);
    s++;
  }

  if(s[0] == '?'){
    res = question(res);
    s++;
  }

  return res;
}

//???[a-z]
Data bracket(const char* &s){
  Data res, data;

  res.start = new Automaton;
  res.end = new Automaton;

  while(isCharacter(s[0])){
    char l = s[0], r;
    if(s[1] == '-' && s[2] != ']'){
      r = s[2];
      s += 3;
    }else{
      r = s[0];
      s++;
    }

    for(char i=l;i<=r;i++){
      res.start->addEdge(getId(i), res.end);
    }
  }

  assert(s[0] == ']');
  return res;
}

//????(????:?)
Data term(const char* &s){
  Data res = factor(s);

  while(1){
    if(isCharacter(*s) || *s == '(' || *s == '['){
      Data data = factor(s);
      res.end->addEdge(getId(Epsilon), data.start);
      res.end = data.end;
    }else{
      break;
    }
  }
  return res;
}

//????
Data factor(const char* &s){
  if(*s != '(') return character(s);
  Data res = expr(++s); s++;

  if(s[0] == '*'){
    res = star(res);
    s++;
  }

  if(s[0] == '?'){
    res = question(res);
    s++;
  }

  return res;
}

//?(????: ?)
Data expr(const char* &s){
  Data res, data;

  res.start = new Automaton;
  res.end = new Automaton;

  data = term(s);
  res.start->addEdge(getId(Epsilon), data.start);
  data.end->addEdge(getId(Epsilon), res.end);

  while(1){
    if(*s == '|') {
      data = term(++s);
      res.start->addEdge(getId(Epsilon), data.start);
      data.end->addEdge(getId(Epsilon), res.end);
    }else{
      break;
    }
  }
  return res;
}

Automaton *make_epsilon_nfa(const char *pattern) {
  Data data = expr(pattern);
  data.end->endState = true;

  return data.start;
}

/* makeNfa.cpp */

using namespace std;

Automaton *make_nfa(Automaton* ep_nfa){
  map<Automaton*, int> dic;
  vector<Automaton*> nodeList;
  int incrementId = 0;

  queue<Automaton*> que;
  que.push(ep_nfa);
  while(que.size()){
    auto p = que.front(); que.pop();
    if(p && dic.find(p) == dic.end()){

      dic[p] = incrementId++;
      nodeList.push_back(p);

      for(int i=0;i<N;i++)
        for(int j=0;j<p->nextNodes[i].size();j++)
          que.push(p->nextNodes[i][j]);
    }
  }

  bool dp[incrementId][incrementId][N];
  bool used[incrementId];
  memset(dp, 0, sizeof(dp));
  memset(used, 0, sizeof(used));

  for(int i=0;i<incrementId;i++) dp[i][i][getId(Epsilon)] = true;

  que.push(ep_nfa);
  while(que.size()){
    auto p = que.front(); que.pop();
    if(p && !used[dic[p]]){
      used[dic[p]] = true;
      for(int i=0;i<N;i++){
        for(int j=0;j<p->nextNodes[i].size();j++){
          if(p->nextNodes[i][j] != NULL) {
            que.push(p->nextNodes[i][j]);
            dp[dic[p]][dic[p->nextNodes[i][j]]][i] = true;
          }
        }
      }
    }
  }

  for(int k=0;k<incrementId;k++){
    for(int i=0;i<incrementId;i++){
      for(int j=0;j<incrementId;j++){
        for(int c=0;c<N;c++){
          dp[i][j][c] |= dp[i][k][getId(Epsilon)] && dp[k][j][c];
          dp[i][j][c] |= dp[i][k][c] && dp[k][j][getId(Epsilon)];
        }
      }
    }
  }

  for(int i=0;i<incrementId;i++){
    for(int j=0;j<N;j++){
      nodeList[i]->nextNodes[j].resize(0);

      if(j != getId(Epsilon)){
        for(int k=0;k<incrementId;k++){
          if(dp[i][k][j]) nodeList[i]->addEdge(j, nodeList[k]);
        }
      }
    }
  }

  return ep_nfa;
}

/* makeDfa.cpp */

using namespace std;

struct Bit{
  int n;
  vector<bool> bit;

  Bit(int n):n(n),bit(n,false){}

  bool operator< (const Bit &B) const {
    if(n != B.n) return n < B.n;
    return bit < B.bit;
  }
};

Automaton* make_dfa(Automaton *nfa){
  map<Automaton*, int> dic;
  vector<Automaton*> nodeList;
  int incrementId = 0;

  queue<Automaton*> que;
  que.push(nfa);
  while(que.size()){
    auto p = que.front(); que.pop();
    if(p && dic.find(p) == dic.end()){

      dic[p] = incrementId++;
      nodeList.push_back(p);

      for(int i=0;i<N;i++)
        for(int j=0;j<p->nextNodes[i].size();j++)
          que.push(p->nextNodes[i][j]);
    }
  }

  const int n = incrementId;

  map<Bit,int> bitDic;
  int bitDicIncrementId = 0;
  vector<Automaton*> dfaNodeList;
  Bit Sbit(n); Sbit.bit[0] = true;
  Bit initBit(n);

  queue<Bit> que2;
  que2.push(Sbit);
  bitDic[Sbit] = bitDicIncrementId++;
  dfaNodeList.push_back(new Automaton);

  //printf("S: %lld\n", dfaNodeList[0]);

  while(que2.size()){
    auto p = que2.front(); que2.pop();
    int id = bitDic[p];

    for(int i=0;i<N;i++){
      if(i == getId(Epsilon)) continue;
      Bit nextBit(n);
      bool endState = false;
      for(int j=0;j<n;j++){
        if(p.bit[j]){
          for(int k=0;k<nodeList[j]->nextNodes[i].size();k++){
            nextBit.bit[dic[nodeList[j]->nextNodes[i][k]]] = true;
            endState |= nodeList[j]->nextNodes[i][k]->endState;
          }
        }
      }

      if(nextBit.bit == initBit.bit) continue;

      Automaton* nextNode;

      if(bitDic.find(nextBit) == bitDic.end()){
        nextNode = new Automaton;
        //printf("%lld %d 0\n", nextNode, endState);
        nextNode->endState = endState;
        bitDic[nextBit] = bitDicIncrementId++;
        dfaNodeList.push_back(nextNode);
        que2.push(nextBit);
      }else{
        nextNode = dfaNodeList[bitDic[nextBit]];
      }
      dfaNodeList[id]->addEdge(i, nextNode);
    }
  }

  for(int i=0;i<incrementId;i++){
    delete nodeList[i];
  }

  return dfaNodeList[0];
}

/* main.cpp */

using namespace std;

int match(const char *str, const char *pattern) {
  Automaton *ep_nfa = make_epsilon_nfa(pattern);
  Automaton *nfa = make_nfa(ep_nfa);
  Automaton *dfa = make_dfa(nfa);

  int n = strlen(str);
  char *matchstr = (char*)malloc(sizeof(char) * (n + 3));
  strcpy(matchstr+1, str);
  matchstr[0] = '^';
  matchstr[n+1] = '$';
  matchstr[n+2] = '\0';

  for(int i=-1;*matchstr;i++){
    Automaton *pc = dfa;
    const char *sp = matchstr;
    bool flag = true;

    while(*sp){
      if(pc == NULL) {flag = false; break;}
      if(pc->endState) break;
      if(pc->nextNodes[getId(*sp)].size() == 0) {flag = false; break;}
      assert(pc->nextNodes[getId(*sp)].size() == 1);
      pc = pc->nextNodes[getId(*sp)][0];
      sp++;
    }

    if(flag && pc->endState){
      return max(0,i);
    }

    matchstr++;
  }

  return -1;
}

int main(){
  char str[1024],
    pattern[1024] = "[Ii][a-zA-Z]*[Cc][a-zA-Z]*[Tt]";
  
  scanf("%s", str);

  int res = match(str, pattern);

  puts(res != -1 ? "YES" : "NO");
  //printf("res : %d\n", res);

  return 0;
}