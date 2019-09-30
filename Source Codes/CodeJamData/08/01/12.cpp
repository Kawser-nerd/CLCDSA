#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef int ret_t;

class Solver {
public:
    ret_t solve(int s, vector<int> q) {
        vector<int> b(s, 0);
        for (int i = 0; i < q.size(); ++i) {
            int low = 10000;
            for (int j = 0; j < s; ++j) if (j != q[i] && b[j] < low)
                low = b[j];
            b[q[i]] = low + 1;
        }
        int low = 10000;
        for (int j = 0; j < s; ++j) if (b[j] < low)
            low = b[j];
        return low;
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
        int S;
        {
            stringstream A(s);
            A >> S;
        }
        map<string, int> name;
        for (int i = 0; i < S; ++i) {
            getline(cin, s);
            name[s] = i;
        }
        getline(cin, s);
        int Q;
        {
            stringstream A(s);
            A >> Q;
        }
        vector<int> q(Q);
        for (int i = 0; i < Q; ++i) {
            getline(cin, s);
            stringstream A(s);
            q[i] = name[A.str()];
        }
        ret_t ret = solver.solve(S, q);

        // *** give output ***
        cout << "Case #" << no << ": " << ret << endl; // one line
        //cout << "Case #" << no << ":\n" << ret; // multi-line
        //cout << "Case #" << no << ": " << fixed << setprecision(7) << ret << endl; // float
    }
    return 0;
}
