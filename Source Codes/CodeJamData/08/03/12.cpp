#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef double ret_t;

class Solver {
public:
    ret_t solve(double f, double R, double t, double r, double g) {
        if (2 * f >= g || R - t - f <= 0)
            return 1;
        int fullholes = 0;
        double holes = 0;
        double step = g + 2 * r;
        double rad = R - t - f;
        int x = -1; bool moveright = true;
        int y = (int)(rad / step);
        double yin, yout;
        bool done = false;
        while (!done) {
            //cerr << "y in " << y*step+r+f << "," << (y+1)*step-r-f << endl;
            if (moveright) {
                ++x;
                if (x * step + r + f > rad)
                    done = true;
                else {
                    yin = sqrt(rad * rad - (x * step + r + f)
                               * (x* step + r + f));
                    if ((x+1)*step - r - f < rad)
                        yout = sqrt(rad * rad - ((x+1)*step - r - f)
                                    * ((x+1)*step - r - f));
                    else
                        yout = -1;
                }
                //cerr << "*** yin = " << yin << ", yout = " << yout << endl;
                moveright = false;
            }
            else if (yin < y * step + r + f) {
                --y;
                if (y < 0)
                    done = true;
            }
            else if (yout >= (y+1)*step - r - f) {
                //cerr << x << "," << y << " completely open" << endl;
                fullholes += y + 1;
                moveright = true;
            }
            else {
                double ax, ay, bx, by;
                if (yin <= (y+1)*step - r - f) {
                    ax = x * step + r + f;
                    ay = yin;
                }
                else {
                    ay = (y+1)*step - r - f;
                    ax = sqrt(rad * rad - ay * ay);
                }
                if (yout >= y * step + r + f) {
                    bx = (x+1)*step - r - f;
                    by = yout;
                    fullholes += y;
                    moveright = true;
                }
                else {
                    by = y * step + r + f;
                    bx = sqrt(rad * rad - by * by);
                }
                //cerr << "(" << ax << "," << ay << ")-("
                //     << bx << "," << by << ")" << endl;
                double s = (atan(ay / ax) - atan(by / bx)) * rad * rad / 2;
                //cerr << s;
                s -= (ay - by) * ax / 2 + (bx - ax) * by / 2;
                //cerr << ", " << s;
                s += (ay - y * step - r - f) * (ax - x * step - r - f);
                //cerr << ", " << s << endl;
                s += (by - y * step - r - f) * (bx - ax);
                //cerr << x << "," << y << " parially open:"
                //     << s << endl;
                holes += s;
                if (!moveright) {
                    --y;
                    if (y < 0)
                        done = true;
                }
            }
        } // while
        holes *= 4;
        holes += 4 * fullholes * (g - 2 * f) * (g - 2 * f);
        double total = M_PI * R * R;
        return (total - holes) / total;
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
        double f, R, t, r, g;
        {
            stringstream A(s);
            A >> f >> R >> t >> r >> g;
        }
        ret_t ret = solver.solve(f, R, t, r, g);

        // *** give output ***
        //cout << "Case #" << no << ": " << ret << endl; // one line
        //cout << "Case #" << no << ":\n" << ret; // multi-line
        cout << "Case #" << no << ": " << fixed << setprecision(7) << ret << endl; // float
    }
    return 0;
}
