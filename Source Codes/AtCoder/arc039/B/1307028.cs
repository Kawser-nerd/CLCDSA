using System;
using System.Collections.Generic;
using System.Linq;
using System.Collections;
using System.Linq.Expressions;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, K;
    const int Mod = 1000000007;
    private int[,] Combination;
    private void Scan()
    {
        var l = Console.ReadLine().Split(' ');
        N = int.Parse(l[0]);
        K = int.Parse(l[1]);
    }

    private void Calc()
    {
        Combination = new int[1001, 1001];
        for(int i = 0; i < 1001; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(i == 0 || j == 0)
                {
                    Combination[i, j] = 1;
                }
                else
                {
                    Combination[i, j] = (Combination[i - 1, j - 1] + Combination[i - 1, j]) % Mod;
                }
            }
        }
    }

    public void Solve()
    {
        Scan();
        Calc();
        if (N > K)
        {
            Console.WriteLine(Combination[N + K - 1, K]);
        }
        else
        {
            Console.WriteLine(Combination[N, K % N]);
        }
    }
}