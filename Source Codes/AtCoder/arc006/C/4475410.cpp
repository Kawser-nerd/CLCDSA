#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> back;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int w;
        cin >> w;
        int min = 0x3f3f3f3f;
        int min_index = -1;
        for (int i = 0; i < back.size();i++) {
            if (back[i] >= w && back[i] - w < min) {
                min = back[i] - w;
                min_index = i;
            }
        }
        if (min_index == -1) back.push_back(w);
        else back[min_index] = w;
    }
    cout << back.size() << endl;
    return 0;
}