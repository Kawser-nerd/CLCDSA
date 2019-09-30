#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solve(vector<pair<int64_t, int64_t> > H) {
    vector<int64_t> times;
    for (auto &h : H) {
        h.first *= h.second;
        h.second *= 360;
        times.push_back(h.second - h.first);
    }

    sort(times.begin(), times.end());

    int answer = H.size();

    set < pair<int64_t, int> > when;
    vector<int> many(H.size(), 0);
    for (int i = 0; i < int(H.size()); ++i) {
        auto h = H[i];
        when.emplace(h.second - h.first, i);
    }

    int overtake = H.size();
    int undertake = 0;
    for (auto &x : times) {
        while (when.begin()->first <= x && undertake <= answer) {
            int64_t time; int whom; tie(time, whom) = *when.begin();
            when.erase(when.begin());
            if (many[whom] == 0)
                --overtake;
            else
                ++undertake;
            ++many[whom];
            when.emplace(time + H[whom].second, whom);
        }
        answer = min(answer, overtake + undertake);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    for (int test = 1; test <= T; ++test) {
        int N; cin >> N;
        vector< pair<int64_t, int64_t> > H;
        for (int i = 0; i < N; ++i) {
            int D, K, M; cin >> D >> K >> M;
            for (int j = 0; j < K; ++j)
                H.emplace_back(D, M + j);
        }

        cout << "Case #" << test << ": " << solve(H) << "\n";
    }
}
