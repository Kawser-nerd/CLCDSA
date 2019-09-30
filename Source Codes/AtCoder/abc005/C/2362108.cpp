#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define ARRAY_SIZE 200

int takoyaki[ARRAY_SIZE];

bool search_takoyaki(int customer, int timelimit, int ntakoyaki)
{
  for(int i = 0; i < ntakoyaki; i++) {
    if(takoyaki[i] <= customer && customer <= takoyaki[i] + timelimit) {
      takoyaki[i] = INT_MAX;
      return true;
    }
  }
  return false;
}

int main()
{
  int timelimit;
  int ntakoyaki, ncustomer;
  int customer;

  scanf("%d", &timelimit);
  scanf("%d", &ntakoyaki);
  for(int i = 0; i < ntakoyaki; i++) {
    scanf("%d", &takoyaki[i]);
  }
  scanf("%d", &ncustomer);
  for(int i = 0; i < ncustomer; i++) {
    scanf("%d", &customer);
    if(!search_takoyaki(customer, timelimit, ntakoyaki)) {
      puts("no");
      return 0;
    }
  }
  puts("yes");
  return 0;
}