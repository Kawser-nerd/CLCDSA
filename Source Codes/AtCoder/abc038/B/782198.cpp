#include <iostream>
#include <map>
using namespace std;
int main(void){
map<int,bool>memo;
int a,b;
cin >> a>>b;
memo[a]=true;
memo[b] = true;
cin>>a>>b;
cout << (memo[a]||memo[b]?"YES":"NO")<<endl;
}