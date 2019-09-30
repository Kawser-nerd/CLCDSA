using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N;
    int[] T;
    const int Mod = 1000000007;
    long[] F = new long[10001];

    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        T = new int[N];
        for (int i = 0; i < N; i++)
        {
            T[i] = int.Parse(Console.ReadLine());
        }
    }

    private void Calc()
    {
        F[0] = 1;
        for (int i = 1; i <= 10000; i++)
        {
            F[i] = (F[i - 1] * i) % Mod;
        }
    }

    public void Solve()
    {
        Scan();
        Calc();
        Array.Sort(T);
        long time = 0;
        long minTime = 0;
        long ans = 1;
        int cnt = 1;
        for (int i = 0; i < N; i++)
        {
            time += T[i];
            minTime += time;
            if (i == 0) continue;

            if (T[i] == T[i - 1])
            {
                cnt++;
            }
            else
            {
                ans *= F[cnt];
                ans %= Mod;
                cnt = 1;
            }
        }
        ans *= F[cnt];
        ans %= Mod;
        Console.WriteLine(minTime);
        Console.WriteLine(ans);
    }
}