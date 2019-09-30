#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t, ct;
    for (cin >> t, ct = 1; ct <= t; ct++)
    {
        string C, J;
        cin >> C >> J;
        vector<long long> V_l, V_m, V_r;
        vector<string> V_la, V_ma, V_ra;
        vector<string> V_lb, V_mb, V_rb;
        int n = C.size();
        V_l.push_back(0);
        V_m.push_back(0);
        V_r.push_back(0);
        for (int i = 0; i < n; i ++)
        {
            V_l.push_back(1);
            V_m.push_back(1);
            V_r.push_back(-1);
            V_la.push_back("");
            V_lb.push_back("");
            V_ma.push_back("");
            V_mb.push_back("");
            V_ra.push_back("");
            V_rb.push_back("");
            int a1, a2, b1, b2;
            if (C[i] == '?')
            {
                a1 = 0;
                a2 = 9;
            }
            else
            {
                a1 = a2 = C[i] - '0';
            }
            if (J[i] == '?')
            {
                b1 = 0;
                b2 = 9;
            }
            else
            {
                b1 = b2 = J[i] - '0';
            }
            for (int a = a1; a <= a2; a++)
                for (int b = b1; b <= b2; b++)
                {
                    if (V_l[i] < 0)
                    {
                        long long difference = V_l[i] * 10 + a - b;
                        string aa = (i == 0? string() : V_la[i - 1]) + char('0' + a);
                        string bb = (i == 0? string() : V_lb[i - 1]) + char('0' + b);
                        if (difference < 0 && (difference > V_l[i + 1] || difference == V_l[i + 1] && aa < V_la[i] || difference == V_l[i + 1] && aa == V_la[i] && bb < V_lb[i] || V_l[i + 1] == 1))
                        {
                            V_l[i + 1] = difference;
                            V_la[i] = aa;
                            V_lb[i] = bb;
                        }
                    }
                    if (V_m[i] == 0)
                    {
                        long long difference = V_m[i] * 10 + a - b;
                        string aa = (i == 0? string() : V_ma[i - 1]) + char('0' + a);
                        string bb = (i == 0? string() : V_mb[i - 1]) + char('0' + b);
                        if (difference < 0 && (difference > V_l[i + 1] || difference == V_l[i + 1] && aa < V_la[i] || difference == V_l[i + 1] && aa == V_la[i] && bb < V_lb[i] || V_l[i + 1] == 1))
                        {
                            V_l[i + 1] = difference;
                            V_la[i] = aa;
                            V_lb[i] = bb;
                        }
                        if (difference == 0 && (aa < V_ma[i] || aa == V_ma[i] && bb < V_mb[i] || V_m[i + 1] == 1))
                        {
                            V_m[i + 1] = difference;
                            V_ma[i] = aa;
                            V_mb[i] = bb;
                        }
                        if (difference > 0 && (difference < V_r[i + 1] || difference == V_r[i + 1] && aa < V_ra[i] || difference == V_r[i + 1] && aa == V_ra[i] && bb < V_rb[i] || V_r[i + 1] == -1))
                        {
                            V_r[i + 1] = difference;
                            V_ra[i] = aa;
                            V_rb[i] = bb;
                        }
                    }
                    if (V_r[i] > 0)
                    {
                        long long difference = V_r[i] * 10 + a - b;
                        string aa = (i == 0? string() : V_ra[i - 1]) + char('0' + a);
                        string bb = (i == 0? string() : V_rb[i - 1]) + char('0' + b);
                        if (difference > 0 && (difference < V_r[i + 1] || difference == V_r[i + 1] && aa < V_ra[i] || difference == V_r[i + 1] && aa == V_ra[i] && bb < V_rb[i] || V_r[i + 1] == -1))
                        {
                            V_r[i + 1] = difference;
                            V_ra[i] = aa;
                            V_rb[i] = bb;
                        }
                    }
                }
        }
        long long distance = 1000000000000000000ll;
        string A, B;
        if (V_m[n] == 0)
        {
            A = V_ma[n - 1];
            B = V_mb[n - 1];
            distance = 0;
        }
        if (V_l[n] < 0 && -V_l[n] < distance)
        {
            A = V_la[n - 1];
            B = V_lb[n - 1];
            distance = -V_l[n];
        }
        if (V_r[n] > 0 && (V_r[n] < distance || V_r[n] == distance && V_ra[n - 1] < A || V_r[n] == distance && V_ra[n - 1] == A && V_rb[n - 1] < B))
        {
            A = V_ra[n - 1];
            B = V_rb[n - 1];
            distance = V_r[n];
        }
        cout << "Case #" << ct << ": " << A << " " << B << endl;
    }

    return 0;
}
