#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long

int main(){
   /* int N, K;
    char S[101];
    cin >> N >> K;
    cin >> S;
    char Skotae[101];
    REP(i, N){
        Skotae[i] = S[i];
    }
    sort(Skotae, Skotae + N);
    int chigau[101] = 0;
    REP(i, N){
        if(Skotae[N - i - 1] )
    }*/
    char S[500], T[500];
    cin >> S;
    cin >> T;
    int nagasa = strlen(S);
    int nagasat = strlen(T);
    int hatenanagasa = 0;
    int tstart = -1;
    REP(i, nagasa){
        int ikeru = 0;
      //  printf("%c,%d,%c,%d\n",S[nagasa - i - 1], nagasa - i - 1, T[nagasat - hatenanagasa - 1], nagasat -hatenanagasa - 1);
        if(S[nagasa - i - 1] == '?' ) {hatenanagasa++;ikeru = 1;}
        else {
            REP(j, hatenanagasa + 1){
                if(S[nagasa - i - 1] == T[nagasat - hatenanagasa - 1 + j]){
                    ikeru = 1;
                    hatenanagasa = hatenanagasa - j + 1;
                    break;
                }
            }
        }
        if(ikeru == 0)hatenanagasa = 0;
        if(hatenanagasa >= nagasat) {tstart = nagasa - i - 1;break;}
    }
    //printf("%d\n", tstart);
    if(tstart == -1) printf("UNRESTORABLE");
    else{
        REP(i, nagasa){
            if(i >= tstart && i < tstart + nagasat){
                printf("%c", T[i - tstart]);
            }
            else if(S[i] == '?') printf("a");
            else printf("%c", S[i]);
            }
        }
    printf("\n");

}