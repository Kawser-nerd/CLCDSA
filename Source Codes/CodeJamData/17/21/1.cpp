#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

ifstream fin ("A.in");
ofstream fout ("A.out");

void run()
{
    int D, N;
    fin >> D >> N;
    double ans = 0.0; // longest time
    for (int i = 0; i < N; i++)
    {
        double K, S;
        fin >> K >> S;
        ans = max (ans, (D - K) / S);
    }

    fout << D / ans;
}

int main()
{
    fout << fixed << setprecision(7);
    int T; fin >> T;
    for (int i = 1; i <= T; i++)
    {
        fout << "Case #" << i << ": ";
        run();
        fout << "\n";
    }
}