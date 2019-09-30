#include <cstdio>
#include <iostream>

using namespace std;
#define DEBUG(X) cerr<<__LINE__<<" "<<#X<<": "<<X<<endl;
int main() {
  string S;
  cin >> S;
  printf("%s\n", (S.back()=='T')? "YES":"NO");
}