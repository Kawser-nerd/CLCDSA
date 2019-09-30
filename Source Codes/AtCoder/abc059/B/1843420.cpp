#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

int compare(const string& a, const string& b){
    if(a.length() > b.length()){
        return 1;
    }
    if(a.length() < b.length()){
        return -1;
    }
    const int len = a.length();
    for(int i = 0; i < len; i++){
        if(a[i] > b[i]){
            return 1;
        }
        if(a[i] < b[i]){
            return -1;
        }
    }
    return 0;
}

int main(void) {
    string a, b;
    cin >> a >> b;

    int comp = compare(a, b);
    if(comp > 0){
        cout << "GREATER" << endl;
    }else if(comp < 0){
        cout << "LESS" << endl;
    }else{
        cout << "EQUAL" << endl;
    }
    return 0;
}