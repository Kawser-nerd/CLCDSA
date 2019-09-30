#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define AN 26

int to_number(string s){
    int len = s.size();
    int sum = 0;  
    for(int i = 0; i < s.size() && i < 5; i++){
        sum += (s[i] - 'a' + 1) * pow(AN + 1, 4 - i);
    }
    return sum;
}

string _to_string(int n){
    string s = "";
    for(int i = 0; i < 5; i++){
        if(1 <= n % (AN + 1) && n % (AN + 1) <= 26){
            s.push_back(char(n % (AN + 1) + 'a' - 1));
        }
        n = n / (AN + 1);
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(void){
    string s;
    int K;
    cin >> s;
    scanf("%d", &K);

    vector<int> v;
    for(int i = 0; i < s.size(); i++){
        for(int j = 1; j <= 5; j++){
            if(i + j <= s.size())
                //cout << to_number(s.substr(i, j)) << endl;
                v.push_back(to_number(s.substr(i, j)));
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    /*
    for(int i = 0; i < 5; i++){
        cout << _to_string(v[i]) << endl;
    }
    */

    cout << _to_string(v[K - 1]) << endl;


    return 0;
}