#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <class T>
void read_nums(istream& ist, vector<T>& nums, size_t cnt){
    for(size_t i = 0; i < cnt; i++){
        T val;
        ist >> val;
        nums.push_back(val);
    }
}

bool is_tree(int n, vector<vector<int> >& edges, vector<int>& flags){
    if(flags[n-1]) return false;
    flags[n-1] = 1;
    for(size_t i = 0; i < edges[n-1].size(); i++){
        if(!is_tree(edges[n-1][i], edges, flags)){
            return false;
        }
    }
    return true;
}

bool is_forest(int N, vector<vector<int> > &edges){
    for(int n = 1; n <= N; n++){
        vector<int> flags(N, 0);
        if(!is_tree(n, edges, flags)){
            return false;
        }
    }
    return true;
}

int main(){
    size_t T = 0;
    cin >> T;
    for(size_t t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector< vector<int> > edges;
        for(size_t n = 1; n <= N; n++){
            vector<int> nums;
            size_t mi;
            cin >> mi;
            read_nums(cin, nums, mi);
            edges.push_back(nums);
        }
        bool result = is_forest(N, edges);
        if(!result){
            cout << "Case #" << t << ": Yes" << endl;
        }else{
            cout << "Case #" << t << ": No" << endl;
        }
    }
    return 0;
}

