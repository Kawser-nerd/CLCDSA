#include <iostream>

using namespace std;

int main(){
    int N;
    int a[100000];
    cin >> N;
    int a_max = 0;
    int a_min = INT32_MAX;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a_max = max(a[i], a_max);
        a_min = min(a[i], a_min);
    }
    if(a_max > a_min+1){
        cout << "No" << endl;
    }else if(a_max == a_min){
        int m = a_min;
        if(N-1 == m){
            cout << "Yes" << endl;
        }else if(N >= 2*m){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        int min_cnt = 0;
        int max_cnt = 0;
        for(int i = 0; i < N; i++){
            if(a[i] == a_min) min_cnt++;
            if(a[i] == a_max) max_cnt++;
        }
        if(2*(a_max - min_cnt) <= max_cnt && a_max - min_cnt > 0){
            cout << "Yes" << endl;
        }else if(a_max - min_cnt == max_cnt){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}