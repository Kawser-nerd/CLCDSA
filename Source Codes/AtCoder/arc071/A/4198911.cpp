#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

int main()
{
    int n, length;
    cin >> n;
    string str;
    vector<int> count(26, 0);
    vector<int> num_min(26, 300);
    for (int i=0; i<n; ++i){
        cin >> str;
        length = str.length();
        for (int j=0; j<26; ++j){
            count[j] = 0;
        }
        for (int j=0; j<length; ++j){
            count[str[j] - 'a']++;
        }
        for (int j=0; j<26; ++j){
            num_min[j] = min(num_min[j], count[j]);
        }
    }
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<26; ++i){
        for (int j=0; j<num_min[i]; ++j){
            cout << alphabet[i];
        }
    }
    cout << endl;
    return 0;
}