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
    int prev,current;
    int magic = 0;
    int N;
    cin>>N;

    cin>>prev;

    for(int i = 1;i < N;i++) {
        cin>>current;
        if(prev == current) {
            magic++;
            prev = -1;
        } else {
            prev = current;
        }
    }

    cout<<magic<<endl;

    return 0;
}