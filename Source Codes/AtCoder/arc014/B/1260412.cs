using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    public void Solve()
    {
        var hs = new HashSet<string>();
        int N = int.Parse(Console.ReadLine());
        var W = new string[N];
        for (int i = 0; i < N; i++)
        {
            W[i] = Console.ReadLine();
        }
        hs.Add(W[0]);
        for (int i = 1; i < N; i++)
        {
            if (!hs.Add(W[i]) || W[i - 1][W[i - 1].Length - 1] != W[i][0])
            {
                Console.WriteLine(i % 2 == 1 ? "WIN" : "LOSE");
                return;
            }
        }
        Console.WriteLine("DRAW");
    }
}