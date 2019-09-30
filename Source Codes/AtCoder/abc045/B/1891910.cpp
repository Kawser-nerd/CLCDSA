#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    size_t ia, ib, ic;
    ia = ib = ic = 0;
    int turn = 'a';
    while(1){
        switch(turn){
            case 'a':
                if(ia >= sa.length()){
                    cout << 'A' << endl;
                    return 0;
                }
                turn = sa[ia++];
                break;
            case 'b':
                if(ib >= sb.length()){
                    cout << 'B' << endl;
                    return 0;
                }
                turn = sb[ib++];
                break;
            case 'c':
                if(ic >= sc.length()){
                    cout << 'C' << endl;
                    return 0;
                }
                turn = sc[ic++];
                break;
        }
    }

    return 0;
}