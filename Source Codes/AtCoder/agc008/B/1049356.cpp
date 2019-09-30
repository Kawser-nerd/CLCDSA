#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  vector <int> inputs;
  cin >> N >> K;

  int i;
  int a;
  long long int inputSum = 0;
  for (i = 0; i < N; i++) {
    cin >> a;
    inputSum += (a > 0) ? a : 0;
    inputs.push_back(a);
  }

  long long int whiteloss = 0;
  long long int blackloss = 0;
  for (i = 0; i < K; i++) {
    whiteloss += (inputs[i] > 0) ? inputs[i] : 0;
    blackloss += (inputs[i] < 0) ? -inputs[i] : 0;
  }

  long long int minloss = (whiteloss > blackloss) ? blackloss : whiteloss;
  for (i = 0; i + K < N; i++) {
    whiteloss -= (inputs[i] > 0) ? inputs[i] : 0;
    blackloss -= (inputs[i] < 0) ? -inputs[i] : 0;
    whiteloss += (inputs[i + K] > 0) ? inputs[i + K] : 0;
    blackloss += (inputs[i + K] < 0) ? -inputs[i + K] : 0;
    if (minloss > whiteloss) minloss = whiteloss;
    if (minloss > blackloss) minloss = blackloss;
  }

  cout << inputSum - minloss << endl;

  return 0;
}