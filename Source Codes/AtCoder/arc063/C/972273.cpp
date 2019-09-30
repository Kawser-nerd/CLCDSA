#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

struct Node{
    vector<Node*> nodes;
    int mini = -M, maxi = M;
    bool even;
    void propagate(Node* from = nullptr){
        if(mini == -M && !from){ return; }
        auto size = maxi - mini;
        if(mini == -M){
            even = !from -> even;
            mini = from -> mini - 1;
            maxi = from -> maxi + 1;
        }else if(from){
            mini = max(mini, from -> mini - 1);
            maxi = min(maxi, from -> maxi + 1);
            if(even == from -> even || mini > maxi){
                cout << "No" <<endl;
                exit(0);
            }
        }

        if(from && size == maxi - mini){ return; }
        for(Node* n : nodes){
            n -> propagate(this);
        }
    }
    void set(int num){
        mini = maxi = num;
        even = !(num % 2);
    }
    void print(){
        cout << mini << endl;
    }
};

int main(){
	int n, k;
	cin >> n;
    vector<Node> nodes(n);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        nodes[a].nodes.push_back(&nodes[b]);
        nodes[b].nodes.push_back(&nodes[a]);
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int v, p;
        cin >> v >> p;
        v--;
        // nodes[v].cands.insert(p);
        nodes[v].set(p);
    }

    for(int i=0;i<n;i++){
        nodes[i].propagate();
    }

    cout << "Yes" <<endl;
    for(int i=0;i<n;i++){
        nodes[i].print();
    }

	return 0;
}