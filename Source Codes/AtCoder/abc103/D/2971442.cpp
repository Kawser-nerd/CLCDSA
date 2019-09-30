#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long

class Bluedaishou{
public:
    bool operator()(const pair<int, int>& riLeft, const pair<int, int>& riRight) const {
        return riLeft.first < riRight.first; // ??????? < ?????????????????????
    }
};
class Reddaishou{
public:
    bool operator()(const pair<int, int>& riLeft, const pair<int, int>& riRight) const {
        return riLeft.second > riRight.second; // ??????? < ?????????????????????
    }
};

typedef pair<int, int> pint;
class Islanddaishou{
public:
    bool operator()(const pint& riLeft, const pint& riRight) const {
        return riLeft.second > riRight.second || (riLeft.second == riRight.second && riLeft.first < riRight.first);
    }
                                                  };

vector<pint> ab;
int islandswar(){
    
    
    return 0;
}

int main(){
    int M, N;
    cin >> N >> M;
    REP(i, M){
        int a,b;
        cin >> a >> b;
        ab.push_back(pint(a,b));
    }
    
    sort(ab.begin(), ab.end(), Islanddaishou());
    int hasinohousuu = 0;
    while(!ab.empty()){
        
        int hasinomigihasi = ab.back().second;
        ab.pop_back();
        while(ab.back().first < hasinomigihasi && !ab.empty()){
            ab.pop_back();
        }
        hasinohousuu++;
    }
    printf("%d\n", hasinohousuu);
    
    /*int N;
    cin >> N;
    vector <pair<int,int>> ab;
    vector <pair<int,int>> cd;
    int a,b,c,d;
    
    REP(i, N){
        cin >> a >> b;
        ab.push_back({a,b});
    }
    REP(i, N){
        cin >> c >> d;
        cd.push_back({c,d});
    }
    sort(ab.begin(),ab.end(),Reddaishou());
    sort(cd.begin(),cd.end(),Bluedaishou());
    REP(i, N){
    //    printf("(%d,%d),(%d,%d)\n",ab[i].first , ab[i].second , cd[i].first ,cd[i].second);
    }
    int pairninatta = 0;
    bool matchsita = false;
    bool mada[100] = {false};
    REP(i, N){
        REP(j, N){
            matchsita = false;
            //printf("(%d,%d),(%d,%d)\n",ab[i].first , ab[i].second , cd[j].first ,cd[j].second);
            if(ab[ i].first < cd[j].first && ab[i].second < cd[j].second && mada[j] == false){
                //printf("A");
    //            printf("(%d,%d),(%d,%d)\n",ab[i].first , ab[i].second , cd[j].first ,cd[j].second);
                mada[j] = true;
                matchsita = true;
                pairninatta++;
                break;
            }
        }
    }
    cout << pairninatta;
    /*int T, N, M;
    int A[120];
    int B[101];
    
    cin >> T;
    cin >> N;
    REP(i, N){
        cin >> A[i];
    }
    cin >> M;
    REP(i, M){
        cin >> B[i];
    }
    
    bool takoyaki[101] = {false};
    bool ureta = false;
    REP(i, M){
        ureta = false;
        REP(j, N){
            if(B[i] - A[j] <= T && B[i] >= A[j] && takoyaki[j] == false){
                takoyaki[j] = true;
                ureta = true;
                break;
            }
        }
        if(!ureta){
            printf("no\n");
            break;
        }
    }
    if(ureta){
        printf("yes\n");
    }
    
   /* int N;
    cin >> N;
    int danball[50];
    REP(i, N){
        cin >> danball[i];
    }
    int yamanokazu = 1;
    int yama[50];
    yama[0] = danball[0];
    bool kasanerareta;
    REP(i, N){
        kasanerareta = false;
        REP(j, yamanokazu){
            if(danball[i] <= yama[j]){
                yama[j] = danball[i];
                kasanerareta = true;
                break;
            }
        }
        if(kasanerareta == false){
            yama[yamanokazu] = danball[i];
            yamanokazu++;
        }
    }
    cout << yamanokazu << endl;
    /*ll X, Y;
    cin >> X >> Y;
    int i = 0;
    do{
        X *= 2;
        i++;
    }while(X <= Y);
    cout << i;
    */
    /*int alphabets[26];
    int alphabetsnaraberu[26];
    int N, K;
    char S[101];
    cin >> N >> K;
    cin >> S;
    char Skotae[101];
    int chigaukazu = 0;
    vector<char> Snaraberu;
    REP(i, N){
        Snaraberu.push_back(S[i]);
    }
    sort(Snaraberu.begin(), Snaraberu.end());
    int chigau[101] = {0};
    REP(i, N){
        if(Snaraberu[N - i - 1] != S[N - i - 1])chigau[N - i - 1] = chigau[N - i] + 1;
        else chigau[N - i - 1] = chigau[N - i];
    }
    int aru = 0;
    int chigaukakutei = 0;
    REP(i,26){
        alphabets[i] = 0;
        alphabetsnaraberu[i] = 0;
    }
    REP(i,N){
        alphabets[S[i] - 'a']++;
        alphabetsnaraberu[S[i] - 'a']++;
    }
    //REP(i, N){printf("%c", Snaraberu[i]);}
    REP(i, N - 1){
        if(alphabetsnaraberu[S[i] - 'a'] < alphabets[S[i] - 'a'])chigaukakutei++;
        alphabets[S[i] - 'a'] -= 1;
        REP(j, N - i){
            chigaukazu = 0;
            if(S[i] != Snaraberu[j]) {chigaukazu+=2;
       //         printf("a\n");
                
            }
          //  printf("now:%c\n",Snaraberu[j]);
            REP(l,26){
                if(l == Snaraberu[j] - 'a'){chigaukazu += abs(alphabets[l] - alphabetsnaraberu[l] + 1);
           //         printf("now%d\n",abs(alphabets[l] - alphabetsnaraberu[l] + 1));
                    
                }
                else {
                    chigaukazu += abs(alphabets[l] - alphabetsnaraberu[l]);
         //           printf("now:%c:%d\n",'a' + l,abs(alphabets[l] - alphabetsnaraberu[l]));
                }
            }
            chigaukazu = chigaukazu / 2 + chigaukakutei;
            if(chigaukazu <= K){
        //        printf("%c,%d\n",Snaraberu[j],chigaukazu);
                Skotae[i] = Snaraberu[j];
                alphabetsnaraberu[Skotae[i] - 'a'] -= 1;
                Snaraberu.erase(Snaraberu.begin() + j);
                if(S[i] != Skotae[i] /*&& alphabetsnaraberu[Skotae[i] - 'a'] >= alphabets[Skotae[i] - 'a'])chigaukakutei ++;
        //        printf("%d\n",chigaukakutei);
                break;
                
            }
        }
    }
    REP(i,N-1){
        printf("%c",Skotae[i]);
    }
    printf("%c\n",Snaraberu[0]);*/
    /*char S[500], T[500];
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
    printf("\n");*/

} ./Main.cpp:99:5: warning: '/*' within block comment [-Wcomment]
    /*int T, N, M;
    ^
./Main.cpp:133:4: warning: '/*' within block comment [-Wcomment]
   /* int N;
   ^
./Main.cpp:158:5: warning: '/*' within block comment [-Wcomment]
    /*ll X, Y;
    ^
./Main.cpp:222:38: warning: '/*' within block comment [-Wcomment]
                if(S[i] != Skotae[i] /*&& alphabetsnaraberu[Skotae[i] - 'a'] >= alphabets[Skotae[i] - 'a'])chigaukakutei ++;
                                     ^
4 warnings generated.