#include <stdio.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <assert.h> 
#include <map>
#include <set> 
#include <vector> 
#include <string> 
#include <algorithm> 
using namespace std; 

typedef long long ll; 

#define modp(x) (((x)%P+P)%P) 
#define mod(x,y) (((x)%(y)+(y))%(y)) 

set<vector<long long> > visited;

char board[70][70];

vector<long long> finish;

bool lucky;

int tate,yoko;


void saiki(vector<long long>& state){
  if(visited.count(state)>0)return;
  if(state==finish)lucky=true;
  visited.insert(state);
  {
    vector<long long> newstate(tate);
    for(int i=0;i<tate;i++){
      for(int j=0;j<yoko;j++){
	if(board[i][j]=='.'){
	  if(((state[i]>>j)&1) && board[i][j+1]=='#')newstate[i]|=(1LL<<j);
	  else if(((state[i]>>(j-1))&1))newstate[i]|=(1LL<<j);
	}
      }
    }
    saiki(newstate);
  }
  {
    vector<long long> newstate(tate);
    for(int i=0;i<tate;i++){
      for(int j=0;j<yoko;j++){
	if(board[i][j]=='.'){
	  if(((state[i]>>j)&1) && board[i][j-1]=='#')newstate[i]|=(1LL<<j);
	  else if(((state[i]>>(j+1))&1))newstate[i]|=(1LL<<j);
	}
      }
    }
    saiki(newstate);
  }
  {
    vector<long long> newstate(tate);
    for(int i=0;i<tate;i++){
      for(int j=0;j<yoko;j++){
	if(board[i][j]=='.'){
	  if(((state[i]>>j)&1) && board[i+1][j]=='#')newstate[i]|=(1LL<<j);
	  else if(((state[i-1]>>(j))&1))newstate[i]|=(1LL<<j);
	}
      }
    }
    saiki(newstate);
  }
}

main(){
  int testcases;
  scanf("%d",&testcases);
  for(int casenum=1;casenum<=testcases;casenum++){
    scanf("%d%d ",&tate,&yoko);
    for(int i=0;i<tate;i++)gets(board[i]);
    int ci[10],cj[10];
    int cavecnt=0;
    for(int i=0;i<tate;i++){
      for(int j=0;j<yoko;j++){
	if(board[i][j]>='0' && board[i][j]<='9'){
	  int dig=board[i][j]-'0';
	  ci[dig]=i;
	  cj[dig]=j;
	  cavecnt++;
	  board[i][j]='.';
	}
      }
    }
    printf("Case #%d:\n",casenum);
    for(int cave=0;cave<cavecnt;cave++){
      vector<long long> state(tate);
      state[ci[cave]]=(1LL<<cj[cave]);
      finish=state;
      for(;;){
	bool modified=false;
	for(int i=0;i<tate;i++){
	  for(int j=0;j<yoko;j++){
	    if((state[i]>>j)&1){
	      if(board[i][j-1]=='.' && !((state[i]>>(j-1))&1)){state[i]|=(1LL<<(j-1));modified=true;}
	      if(board[i][j+1]=='.' && !((state[i]>>(j+1))&1)){state[i]|=(1LL<<(j+1));modified=true;}
	      if(board[i-1][j]=='.' && !((state[i-1]>>(j))&1)){state[i-1]|=(1LL<<(j));modified=true;}
	    }
	  }
	}
	if(!modified)break;
      }
      int cnt=0;
      for(int i=0;i<tate;i++)cnt+=__builtin_popcount(state[i]);
      visited.clear();
      lucky=false;
      saiki(state);
      printf("%d: %d %s\n",cave,cnt,lucky?"Lucky":"Unlucky");
    }
  }
}
