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
    //cout << "main called" << endl;
    int N;
    std::vector<int> vec;
    int m1;
    cin >> N;

    for (int i = 0; i < N;i++){
        cin >> m1;
        vec.push_back(m1);
    }

    std::vector<int> queue = vec;
    std::sort(vec.begin(), vec.end());
    int med_r = vec[N / 2];
    int med_l=vec[N / 2 - 1];
    for(int i=0;i<N;i++){
        if(queue[i]<=med_l){
            cout << med_r << endl;
        }else{
            cout << med_l << endl;
        }
    }

    return 0;
}