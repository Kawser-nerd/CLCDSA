#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string nameHead = "MARCH";
    int str[5] = {0};
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        string inp; cin >> inp;
        for(int j = 0; j < 5; j++) {
            if(nameHead[j] == inp[0]) str[j]++;
        }
    }
    long long sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                sum += str[i] * str[j] * str[k];
            }
        }
    }
    cout << sum << endl;
    return 0;
}