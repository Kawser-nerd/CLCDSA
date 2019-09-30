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
    private int[][] A;
    private bool[] U;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        M = int.Parse(line[1]);
        A = new int[N][];
        for (int i = 0; i < N; i++)
        {
            A[i] = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }
    }

    private int C(out int o)
    {
        int[] a = new int[M + 1];
        foreach(var i in A)
        {
            foreach(int j in i)
            {
                if (U[j])
                {
                    a[j]++;
                    break;
                }
            }
        }
        int result = -1;
        o = -1;
        for(int i = 1; i <= M; i++)
        {
            if (result < a[i])
            {
                result = a[i];
                o = i;
            }
        }
        return result;
    }


    public void Solve()
    {
        Scan();
        U = new bool[M + 1];
        for (int i = 1; i <= M; i++)
        {
            U[i] = true;
        }
        int ans = int.MaxValue;

        for (int i = 0; i < M; i++)
        {
            int o;
            ans = Math.Min(ans, C(out o));
            U[o] = false;
        }
        Console.WriteLine(ans);
    }
}