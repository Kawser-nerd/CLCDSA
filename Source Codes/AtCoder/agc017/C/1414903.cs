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
    private int N, M;
    private int[] A;
    private int Count = 0;
    private int[] Map;
    private int[] C;

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        M = int.Parse(line[1]);
        A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    private void Q()
    {
        int x, y;
        var line = Console.ReadLine().Split(' ');

        x = int.Parse(line[0]);
        y = int.Parse(line[1]);
        int xx = A[x - 1];
        A[x - 1] = y;
        Map[xx]--;
        int p = xx - Map[xx];
        if (p >= 1)
        {
            C[p]--;
            if (C[p] == 0)
            {
                Count++;
            }
        }
        Map[y]++;
        int q = y - Map[y] + 1;

        if (q >= 1)
        {
            if (C[q] == 0)
            {
                Count--;
            }
            C[q]++;
        }
    }

    public void Solve()
    {
        Scan();
        Map = new int[N + 1];
        C = new int[N + 1];
        foreach (int i in A)
        {
            Map[i]++;
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < Map[i]; j++)
            {
                int p = i - j;
                if (p >= 1)
                {
                    C[i - j]++;
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            if (C[i] == 0)
            {
                Count++;
            }
        }

        var sb = new StringBuilder();

        for (int n = 0; n < M; n++)
        {
            Q();
            sb.AppendLine(Count.ToString());
        }
        Console.WriteLine(sb.ToString());
    }
}