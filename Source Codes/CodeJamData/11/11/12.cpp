#include <iostream>
#include <cassert>

using namespace std;

bool simple(long long percentage_today,long long percentage_overall,long long most);
bool difficult(long long percentage_today,long long percentage_overall,long long most);

int main(){
  long long t;
  cin>>t;
  for(int i=0;i<t;i++){
    long long percentage_today,percentage_overall,most;
    cin>>most>>percentage_today>>percentage_overall;
    bool possible=difficult(percentage_today,percentage_overall,most);
    if(possible)
      cout<<"Case #"<<i+1<<": Possible\n";
    else
      cout<<"Case #"<<i+1<<": Broken\n";
  }
}

bool simple(long long percentage_today,long long percentage_overall,long long most){
  for(long long today=1;today<=most;today++)
    for(long long wins_today=0;wins_today<=today;wins_today++){
      if(wins_today*100==percentage_today*today);
      else continue;
      bool did_lose_today=percentage_today<100;
      bool did_win_today=percentage_today>0;
      if(did_win_today && percentage_overall==0)
        continue;
      if(did_lose_today && percentage_overall==100)
        continue;

      return true;
    }
  return false;
}

bool percentage_posssible(long long percentage_today,long long percentage_overall);

bool difficult(long long percentage_today,long long percentage_overall,long long most){
  if(!percentage_posssible(percentage_today,percentage_overall))
    return false;

  if(most>100)
    return true;

  for(long long today=1;today<=most;today++)
    for(long long wins_today=0;wins_today<=today;wins_today++){
      if(wins_today*100==percentage_today*today);
      else continue;
      return true;
    }
  return false;
}

bool percentage_posssible(long long percentage_today,long long percentage_overall){
  bool did_lose_today=percentage_today<100;
  bool did_win_today=percentage_today>0;
  if(did_win_today && percentage_overall==0)
    return false;
  if(did_lose_today && percentage_overall==100)
    return false;
  return true;
}
