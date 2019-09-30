#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#include<functional>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  printf("%s\n",b-a==c-b ? "YES" : "NO");
  return 0;
}