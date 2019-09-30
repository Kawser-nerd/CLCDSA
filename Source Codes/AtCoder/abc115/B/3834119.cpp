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
    int N;
    vector<int> p;
    
    cin>>N;
    
    for(int i = 0;i < N;i++) {
        int temp;
        cin>>temp;
        p.push_back(temp);
    }

    sort(p.begin(),p.end(),greater<int>());

    Int sum = 0;
    sum = p[0]/2;
    for(int i = 1;i < N;i++) {
        sum += p[i];
    }

    cout<<sum<<endl;

    return 0;
}