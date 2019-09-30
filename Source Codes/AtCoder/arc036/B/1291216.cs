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
    int[] H;

    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        H = new int[N];
        for (int i = 0; i < N; i++)
        {
            H[i] = int.Parse(Console.ReadLine());
        }
    }

    public void Solve()
    {
        Scan();
        int[] upCnt = new int[N];
        int[] downCnt = new int[N];
        for (int i = 0; i < N; i++)
        {
            if (i > 0)
            {
                upCnt[i] = H[i] > H[i-1] ? upCnt[i - 1] + 1 : 0;
            }
        }
        for(int i = N - 1; i >= 0; i--)
        {
            if (i < N - 1)
            {
                downCnt[i] = H[i] > H[i + 1] ? downCnt[i + 1] + 1 : 0;
            }
        }
        int ans = -1;
        for(int i = 0; i < N; i++)
        {
            int m = upCnt[i] + downCnt[i] +1;
            ans = Math.Max(m, ans);
        }
        Console.WriteLine(ans);
    }
}