#include <iostream>
using namespace std;
int v[100001];
int main(){
  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    v[a]++, v[b]++;
  }
  for (int i = 1; i <= N; i++){
    if (v[i]%2){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}