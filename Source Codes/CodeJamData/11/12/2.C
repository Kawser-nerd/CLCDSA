#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>

using namespace std;

const unsigned long len_unit = 1UL<<50;

struct Status{
  string word;
  int score;
  int dic;
  unsigned long val[26];
  bool operator<(const Status &s)const {
    for(int i=0;i<26;++i){
      if(val[i] < s.val[i]) return true;
      if(val[i] > s.val[i]) return false;
    }
    return false;
  }
};

int N,M;
unsigned long pow27[11];

Status status[10000];

void cal_status(const string &guess)
{
  for(int i=0;i<N;++i){
    Status &cur = status[i];
    unsigned long len = len_unit * cur.word.size();
    cur.val[0] = len;
    for(int j=1;j<26;++j){
      cur.val[j] = len;
      for(int k=0;k<cur.word.size();++k){
        if(guess.rfind(cur.word[k], j-1) != -1) cur.val[j] += (cur.word[k] - 'a' + 1)*pow27[k];
      }
    }
  }
}

void get_score(int dep, int l, int u)
{
  if(dep == 26) return;
  if(status[l].val[dep] != status[u-1].val[dep]) {
    for(int i=l;i<u;++i) {
      if(status[i].val[dep] == status[i].val[dep-1]) ++status[i].score;
    }
    int last = l;
    for(int i=l+1;i<u;++i) {
      if(status[i].val[dep] == status[last].val[dep]) continue;
      get_score(dep+1, last, i);
      last = i;
    }
    get_score(dep+1, last, u);
  }else{
    get_score(dep+1, l, u);
  }
}

void do_case(void)
{

  cin>>N>>M;
  for(int i=0;i<N;++i) {
    cin>>status[i].word;
    status[i].dic = i;
  }

  for(int i=0;i<M;++i) {
    string guess;
    cin>>guess;

    for(int i=0;i<N;++i) status[i].score = 0;

    cal_status(guess);
    sort(status, status + N);

    int last = 0;
    for(int j=1;j<N;++j){
      if(status[j].val[0] == status[last].val[0]) continue;
      get_score(1, last, j);
      last = j;
    }
    get_score(1, last, N);

    int max = 0;
    int max_idx;
    for(int i=0;i<N;++i){
      if(status[i].score > max) {
        max = status[i].score;
        max_idx = i;
      }else if(status[i].score == max && status[i].dic < status[max_idx].dic) {
        max_idx = i;
      }
    }
    cout<<' '<<status[max_idx].word;
  }
  cout<<'\n';
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  pow27[0] = 1;
  for(int i=1;i<11;++i){
    pow27[i] = pow27[i-1]*27;
  }

  int cases;
  cin>>cases;
  int i = 1;
  do{
    printf("Case #%d:", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
