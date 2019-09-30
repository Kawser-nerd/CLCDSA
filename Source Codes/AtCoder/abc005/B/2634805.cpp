#include <iostream>

using namespace std;

void input_int(int num, int *ptr);
int min_(int *a, int *b);

int main(){
    int n;
    cin >> n;
    int *t = new int[n];
    input_int(n, t);
    cout << min_(&t[0], &t[n - 1]) << endl;
    delete[] t;
    return 0;
}

void input_int(int num, int *ptr){
    if(num <= 0)
        return;
    cin >> *ptr;
    input_int(num - 1, ++ptr);
}

int min_(int *start, int *end){
    if(start == end)
        return *end;
    int prev_ans = min_(start + 1, end);
    if(*start < prev_ans)
        return *start;
    else
        return prev_ans;
}