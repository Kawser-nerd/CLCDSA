#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)



constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

//?????????? unique_ptr<Segment_tree<int>> seg(new Segment_tree<int>(n));??????
template <typename T>
class Segment_tree{
public:
    Segment_tree(int origin_data_num){
        data_num = origin_data_num;
        width = 1;
        depth = 1;
        while(width<data_num){
            width *= 2;
            depth++;
        }
        nodes.resize(2*width-1,0);//??????????????   ?????...??:0 ??:1 ??:numeric_limits<T>::max()-5 ??:numeric_limits<T>::min()+5

    }
    Segment_tree(vector<T> origin_v){
        data_num = (int)origin_v.size();
        width = 1;
        depth = 1;
        while(width<data_num){
            width *= 2;
            depth++;
        }

        nodes.resize(2*width-1,0);//??????????????   ?????...??:0 ??:1 ??:numeric_limits<T>::max()-5 ??:numeric_limits<T>::min()+5
        REP(i,data_num){
            nodes[width - 1 + i] = origin_v[i];
            if(i&1){
            mini_update(i + width - 1);
            }
        }
    if((data_num&1)){
        mini_update(data_num + width - 2);
    }
    }
    ~Segment_tree(){}
    void mini_update(int where){

        int x = where;

        while(x > 0) {
            x = (x - 1) / 2;
            nodes[x] = nodes[2*x+1]+ nodes[2*x+2];
        }
    }

    void leaf_set(int where,T after_value){
        if(where<0||width<where){
            return;
        }

        nodes[width+where-1] = after_value;
        mini_update(width+where-1);
    }
    T get(int where){
        return nodes[where];
    }
    
    T get_leaf(int where){
        return nodes[width + where - 1];
    }
    void all_out(){
        cout << width <<' '<< depth << endl;
        
        REP(i,depth){
            REP(j,pow(2,i)-1){
                cout << nodes[(int)pow(2,i)-1+j] <<' ' ;
            }
        cout <<nodes[(int)pow(2,i+1)-2]<< endl;
        }
        cout<<endl;
    }

    T get_val(int a, int b, int k=0, int l=0, int r=-1) {
        // ????????????????? [0, n)
        if(r < 0) {
            r = width;
        }
        // ??????????????? -> ?????
        if(r <= a || b <= l) {return 0;}//?????...??:0 ??:1 ??:numeric_limits<T>::max()-5 ??:numeric_limits<T>::min()+5

        // ??????????????? -> ?????????????
        if(a <= l && r <= b) {return nodes[k];}

        // ??????????????? -> ??????????
        // ????? vl ? ????? vr ?????
        // ?????????????????????????
        T vl = get_val(a, b, 2*k+1, l, (l+r)/2);
        T vr = get_val(a, b, 2*k+2, (l+r)/2, r);
        return vl+ vr;
    }
private:
    int width,data_num,depth;
    vector<T> nodes;
};


int main(){

    int n,k;
    cin >> n >> k;
    vector<long long int> v(n);
    REP(i,n){scanf("%lld", &v[i]);}

    unique_ptr<Segment_tree<long long int>> seg(new Segment_tree<long long int>(v));



    long long int result = 0;
    REP(i,n-k+1){
        result += seg->get_val(i,i+k);

    }
    cout << result << endl;

    return 0;
}