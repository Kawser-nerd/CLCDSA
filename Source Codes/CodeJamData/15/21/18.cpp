#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


struct Case {
    LL N;


    void input(){
        scanf("%lld", &N);
    }

    LL pwr10(int what){
        LL result = 1;
        while(what--) result *= 10;
        return result;
    }

    // asserting equal lengths and from = 10^k
    LL min_num_moves(LL from, LL to){
        assert(from <= to);
        if(from == to) return 0;
        
        // no inverting?
        LL result = to - from;
        
        if(to % 10 == 0){
            return min_num_moves(from, to-1) + 1;
        }

        // inverting?
        string strTo = to_string(to);
        int len = (int)strTo.size();
        LL res = 1; // for inverse
        for(int i = 0; i < len; i++){
            int digit = strTo[i] - '0';
            LL coef = pwr10(min(i, len-i-1));
//            printf("coef=%lld ", coef);

            if(i == len-1){
                res += coef * (digit-1);
            } else {
                res += coef * digit;
            }
        }
//        printf("res=%lld ", res);

        return min(result, res);
    }

    void run(){
        LL result = 0;
        LL number = 1;

        while(number != N){
            if(number*10 <= N){
                result += min_num_moves(number, number*10-1) + 1;
                number *= 10;
            } else {
                result += min_num_moves(number, N);
                number = N;
            }
        }

        printf("%lld\n", result+1);
    }
};

int main(){
    int numTests;
    scanf("%d", &numTests);

    for(int i = 1; i <= numTests; i++){
        Case C;
        C.input();
        printf("Case #%d: ", i);
        C.run();
    }
}
