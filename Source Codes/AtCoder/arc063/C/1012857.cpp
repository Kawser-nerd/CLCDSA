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
    void dfs(Node* from = nullptr){
        for(Node* n : nodes){
            if(n == from){ continue; }
            n -> dfs(this);
            mini = max(mini, n -> mini - 1);
            maxi = min(maxi, n -> maxi + 1);
        }
    }
    void dfs2(Node* from = nullptr){
        for(Node* n : nodes){
            if(n == from){ continue; }
            n -> mini = max(n -> mini, mini - 1);
            n -> maxi = min(n -> maxi, maxi + 1);
            n -> dfs2(this);
        }
    }
    bool judge(Node* from = nullptr, bool fb = false){
        if(mini > maxi){ return false; }
        even = mini % 2 == 0;
        if(from && fb == even){
            return false;
        }
        for(Node* n : nodes){
            if(n == from){ continue; }
            if(!n -> judge(this, even)){
                return false;
            }
        }
        return true;
    }
    // void propagate(Node* from = nullptr){
    //     if(mini == -M && !from){ return; }
    //     auto size = maxi - mini;
    //     if(mini == -M){
    //         even = !from -> even;
    //         mini = from -> mini - 1;
    //         maxi = from -> maxi + 1;
    //     }else if(from){
    //         mini = max(mini, from -> mini - 1);
    //         maxi = min(maxi, from -> maxi + 1);
    //         if(even == from -> even || mini > maxi){
    //             cout << "No" <<endl;
    //             exit(0);
    //         }
    //     }
    //
    //     if(from && size == maxi - mini){ return; }
    //     for(Node* n : nodes){
    //         n -> propagate(this);
    //     }
    // }
    void set(int num){
        mini = maxi = num;
        even = !(num % 2);
    }
    void print(){
        cout << mini << '\n';
        // printf("%d\n", mini);
    }
};
// struct Node{
//     vector<Node*> nodes;
//     // int num = -1;
//     set<int> cands;
//     void propagate(Node* from = nullptr){
//         if(cands.empty() && !from){ return; }
//         auto size = cands.size();
//         if(cands.empty()){
//             for(int i : from -> cands){
//                 cands.insert(i + 1);
//                 cands.insert(i - 1);
//             }
//         }else if(from){
//             set<int> cand2;
//             for(int i : from -> cands){
//                 if(cands.count(i + 1)){ cand2.insert(i + 1); }
//                 if(cands.count(i - 1)){ cand2.insert(i - 1); }
//             }
//             if(cand2.empty()){
//                 cout << "No" <<endl;
//                 exit(0);
//             }
//             cands.swap(cand2);
//         }
//
//         if(from && size == cands.size()){ return; }
//         for(Node* n : nodes){
//             n -> propagate(this);
//         }
//     }
//     void print(){
//         cout << *cands.begin() << endl;
//     }
// };

int main(){
    // cin.tie(0);
    // ios::sync_with_stdio(false);
	int n, k;
	// cin >> n;
    scanf("%d", &n);
    vector<Node> nodes(n);
    for(int i=0;i<n-1;i++){
        int a, b;
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        a--; b--;
        nodes[a].nodes.push_back(&nodes[b]);
        nodes[b].nodes.push_back(&nodes[a]);
    }
    // cin >> k;
    scanf("%d", &k);
    int root;
    for(int i=0;i<k;i++){
        int v, p;
        // cin >> v >> p;
        scanf("%d %d", &v, &p);
        v--;
        // nodes[v].cands.insert(p);
        nodes[v].set(p);
        root = v;
    }

    // for(int i=0;i<n;i++){
    //     nodes[i].propagate();
    // }
    nodes[root].dfs();
    nodes[root].dfs2();
    if(!nodes[root].judge()){
        cout << "No" <<'\n';
        // puts("No");
        return 0;
    }

    cout << "Yes" <<'\n';
    // puts("Yes");
    for(int i=0;i<n;i++){
        nodes[i].print();
    }

	return 0;
}