/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
in(string a, b)
string s << a + b
x << stoi(s)
for(i in (1~sqrt(x))){
    if(i*i==x) yes() return 0
}
no()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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

;;

int main(){
  ;;
    string a, b;
    cin >> a >> b;
    ;
    string s = a + b;;
    int x = stoi(s);;
    if(1<sqrt(x)){;
        for(int i = 1; i <= sqrt(x); ++i){;;;
        if(i*i==x) {;cout << "Yes" << endl; return (0);};
    }
    ;}
    else {;
        for(int i = 1; i >= sqrt(x); --i){;;;
        if(i*i==x) {;cout << "Yes" << endl; return (0);};
    }
    ;};;;;
    cout << "No" << endl;;
}