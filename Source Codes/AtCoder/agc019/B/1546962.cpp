#include <iostream>
using namespace std;

const int N = 1e5+1;
int cnt[2*N];

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    long long l=s.length();
    long long ans=1+(l*(l-1))/2;
    long long cnt[26]={0};
    for(int i=0;i<s.length();i++) cnt[s[i]-'a']++;
    for(int i=0;i<26;i++) ans=ans-(cnt[i]*(cnt[i]-1))/2;
    cout<<ans;
    return 0;
}