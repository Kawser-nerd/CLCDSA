#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  int N;
  cin >> N;
  double money = 0;
  for(int i =0; i < N; i++){
    double tmp_d;
    string tmp_s;
    cin >> tmp_d >> tmp_s;
    if(tmp_s == "JPY"){
      money += tmp_d;
    }else{
      money += tmp_d * 380000.0;
    }
  }
  
  cout << money <<endl;
}