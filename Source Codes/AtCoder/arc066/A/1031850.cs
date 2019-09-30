using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

class Program
{
    static int Power(int N)
    {
        int ans = 1;
        for (int i = 0; i < N; ++i)
        {
            ans *= 2;
            ans %= 1000000007;
        }
        return ans;
    }
    static int Solve(int N, int[] A)
    {
        Array.Sort(A);
        if (N % 2 == 0)
        {
            for (int i = 0; i < N; ++i)
            {
                if (A[i] != ((i & ~1) + 1)) { return 0; }
            }
        }
        else
        {
            for (int i = 0; i < N; ++i)
            {
                if (A[i] != ((i + 1) & ~1)) { return 0; }
            }
        }
        return Power(N / 2);
    }
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int[] A = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Console.WriteLine(Solve(N, A));
    }
}