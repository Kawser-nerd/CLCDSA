#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void insert(vector<string> &cont, string value)
{
    auto it = lower_bound(cont.begin(), cont.end(), value, less<string>());
    cont.insert(it, value);
}

int main()
{
    string str;
    int n;
    cin >> str >> n;

    map<char, vector<int> > d;

    for(int i = 0; i < str.length(); i++) {
        d[str[i]].push_back(i);
    }

    for(auto itr = d.begin(); itr != d.end(); ++itr) {
        vector<string> s;
        //cout << "[" << itr->first << "]";
        for(int x : d[itr->first]) {
            //cout << "[" << x << "]";
            for(int i = x; i < min(x + 5, (int)str.length()); i++) {
                string substr = str.substr(x, i - x + 1);
                //cout << substr << endl;
                if(find(s.begin(), s.end(), substr) == s.end()) {
                    insert(s, substr);
                }
            }
        }
        /*
        for(string x2 : s) {
            cout << x2 << " ";
        }*/
        if(s.size() >= n) {
            cout << s[n - 1];
            return 0;
        } else {
            n -= s.size();
        }
    }

    return 0;
}