#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

// Build and provide the list of prime numbers.
class PrimeList {
 public:
  // Construct the list.
  PrimeList(int64_t);
  // Return true if queue is prime.
  bool IsPrime(int);
  // Used to access the vector of prime numbers. 0-indexed.
  int64_t operator[](int);
  // Get the size of prime numbers list.
  int64_t GetSize(void);

 private:
  // number list saved as std::vector. good for sequencial access.
  std::vector<int64_t> vec_;
  // number list saved as std::unordered_set. good for random access.
  std::unordered_set<int64_t> set_;
  // Log of the number which is thrown to constructor.
  int64_t searched_value_;
};

PrimeList::PrimeList(int64_t max) {
  if (max > 1000000) {
    std::cerr << "PrimeList::PrimeList() Error: Size is too large\n";
    std::cerr << "Note: Maximum size is 1000000\n";
    abort();
  }
  searched_value_ = max;
  std::unordered_set<int> searchlist(max);
  for (int i = 2; i <= max; i++) {
    searchlist.insert(i);
  }
  int top = 2;
  while (top <= std::pow(max, 0.5)) {
    // cout << top << endl;
    vec_.push_back(top);
    set_.insert(top);
    for (int i = top; i <= max; i += top) {
      searchlist.erase(i);
    }
    for (int i = top + 1; i <= max; i++) {
      if (searchlist.find(i) != searchlist.end()) {
        top = i;
        break;
      }
    }
  }
  for (int i = std::pow(max, 0.5); i <= max; i++) {
    if (searchlist.find(i) != searchlist.end()) {
      vec_.push_back(i);
      set_.insert(i);
    }
  }
}

int64_t PrimeList::operator[](int queue) {
  if (queue >= vec_.size()) {
    std::cerr << "PrimeList::operator[](int) Error: Queue is too large\n";
    std::cerr << "Note: Maximum value is " << vec_.size() - 1 << "\n";
    abort();
  }
  return vec_[queue];
}

bool PrimeList::IsPrime(int queue) {
  if (queue >= searched_value_) {
    std::cerr << "PrimeList::IsPrime(int) Error: Queue is too large\n";
    std::cerr << "Note: Maximum value is " << searched_value_ << "\n";
    abort();
  }
  return (set_.find(queue) != set_.end());
}

int64_t PrimeList::GetSize(void) {
  return vec_.size();
}

void OutputError(std::string s) {
  cerr << "\033[93m" << s << "\033[m" << endl;
  return;
}

int64_t f(int64_t a, int64_t b) {
  cerr << "\033[93m" << a << " " << b << "\033[m" << endl;
  int64_t n  = std::max(a, b);
  int result = 1;
  while (n >= 10) {
    result++;
    n /= 10;
  }
  return result;
}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  PrimeList list(100000);
  int64_t n;
  cin >> n;
  int64_t result = f(n, 1);
  for (int64_t a = 1; a <= std::pow(n, 0.5) + 1; a++) {
    if (n % a == 0) {
      int64_t b = n / a;
      result    = std::min(result, f(a, b));
    }
  }

  cout << result << endl;

  return 0;
}