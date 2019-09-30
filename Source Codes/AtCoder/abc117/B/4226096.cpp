#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<functional>
typedef long long ll;
using namespace std;

int main(){
  int N;
  int L[10];
  cin >> N;
  int max=0;
  int index;
  for(int i=0;i<N;i++){
    cin >> L[i];
    if(max<=L[i]){
      max = L[i];
      index = i;
    }
  }
  int sum=0;
  for(int i=0;i<N;i++){
    if(i!=index){
      sum+=L[i];
    }
  }
  if(max<sum){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}