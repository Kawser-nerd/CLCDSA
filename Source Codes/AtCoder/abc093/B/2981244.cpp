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
   ;
    //???????;;
    //ABC076-A;;
    ;;
    int a, b, k;;;
    cin >> a >> b >> k;;;
    ;;
    vector<int> klst;;;
    if(0<k-1){;;;
        for(int i = 0; i <= k-1; ++i){;;;
        bool flg = true;;;
        if(a+i<=b){;;;
            for(int j = 1; j <=  klst.size(); ++j){;;
    int val_0_ = klst[j-1]; if(val_0_==a+i){ flg = false; break;;};;}
            if(flg){ cout << (a+i) << endl;; klst.push_back(a+i);;;}
        ;};;
    ;};;
    ;;}
    else {;;;
        for(int i = 0; i >= k-1; --i){;;;
        bool flg = true;;;
        if(a+i<=b){;;;
            for(int j = 1; j <=  klst.size(); ++j){;;
    int val_1_ = klst[j-1]; if(val_1_==a+i){ flg = false; break;;};;}
            if(flg){ cout << (a+i) << endl;; klst.push_back(a+i);;;}
        ;};;
    ;};;
    ;;};;
    if(k-1<0){;;;
        for(int i = k-1; i <= 0; ++i){;;;
        bool flg = true;;;
        if(b-i>=a){;;;
            for(int j = 1; j <=  klst.size(); ++j){;;
    int val_2_ = klst[j-1]; if(val_2_==b-i){ flg = false; break;;};;}
            if(flg){ cout << (b-i) << endl;; klst.push_back(b-i);;;}
        ;};;
    ;};;
    ;;}
    else {;;;
        for(int i = k-1; i >= 0; --i){;;;
        bool flg = true;;;
        if(b-i>=a){;;;
            for(int j = 1; j <=  klst.size(); ++j){;;
    int val_3_ = klst[j-1]; if(val_3_==b-i){ flg = false; break;;};;}
            if(flg){ cout << (b-i) << endl;; klst.push_back(b-i);;;}
        ;};;
    ;};;
    ;;};;
}