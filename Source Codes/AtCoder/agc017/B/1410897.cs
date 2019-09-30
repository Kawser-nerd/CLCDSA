using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private long N, A, B, C, D;
    private long S;

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        A = int.Parse(line[1]);
        B = int.Parse(line[2]);
        C = int.Parse(line[3]);
        D = int.Parse(line[4]);
    }

    bool Bo(int n)//n?+
    {
        long a = C * n;
        long b = D * n;

        long c = C * (N - 1 - n);
        long d = D * (N - 1 - n);

        long aa = b - c;
        long bb = a - c;
        if (bb <= S && S <= aa)
        {
            return true;
        }

        long cc = b - d;
        long dd = a - d;

        if (dd <= S && S <= cc)
        {
            return true;
        }
        return false;
    }


    public void Solve()
    {
        Scan();
        S = Math.Abs(A - B);
        for (int i = 0; i < N; i++)
        {
            if (Bo(i))
            {
                Console.WriteLine("YES");
                return;
            }
        }
        Console.WriteLine("NO");
    }
}