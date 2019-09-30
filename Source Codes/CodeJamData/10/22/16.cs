using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class B : X, IABC
{
    public B() { }
    public B(int i) : base(i) { }

    public void solve()
    {
        ReadLine();
        int N = ReadInt();
        int K = ReadInt();
        int B = ReadInt();
        int T = ReadInt();
        ReadLine();
        int[] X = ReadIntArray();
        ReadLine();
        int[] V = ReadIntArray();
        int r = 0;
        int c = 0;
        int u = 0;
        int[] Z = new int[N];
        for (int i = 0; i < N; i++)
        {
            Z[i] = X[i] + V[i] * T;
        }
        for (int i = N-1; i >=0; i--)
        {
            if (c >= K) break;
            if (Z[i] < B)
                u++;
            else
            {
                c++;
                r += u;
            }
        }

        if (c < K)
        WriteCase("{1}", "IMPOSSIBLE");
        else
        WriteCase("{1}", r);
    }
}
