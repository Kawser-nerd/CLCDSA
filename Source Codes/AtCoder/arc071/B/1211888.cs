using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

public class Magatro
{
    private long N, M;
    private long[] X, Y;
    const int Mod = 1000000007;
    public void Solve()
    {
        string[] s = Console.ReadLine().Split(' ');
        N = long.Parse(s[0]);
        M = long.Parse(s[1]);
        X = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        Y = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        long xS = 0;
        for(int i = 0; i < N; i++)
        {
            xS += (i*X[i]-(N-i+-1)*X[i]);
            xS %= Mod;
        }
        long yS = 0;
        for (int i = 0; i < M; i++)
        {
            yS += (i * Y[i] - (M - i-1) * Y[i]);
            yS %= Mod;
        }
        Console.WriteLine(xS * yS % Mod);
    }

    public void S()
    {
        string[] s = Console.ReadLine().Split(' ');
        N = long.Parse(s[0]);
        M = long.Parse(s[1]);
        s = Console.ReadLine().Split(' ');
        long x = long.Parse(s[N - 1]) - long.Parse(s[0]);
        s = Console.ReadLine().Split(' ');
        long y = long.Parse(s[M - 1]) - long.Parse(s[0]);
        long sq = (x * y);
        long ans = 0;
        for (int i = 0; i < 100000; i++)
        {
            ans = (sq * i) % Mod;
            if (ans == 835067060)
            {
                Console.WriteLine(i);
                return;
            }
        }
    }
}