#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#include<functional>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;
typedef pair<int,int> miria;

map<int , int> akagi;

int main(){
  int s,count=1;
  cin >> s;
  for(int i=1;i<=100;i++){
    akagi[i]=0;
  }
  akagi[s]++;
  while(akagi[s]!=2){
    if(s%2==0){
      s /= 2;
    }else{
      s = 3*s+1;
    }
    akagi[s]++;
    count++;
  }
  cout << count << endl;
  return 0;
}