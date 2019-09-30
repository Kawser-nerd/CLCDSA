#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   if (a+b < c+d) cout << "Right" << endl;
   else if (a+b == c+d) cout << "Balanced" << endl;
   else cout << "Left" << endl;
}