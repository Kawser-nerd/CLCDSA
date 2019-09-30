#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using uint = unsigned int;
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    for(int _ = 0; _ < q; _++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool rev = false;
        if(a > b){
            swap(a, b);
            rev = true;
        }
        int ma = max(a, b), mi = min(a, b);
        int out = 0, in = ma;
        while(out + 1 < in){
            int piv = (out + in) / 2;
            if((ma + piv - 1) / piv - 1 <= mi){
                in = piv;
            }else{
                out = piv;
            }
        }
        int size = in;

        // aaaa bb a bbb ... a bbb a bbb
        int tailReps = (b - 1) / size;
        int headAs = a - tailReps;
        int headBs = b - tailReps * size;
        int headReps = 0;
        printd(size, headReps, headAs, headBs, tailReps);
        while(headAs > size){
            int times = (headAs - 1) / size;
            headBs -= times;
            headAs -= times * size;
            headReps += times;
            if(headBs <= 0 && tailReps){
                times = - headBs / size + 1;
                headAs += times;
                headBs += times * size;
                tailReps -= times;
            }
        }
        // while(headAs > size){
        //     if(headBs){
        //         headBs--;
        //         headAs -= size;
        //         headReps++;
        //     }
        //     if(headBs == 0 && tailReps){
        //         headAs++;
        //         headBs += size;
        //         tailReps--;
        //     }
        // }
        printd(headReps, headAs, headBs, tailReps);

        // if(a > 1e3 || b > 1e3){
        //     return 1;
        // }

        // aaa b aaa b ... aaa b aa bb a bbb ... a bbb
        int width = size + 1;
        int idx = c - 1;
        if(rev){
            idx = a + b - d;
        }
        // int idx = c / width * width;
        string str;
        int acc = headReps * width;
        while(idx < acc && (int)str.size() < d - c + 1){
            str += idx % width == size ? 'B' : 'A';
            idx++;
        }
        acc += headAs;
        while(idx < acc && (int)str.size() < d - c + 1){
            str += 'A';
            idx++;
        }
        acc += headBs;
        while(idx < acc && (int)str.size() < d - c + 1){
            str += 'B';
            idx++;
        }
        while((int)str.size() < d - c + 1){
            str += (idx - acc) % width ? 'B' : 'A';
            idx++;
        }
        if(rev){
            reverse(str.begin(), str.end());
            for(auto& c : str){
                cout << (c == 'A' ? 'B' : 'A');
            }
            cout << '\n';
        }else{
            cout << str << '\n';
        }
    }
}