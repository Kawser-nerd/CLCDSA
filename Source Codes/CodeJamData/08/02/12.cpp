#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef pair<int, int> ret_t;

class Solver {
public:
    int solve2(vector<int> out, vector<int> in) {
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());
        int ret = 0;
        int u = 0;
        for (int i = 0; i < out.size(); ++i) {
            if (u < in.size() && in[u] <= out[i]) {
                ++u;
            }
            else {
                ++ret;
            }
        }
        return ret;
    }
    ret_t solve(int t, vector<pair<int, int> > a, vector<pair<int, int> > b) {
        vector<int> toa, froma, tob, fromb;
        for (int i = 0; i < a.size(); ++i) {
            froma.push_back(a[i].first);
            tob.push_back(a[i].second + t);
        }
        for (int i = 0; i < b.size(); ++i) {
            fromb.push_back(b[i].first);
            toa.push_back(b[i].second + t);
        }
        return make_pair(solve2(froma, toa), solve2(fromb, tob));
	}
};

int main(int argc, char ** argv) {
    string s;
    int N;
    getline(cin, s);
    {
        stringstream A(s);
        A >> N;
    }
    for (int no = 1; no <= N; ++no) {
        cerr << "Case " << no << " / " << N << endl;
        Solver solver;
        // *** get input ***
        getline(cin, s);
        int time;
        {
            stringstream A(s);
            A >> time;
        }
        getline(cin, s);
        int na, nb;
        {
            stringstream A(s);
            A >> na >> nb;
        }
        vector<pair<int, int> > a, b;
        for (int i = 0; i < na; ++i) {
            getline(cin, s);
            if (s.size() != 11) cerr << "Bad format" << endl;
            vector<int> t(11);
            for (int i = 0; i < 11; ++i)
                t[i] = s[i] - '0';
            a.push_back(make_pair(t[0]*600+t[1]*60+t[3]*10+t[4],
                                  t[6]*600+t[7]*60+t[9]*10+t[10]));
        }
        for (int i = 0; i < nb; ++i) {
            getline(cin, s);
            if (s.size() != 11) cerr << "Bad format" << endl;
            vector<int> t(11);
            for (int i = 0; i < 11; ++i)
                t[i] = s[i] - '0';
            b.push_back(make_pair(t[0]*600+t[1]*60+t[3]*10+t[4],
                                  t[6]*600+t[7]*60+t[9]*10+t[10]));
        }
        ret_t ret = solver.solve(time, a, b);

        // *** give output ***
        cout << "Case #" << no << ": "
             << ret.first << " " << ret.second << endl; // one line
        //cout << "Case #" << no << ":\n" << ret; // multi-line
        //cout << "Case #" << no << ": " << fixed << setprecision(7) << ret << endl; // float
    }
    return 0;
}
