using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;
using System.Diagnostics;

class Scanner
{
    private readonly char Separator = ' ';
    private int Index = 0;
    private string[] Line = new string[0];
    public string Next()
    {
        if (Index >= Line.Length)
        {
            Line = Console.ReadLine().Split(Separator);
            Index = 0;
        }
        var ret = Line[Index];
        Index++;
        return ret;
    }

    public int NextInt()
    {
        return int.Parse(Next());
    }

    private long NextLong()
    {
        return long.Parse(Next());
    }
}

class Program
{
    private int N;
    private int[] A1, A2;
    private void Scan()
    {
        var sc = new Scanner();
        N = sc.NextInt();
        A1 = new int[N];
        A2 = new int[N];
        for (int i = 0; i < N; i++)
        {
            A1[i] = sc.NextInt();
        }
        for (int i = 0; i < N; i++)
        {
            A2[i] = sc.NextInt();
        }
    }

    public void Solve()
    {
        Scan();
        for(int i=1;i<N;i++)
        {
            A1[i] += A1[i - 1];
            A2[N - i - 1] += A2[N - i];
        }
        int max = -1;
        for(int i=0;i<N;i++)
        {
            max = Math.Max(A1[i] + A2[i], max);
        }
        Console.WriteLine(max);
    }

    static public void Main()
    {
        new Program().Solve();
    }
}