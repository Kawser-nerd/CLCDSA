#include <iostream>

using namespace std;

string names[] = {
        "TAKAHASHIKUN",
        "Takahashikun",
        "takahashikun",
};

int main() {

    int N;
    int count = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        for (int j = 0; j < 3; j++) {
            if (name == names[j] || name == names[j] + '.') count++;
        }
    }

    cout << count << endl;
}