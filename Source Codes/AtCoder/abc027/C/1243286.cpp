#include <iostream>
#include <cmath>

using namespace std;

long long int N = 0;

bool f = false;

bool solve(long long int i, long long int x){
    if(x > N){
        return i%2 == 0;
    }

    //Takahashi
    if(i%2 == 0){
        x = (f ? 2*x : 2*x + 1);
        return solve(i+1, x);
    }
    //Aoki
    else{
        x = (f ? 2*x + 1: 2*x);
        return solve(i+1, x);
    }
}

int main(void){
    cin >> N;

    long long int depth = (long long int)log2(N);

    long long int left  = pow(2, depth);
    long long int right = pow(2, depth+1) - 1;
    long long int num_2 = pow(2, depth - 1);

    //f is okay
    /*
    if((left + num_2) < N){
        f = true;
    }else{
        f = false;
    }*/
    f = (depth%2 != 0);

    if(solve(0, 1)){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
}