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
        var ans = new int[N];
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
            {
                ans[i / 2] = A[N - i - 1];
            }
            else
            {
                ans[N-i/2-1] = A[N - i - 1];
            }
        }
        Console.WriteLine(string.Join(" ", ans));
    }
}