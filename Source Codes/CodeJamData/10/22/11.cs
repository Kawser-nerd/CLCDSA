using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class B : Solution
{
    int n, k, b, t;
    int[] v;
    int[] x;


    public override void Init(System.IO.TextReader r)
    {
        string[] z = r.ReadLine().Split(' ');
        n = int.Parse(z[0]);
        k = int.Parse(z[1]);
        b = int.Parse(z[2]);
        t = int.Parse(z[3]);

        z = r.ReadLine().Split(' ');
        x = new int[n];
        v = new int[n];
        for (int i = 0; i < n; i++)
            x[i] = int.Parse(z[i]);
        z = r.ReadLine().Split(' ');

        for (int i = 0; i < n; i++)
            v[i] = int.Parse(z[i]);

    }

    public override string Solve()
    {
        bool[] ontime = new bool[n];

        for (int i = 0; i < n; i++)
        {
            ontime[i] = (b - x[i] <= t * v[i]);
        }

        int chickenin = 0;
        int chickenout = 0;
        int swaps = 0;

        Array.Reverse(ontime);

        for (int i = 0; i < n; i++)
        {
            if (ontime[i])
            {
                chickenin++;
                swaps += chickenout;
            }
            else
            {
                chickenout++;
            }

            if (chickenin == k)
                return swaps.ToString();
                

        }
        return "IMPOSSIBLE";
    }
}