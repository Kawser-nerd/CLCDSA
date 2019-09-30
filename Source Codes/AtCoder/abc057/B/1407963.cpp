#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N, M, tmpa, tmpb;
    cin >> N >> M;
    
    vector<pair<long, long>> stu(N);
    vector<pair<long, long>> cp(M);
    for(int i=0; i<N; i++) {
        cin >> tmpa >> tmpb;
        stu[i] = make_pair(tmpa, tmpb);
    }
    for(int i=0; i<M; i++) {
        cin >> tmpa >> tmpb;
        cp[i] = make_pair(tmpa, tmpb);
    }

    long tmp;
    long res = 999999999999999999L;
    int resp = -1;
    for(int i=0; i<N; i++){
        res = 999999999999999999L;
        resp = -1;
        for(int j=0; j<M; j++){
            tmp =  abs(stu[i].first - cp[j].first) + abs(stu[i].second - cp[j].second);
            if(tmp < res) {
                res = tmp;
                resp = j+1;
            }
        }
        cout << resp << endl;
    }

}