#include <iostream>

using namespace std;

typedef struct Station {
    int distance;
    int opening;
    int cycle;
    int takeTime;
};

Station stations[512];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int c, s, f;
        cin >> c >> s >> f;

        Station station = {c, s, f, 0};
        stations[i] = station;
    }

    Station station = {0, 0, 0, 0};
    stations[n - 1] = station;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i; j < n; ++j) {
            // ???
            if (stations[i].takeTime < stations[j].opening) stations[i].takeTime = stations[j].opening;

            // ??????
            if (stations[j].cycle > 0) {
                int diff = (stations[i].takeTime - stations[j].opening) % stations[j].cycle;
                if (diff != 0) stations[i].takeTime += stations[j].cycle - diff;
            }

            // ????
            stations[i].takeTime += stations[j].distance;
        }
    }

    for (int i = 0; i < n; ++i) cout << stations[i].takeTime << endl;

    return 0;
} ./Main.cpp:5:1: warning: typedef requires a name [-Wmissing-declarations]
typedef struct Station {
^~~~~~~
1 warning generated.