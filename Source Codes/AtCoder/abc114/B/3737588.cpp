#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int LIKE_NUMBER = 753;

int main(){
    int result = 1000;
    string input = "";
    cin >> input;

    // ?????????3?????????
    for (int i = 0; i < input.length() - 2; i++){
        string tmp = "";
        for (int j = i; j < i + 3; j++){
            tmp += input[j];
        }
        int number = stoi(tmp);
        if (abs(LIKE_NUMBER - number) < result){
            result = abs(LIKE_NUMBER - number);
        }
    }

    cout << result << endl;

    return 0;
}