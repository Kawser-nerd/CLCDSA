#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef int ret_t;

class Solver {
public:
    ret_t solve(int n, int D, vector<int> a) {
	ret_t ret = 0;
	for (int i = D*2; i < n; ++i)
	    if (a[i] != a[i - D*2])
		return -1;
	for (int d = D; d >= 1; d /= 2) {
	    int tmp = (a[0] - a[d]) - (a[2*d-1] - a[d-1]);
	    //int sumabs = 0;
	    //int firstdiff = a[0] - a[d];
	    //int maxdiff = abs(a[0] - a[d]);
	    int ups = 0;
	    int downs = 0;
	    for (int i = d - 1; i > 0; --i) {
		//maxdiff = max(maxdiff, abs(a[i] - a[d+i]));
		a[d+i] = (a[i] - a[d+i]) - (a[i-1] - a[d+i-1]);
		if (a[d+i]&1) return -1;
		a[d+i] /= 2;
		//sumabs += abs(a[d+i]);
		if (a[d+i] > 0)
		    ups += a[d+i];
		else
		    downs -= a[d+i];
	    }
	    a[d] = tmp;
	    if (a[d]&1) return -1;
	    a[d] /= 2;
	    //sumabs += abs(a[d]);
	    if (a[d] > 0)
		ups += a[d];
	    else
		downs -= a[d];

	    /*for (int i = d; i < 2*d; ++i)
		cerr<<' '<<a[i];
	    cerr << endl;
	    cerr << '|' << ups << '|' << downs << endl;*/

	    int cur = downs;
	    for (int i = 0; i < d; ++i) {
		cur += a[d+i];
		a[i] -= cur;
		if (a[i] < 0)
		    return -1;
	    }
	    ret += ups + downs;
	}
	return ret;
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
        cerr //<< "Case "
	    << no << " / " << N << endl;
        Solver solver;
        // *** get input ***
        getline(cin, s);
        int n, D;
        {
            stringstream A(s);
            A >> n >> D;
        }
	vector<int> a(n);
	getline(cin, s);
	{
	    stringstream A(s);
	    for (int i = 0; i < n; ++i)
		A >> a[i];
	}
        ret_t ret = solver.solve(n, D, a);

        // *** give output ***
        cout << "Case #" << no << ": ";
	if (ret >= 0)
	    cout << ret << endl; // one line
	else
	    cout << "CHEATERS!" << endl; // one line
	//cout << "Case #" << no << ":"; for (int i = 0; i < ret.size(); ++i) cout << " " << ret[i]; cout << endl; // vector
        //cout << "Case #" << no << ":\n" << ret; // multi-line
        //cout << "Case #" << no << ": " << fixed << setprecision(7) << ret << endl; // float
    }
    return 0;
}
