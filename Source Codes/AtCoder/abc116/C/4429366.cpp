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

int N;
int h[102];

bool sum_zero(int m){
  int s=0;
  for(int i=0;i<m;i++){
    s+=h[i];
  }

  return s == 0;
}

int main(){
  int c=0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> h[i];
  }
  h[N] = 0;
  int flag = 0;

  if(sum_zero(N)){
    cout << c << endl;
    return 0;
  }

  while(flag==0){
    int left = 0;
    while(h[left]==0){
      left++;
    }
    int right = left;
    while(h[right]!=0){
      right++;
    }
    //cout << left << " " << right << endl;
    for(int i=left;i<right;i++){
      //cout << "miria" << i << endl;
      h[i]--;
    }
    c++;
    //cout << c << endl;
    if(sum_zero(N)){
      flag = 1;
    }
  }
  cout << c << endl;
  return 0;
}