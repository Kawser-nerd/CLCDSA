#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;

int main(void){
    int N;
    cin >> N;
    std::vector<int> vec;
    int m1;
    for (int i = 0; i < N;i++){
        cin >> m1;
        vec.push_back(m1);
    }
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    int comb_n = vec[0];
    int comb_r_target = vec[0] / 2;
    double comb_r_target_d = vec[0] / 2.0;
    int comb_r;

    if(N==2){
        cout << vec[0] << " " << vec[1] << endl;
        return 0;
    }

    int i = 0;
    if(comb_r_target<vec[N-1]){
        comb_r = vec[N - 1];
    }else{
        while(vec[i]>comb_r_target){
            i++;
        }
        //cout << " i is " << i<<endl;
        //cout << comb_r_target <<" "<< comb_r_target_d<<endl;
        if (vec[i] == comb_r_target)
        {
            comb_r = vec[i];
        }else{
            if(comb_r_target_d-(double)vec[i]>(double)vec[i-1]-comb_r_target_d){
                comb_r = vec[i - 1];
            }else{
                comb_r = vec[i];
            }
        }
    }
    cout << comb_n << " " << comb_r << endl;

    return 0;
}