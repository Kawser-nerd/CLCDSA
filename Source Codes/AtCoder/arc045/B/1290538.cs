using System;
using System.Collections.Generic;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, M;
    private int[] s, t;
    private int[] Table;
    List<int> Ans = new List<int>();

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        M = int.Parse(line[1]);
        s = new int[M];
        t = new int[M];
        for (int i = 0; i < M; i++)
        {
            line = Console.ReadLine().Split(' ');
            s[i] = int.Parse(line[0]) - 1;
            t[i] = int.Parse(line[1]) - 1;
        }
        Table = new int[N];
    }

    private void Imos()
    {
        for (int i = 0; i < M; i++)
        {
            Table[s[i]]++;
            if (t[i] < N - 1)
            {
                Table[t[i] + 1]--;
            }
        }
        for (int i = 1; i < N; i++)
        {
            Table[i] += Table[i - 1];
        }
    }

    private void CuSum()
    {
        if (Table[0] > 1)
        {
            Table[0] = 0;
        }
        for (int i = 1; i < N; i++)
        {
            if (Table[i] == 1)
            {
                Table[i] = Table[i - 1] + 1;
            }
            else
            {
                Table[i] = Table[i - 1];
            }
        }
    }

    private void Calc()
    {
        for (int i = 0; i < M; i++)
        {
            int sum = Table[t[i]];
            if (s[i] > 0)
            {
                sum -= Table[s[i] - 1];
            }
            if (sum == 0)
            {
                Ans.Add(i + 1);
            }
        }
    }

    private void Write()
    {
        Console.WriteLine(Ans.Count);
        foreach (int i in Ans)
        {
            Console.WriteLine(i);
        }
    }

    public void Solve()
    {
        Scan();
        Imos();
        CuSum();
        Calc();
        Write();
    }
}