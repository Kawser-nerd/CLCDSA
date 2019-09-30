using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N;
    private int M;
    private const int Mod = (int)1e9 + 7;

    public void Solve()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        M = int.Parse(line[1]);
        if (N < M)
        {
            var T = N;
            N = M;
            M = T;
        }
        if (N - 1 > M)
        {
            Console.WriteLine(0);
            return;
        }
        if (N - 1 == M)
        {
            long d = 1;
            long f = 1;
            for (int i = 1; i <= N; i++)
            {
                d *= i;
                d %= Mod;

            }
            for (int i = 1; i <= M; i++)
            {
                f *= i;
                f %= Mod;
            }
            Console.WriteLine(f * d % Mod);
        }
        if (N == M)
        {
            long d = 1;
            for (int i = 1; i <= N; i++)
            {
                d *= i;
                d %= Mod;

            }
            Console.WriteLine((d * d) % Mod * 2 % Mod);
        }
    }
}