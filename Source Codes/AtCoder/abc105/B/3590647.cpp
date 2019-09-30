#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    if(!(N % 4) || !(N % 7)){
        cout << "Yes" << endl;
        return 0;
    }else{
        for(int i = 1; i < (N / 4); ++i){
            if(!((N - 4 * i) % 7)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}