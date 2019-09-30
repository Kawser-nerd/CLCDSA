#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ways{1,5,10,-1,-5,-10};

int main() {
    int a, b;
    cin >> a >> b;

    queue<pair<int,int>> q;
    q.push(make_pair(a, 0));

    while(!q.empty()) {
        pair<int,int> now = q.front();
        q.pop();

        if (now.first == b) {
            cout << now.second << endl;
            break;
        }

        for (int i = 0; i < ways.size(); i++) {
            pair<int, int> next = make_pair(now.first+ways[i], now.second+1);

            if (!(next.first < 0 || next.first> 40)) {
                q.push(next);
            }
        }
    }

    return 0;
}