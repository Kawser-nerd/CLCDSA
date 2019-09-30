#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}

int main(void) {
    int d;
    cin>>d;

    if(d == 25) {
        cout<<"Christmas"<<endl;
    } else if(d == 24) {
        cout<<"Christmas Eve"<<endl;
    } else if(d == 23) {
        cout<<"Christmas Eve Eve"<<endl;
    } else if(d == 22) {
        cout<<"Christmas Eve Eve Eve"<<endl;
    }

    return 0;
}