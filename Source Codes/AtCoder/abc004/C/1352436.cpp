#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    N %= 30;
    int cards[6];
    for(int i = 0; i < 6; ++i){
        cards[i] = i+1;
    }

    for(int i = 0; i < N; ++i){
        int j = i % 5;
        int temp = cards[j];
        cards[j] = cards[j+1];
        cards[j+1] = temp;
    }

    for(int i = 0; i < 6; ++i){
        cout << cards[i];
            
    }
    cout << endl;

    return 0;
}