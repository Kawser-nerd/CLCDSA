#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;


int main(int argc, char **argv) {
  char c;
  int N = 0;
  char first, last;
  while ((c = getc(stdin)) != EOF && (c >= 'a' && c <= 'z')) {
    if (N == 0) first = c;
    N++;
    last = c;
  }

  cout << ( ((N <= 2) || !((first == last) ^ (N & 1)))? "Second" : "First" ) << endl;
  return 0;
}