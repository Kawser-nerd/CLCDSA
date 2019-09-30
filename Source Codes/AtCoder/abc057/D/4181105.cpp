#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    long v[50];
    long comb[51][51];
    comb[0][0] = 0;
    long ans = 0;
    for(int i = 0; i < 51; i++){
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j < i; j++){
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v, v+N, greater<long>());
    
    int cnt = 0;
    int first = -1;
    for(int i = 0; i < N; i++){
        if(v[i] == v[A-1]){
            if(first == -1) first = i;
            cnt++;
        }
    }
    
    if(v[0] == v[A-1]){
        for(int i = A-1; i <= B-1; i++){
            if(v[i] == v[0])ans += comb[cnt][i+1];
        }
        cout << v[0] << endl;
    }else{
        long sum = 0;
        for(int i = 0; i < A; i++){
            sum += v[i];
        }
        //cout << setprecision(10) << ((double)sum)/((double)A) << endl;
        printf("%.6f\n",((double)sum)/((double)A));
        ans = comb[cnt][A-first];
    }
    cout << ans << endl;
}