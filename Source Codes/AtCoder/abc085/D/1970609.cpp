#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

long long int N,H;
vector<long long int> a,b;

int Calc(int d) {
    long long int damage = 0;
    sort(b.begin(),b.end(),greater<long long int>());

    vector<long long int>::iterator it;
    it = max_element(a.begin(),a.end());
    
    for(int i = 0;i < b.size() && b[i] >= *it && H > 0;i++)
    {
        damage++;
        H -= b[i];
    }

    if(H > 0 && H%(*it) != 0)
        damage++;

    if(H > 0)
    damage += H/(*it);
    
    return damage;
}

int main(void) {
    cin>>N>>H;

    for(int i = 0;i < N;i++) {
        int temp1,temp2;
        cin>>temp1>>temp2;
              
        a.push_back(temp1);
        b.push_back(temp2);
    }

    cout<<Calc(H)<<endl;

    return 0;
}