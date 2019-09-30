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
    private int K;
    private long[] A;
    private void Scan()
    {
        var sc = new Scanner();
        K = sc.NextInt();
        A = new long[K];
        for (int i = 0; i < K; i++)
        {
            A[i] = sc.NextInt();
        }
    }

    public void Solve()
    {
        Scan();
        long max = 2, min = 2;
        for (int i = K - 1; i >= 0; i--)
        {
            if (((min + A[i] - 1) / A[i]) * A[i] > max)
            {
                Console.WriteLine(-1);
                return;
            }
            max = (max / A[i]) * A[i] + A[i] - 1;
            min = ((min + A[i] - 1) / A[i]) * A[i];
        }
        Console.WriteLine($"{min} {max}");
    }

    static public void Main()
    {
        new Program().Solve();
    }
}