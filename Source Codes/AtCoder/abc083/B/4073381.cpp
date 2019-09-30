#include <iostream>
using namespace std;

int N;
int A;
int B;

int main() {
  cin >> N >> A >> B;
  int sum = 0;

  for (int i = 1; i <= N; i++) {
    int num = i;
    int sumOfEachDigit = 0;
    while (num != 0) {
      sumOfEachDigit += (num % 10);
      num /= 10;
    }

    if (A <= sumOfEachDigit && sumOfEachDigit <= B) {
      sum += i;
    }
  }

  cout << sum << endl;
  return 0;
}