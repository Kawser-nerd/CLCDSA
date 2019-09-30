#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {

    int N, A, B;
    cin >> N >> A >> B;

    int counter = 0;
    for (int i = 1; i <= N; ++i) {
        string numString = to_string(i);
        int num = 0;
        for (int j = 0; j < numString.size(); ++j) {
            string sss = numString.substr(j, 1);
            num += atoi(sss.c_str());;
        }

        if (A <= num && num <= B) {
            counter += i;
        }
    }
    cout << counter << endl;
}