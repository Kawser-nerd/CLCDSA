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
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}



public class Magatro
{
    private long N, M, D;
    private long[] A;
    private long[] Amida;

    private void Scan()
    {
        string[] line = Console.ReadLine().Split(' ');
        N = long.Parse(line[0]);
        M = long.Parse(line[1]);
        D = long.Parse(line[2]);
        line = Console.ReadLine().Split(' ');
        A = new long[M];
        for(int i = 0; i < M; i++)
        {
            A[i] = long.Parse(line[i]);
        }
    }

    public void Solve()
    {
        Scan();

        long[] ans = (new long[N]).Select((i, index) => (long)index+1).ToArray();
        Amida = (new long[N]).Select((i, index) => (long)index).ToArray();
        foreach (int i in A)
        {
            Amida[i] ^= Amida[i - 1];
            Amida[i - 1] ^= Amida[i];
            Amida[i] ^= Amida[i - 1];
        }

        while (D > 0)
        {
            if (D % 2 == 1)
            {
                long[] t = new long[N];
                for (int i = 0; i < N; i++)
                {
                    t[Amida[i]] = ans[i];
                }
                for(int i = 0; i < N; i++)
                {
                    ans[i] = t[i];
                }
            }
            D /= 2;
            long[] tt = new long[N];
            for (int i = 0; i < N; i++)
            {
                tt[i] = Amida[Amida[i]];
            }
            for(int i = 0; i < N; i++)
            {
                Amida[i] = tt[i];
            }
        }
        for(int i = 0; i < N; i++)
        {
            Console.WriteLine(ans[i]);
        }
    }
}