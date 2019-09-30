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
    private int N;
    private int[] A;
    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    public void Solve()
    {
        Scan();
        var b = new bool[100001];
        int j = 0;
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int a = A[i];
            if (b[a])
            {
                while (b[a])
                {
                    b[A[j]] = false;
                    j++;
                }
            }
            b[a] = true;
            ans = Math.Max(ans, i - j + 1);
        }
        Console.WriteLine(ans);
    }
}