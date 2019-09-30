#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<long long int> power;
long long int INF = 10000000000;
int COUNT = 0;

bool check();

void display(){
  for(int i = 0; i < power.size(); i++){
    cout << power[i] << " ";
  }
  cout << endl;
}

int getMaxIndex(){
  int max = 0;
  int index = 0;
  for(int i = 0; i < power.size(); i++){
    if(max < power[i]){
      max = power[i];
      index = i;
    }
  }
  return index;
}

void attack(int A, int B, long long int &count){
  int MaxIndex = getMaxIndex();
  for(int i = 0; i < power.size(); i++){
    if(i == MaxIndex) power[i] -= A;
    else power[i] -= B;
  }
  bool flag = check();
  if(flag){
    cout << count << endl;
    return;
  }
  else{
    count++;
    attack(A, B, count);
  }
}

bool check(){
  bool flag = true;
  for(int i = 0; i < int(power.size()); i++){
    if(power[i] > 0){
      flag = false;
      break;
    }
  }
  return flag;
}

bool enough(long long int T, int A, int B){
  long long int damage = T * B;
  bool flag = true;
  long long int add_num = 0;
  for(int i = 0; i < power.size(); i++){
    if(power[i] > damage){
      long long int tmp = long((power[i] - damage) / (A - B));
      add_num += tmp;
      if((power[i] - damage) % (A - B) != 0) add_num++;
    }
  }
  if(add_num > T) flag = false;
  
  return flag;
}

void calcT(int A, int B, long long int s, long long int e){
  long long int T = (s + e) / 2;
  //cout << "T = " << T << endl;
  if(s + 1 >= e){
    cout << T + 1 << endl;
    return;
  }
  if(enough(T, A, B)){
    long long int new_s = s;
    long long int new_e = T;
    calcT(A, B, new_s, new_e);
  }
  else{
    long long int new_s = T;
    long long int new_e = e;
    calcT(A, B, new_s, new_e);
  }
}

int main(){
  long long int N, A, B;
  cin >> N >> A >> B;
  for(int i = 0; i < N; i++){
    long long int tmp;
    cin >> tmp;
    power.push_back(tmp);
  }

  calcT(A, B, 0, INF);

  return 0;
}