#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template <int COL_SIZE> class mat {
private:
    // (or, and) ??????(???????????(????????????????))
    mat operator*(const mat& m) const {
        mat ans;
        for(int i = 0; i < COL_SIZE; i++){
            for(int j = 0; j < COL_SIZE; j++){
                if(this->a[i][j] == 0) continue;
                ans.a[i] |= m.a[j];
            }
        }
        return ans;
    }
    
public:
    bitset<COL_SIZE>* a;
    int r;
    // ???????
    mat() : mat(COL_SIZE){}
    // ????????
    mat(int row_size) : r(row_size){ a = new bitset<COL_SIZE>[r]; }
    int rank() {
        int res = 0;
        for(int i = 0; i < COL_SIZE; i++){
            if(res == r) return res;
            int pivot = res;
            if(!a[pivot][i]){
                for(int j = res + 1; j < r; j++){
                    if(a[j][i]){
                        pivot = j;
                        break;
                    }
                }
                if(!a[pivot][i]) continue;
                swap(a[pivot], a[res]);
            }
            for(int j = res + 1; j < r; j++){
                if(a[j][i]) a[j] ^= a[res];
            }
            res++;
        }
        return res;
    }
    inline const bitset<COL_SIZE>& operator[](size_t index) const {
        return a[index];
    }
    inline bitset<COL_SIZE>& operator[](size_t index){
        return a[index];
    }
    friend mat pow(mat m, long long cnt){
        mat res;
        for(int i = 0; i < COL_SIZE; i++) res[i][i] = 1;
        while(cnt){
            if(cnt & 1){
                res = res * m;
            }
            m = m * m;
            cnt >>= 1;
        }
        return res;
    }
};
int main(){
    int n;
    cin >> n;
    mat<200>a;
    rep(i,n){
        string s;
        cin >> s;
        rep(j,n)if(s[j]=='1')a[i][j] = 1;
    }
    if(a.rank()==n){
        cout << "Odd" << endl;
    }else{
        cout << "Even" << endl;
    }
}