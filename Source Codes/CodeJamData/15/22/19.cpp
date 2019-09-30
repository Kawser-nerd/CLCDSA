// WHY DOES THIS EVEN WORK

#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


struct Case {
    int R, C, N;


    void input(){
        scanf("%d%d%d", &R, &C, &N);
    }


    void run(){
        int numFree = (R*C+1)/2;

        if(N <= numFree){
            printf("0\n"); return;
        }

        int allEdges = R*(C-1) + C*(R-1);
        int result1 = 1e9, result2 = 1e9;

        if(R >= 2 && C >= 2){
            int numFour = ((R-2)*(C-2)+1)/2;
            int NN = N;
            if(R*C - NN <= numFour){
                result1 = allEdges - (R*C-NN) * 4;
            }

            int numTwo = ((R%2==1) && (C%2==1)) ? 4 : 2;
            int numThree = (R*C+1)/2 - numFour - numTwo;

//            printf("four=%d three=%d two=%d ", numFour, numThree, numTwo);

            allEdges -= numFour * 4;
            NN += numFour;

            if(R*C - NN <= numThree && result1 > 1e7){
                result1 = min(result1, allEdges - (R*C-NN) * 3);
            }

            allEdges -= numThree * 3;
            NN += numThree;
//            printf("R*C-NN=%d numTwo=%d ", R*C-NN, numTwo);
            if(R*C - NN <= numTwo && result1 > 1e7){
                result1 = min(result1, allEdges - (R*C-NN) * 2);
            }
            assert(result1 < 1e7);
        }

        vector<int> increases;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if((r+c) % 2 == 0) continue;

                int numSides = 0;
                if(r == 0) numSides++;
                if(r == R-1) numSides++;
                if(c == 0) numSides++;
                if(c == C-1) numSides++;

                increases.push_back(4 - numSides);
            }
        }

        sort(increases.begin(), increases.end());
        result2 = accumulate(increases.begin(),
                             increases.begin()+(N-numFree), 0);

        printf("%d\n", min(result1, result2));
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
