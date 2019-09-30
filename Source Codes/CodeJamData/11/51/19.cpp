#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int W , L , U , Part;
double Lh[1001];
double Uh[1001];
double h[1001];
double Area[1001];

double calc(double R)
{
    double ret = 0;
    int t = (int)R;
    ret += Area[t];
    //cout << t << ":" << Area[t] << endl;
    
    for(int i = t ; i < W ; i++)
    {
        int Lef = i;
        int Rig = i + 1;
        if((double)Rig <= R)
            ret += (h[Lef] + h[Rig]) / 2;
        else
        {
            if(Lef > R)
                return ret;
            double Dis1 = R - Lef;
            double Dis2 = Rig - R;
            double H = h[Lef] * Dis2 + h[Rig] * Dis1;
            ret += (h[Lef] + H) * Dis1 / 2;
        }
    }
    return ret;
}

double bs(double want)
{
    double L = 0 , R = W , M;
    while(R - L > 1e-7)
    {
        M = (L + R) / 2;
        if(calc(M) < want)
            L = M;
        else
            R = M;
    }
    return M;
}

void solve()
{
    cin >> W >> L >> U >> Part;
    for(int i = 0 ; i <= W ; i++)
        Lh[i] = -1000000 , Uh[i] = -1000000;
    for(int i = 1 ; i <= L ; i++)
    {
        int x;
        double y;
        cin >> x >> y;
        Lh[x] = y;
    }
    for(int i = 1 ; i <= U ; i++)
    {
        int x;
        double y;
        cin >> x >> y;
        Uh[x] = y;
    }
    for(int i = 1 ; i < W ; i++)
    {
        if(Lh[i] < -10000)
        {
            for(int j = i + 1 ; j <= W ; j++)
                if(Lh[j] >= -1000)
                {
                    Lh[i] = (double(j - i) * Lh[i-1] + Lh[j]) / double(j - i + 1);
                    break;
                }
        }
        if(Uh[i] < -10000)
        {
            for(int j = i + 1 ; j <= W ; j++)
                if(Uh[j] >= -1000)
                {
                    Uh[i] = (double(j - i) * Uh[i-1] + Uh[j]) / double(j - i + 1);
                    break;
                }
        }
    }
    Area[0] = 0;
    for(int i = 0 ; i <= W ; i++)
        h[i] = Uh[i] - Lh[i];
    for(int i = 1 ; i <= W ; i++)
    {
        Area[i] = Area[i-1] + (h[i] + h[i-1]) / 2.0;
    }

    double eachS = calc(W) / double(Part);
    cout << endl;
    for(int i = 1 ; i < Part ; i++)
        cout << bs(eachS * i) << endl;
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    cout << fixed << setprecision(10);
    int TestCase;
    cin >> TestCase;
    for(int CaseID = 1 ; CaseID <= TestCase ; CaseID ++)
    {
        cout << "Case #" << CaseID << ": ";
        solve();
    }
    //system("pause");
    return 0;
}
