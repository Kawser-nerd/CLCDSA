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

struct P
{
    public double X, Y;

    public P(double x, double y)
    {
        X = x;
        Y = y;
    }
}


class Magatro
{
    private int N, M;
    private int[] F;
    const int Mod = 1000000007;

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        M = int.Parse(line[1]);
        F = new int[N];
        for (int i = 0; i < N; i++)
        {
            F[i] = int.Parse(Console.ReadLine());
        }
    }

    public void Solve()
    {
        Scan();
        int[] DP = new int[N + 1];
        DP[0] = 1;
        int index = 0;
        int sum = 1;
        bool[] bo = new bool[M + 1];
        for (int i = 1; i <= N; i++)
        {
            int s = F[i - 1];
            if (bo[s])
            {
                while (bo[s])
                {
                    bo[F[index]] = false;
                    sum -= DP[index];
                    while (sum < 0)
                    {
                        sum += Mod;
                    }
                    sum %= Mod;
                    index++;
                }

            }
            bo[s] = true;
            DP[i] = sum;
            sum += DP[i];
            sum %= Mod;
        }
        Console.WriteLine(DP[N]);
    }
}