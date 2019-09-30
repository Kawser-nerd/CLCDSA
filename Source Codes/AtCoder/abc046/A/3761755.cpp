#include <iostream>
#include <set>
using namespace std;

int main (){
set<int> ans;
for (int i = 0; i < 3; i++) {
int sub;
cin >> sub;
ans.insert(sub);
}
cout <<ans.size() << endl;
}