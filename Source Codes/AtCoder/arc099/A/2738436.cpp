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
    int N,K;
    vector<int> A;
    cin>>N>>K;
    for(int i = 0;i < N;i++) {
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    
    N--;
    int count = 0;
    while(N>0) {
        count++;
        N = N-(K-1);
    }

    cout<<count<<endl;

    return 0;
}