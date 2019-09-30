#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;


int n;
vector<int> x(0);
queue<int> q;

int gcd(int p, int q){
    if(p < q) swap(p, q); // always p >= q
    if(p%q == 0) return q;
    else return gcd(q, p%q);
}

int main(){
    int a;
    int s, t;
	cin >> n;
    for(int i=0;i<=n;i++){
        cin >> a;
        x.push_back(a);
    }
    sort(x.begin(), x.end());
    for(int i=0;i<n;i++){
        q.push(x[i+1] - x[i]);
    }

    s = q.front();
    q.pop();
    while(q.size()){
        t = q.front();
        q.pop();
        s = gcd(s, t);
    }
    cout << s << endl;

	return 0;
}