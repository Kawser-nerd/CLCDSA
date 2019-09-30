using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

class Program
{
    static bool Solve(int N, long[] A)
    {
        long sum = A.Sum();
        long sigma = Math.BigMul(N, N + 1) / 2;
        if (sum % sigma != 0) { return false; }
        long steps = sum / sigma;
        long count = 0;
        for (int i = 0; i < N; ++i)
        {
            long dif = A[(i + 1) % N] - A[i];
            if (dif > steps) { return false; }
            if ((steps - dif) % N != 0) { return false; }
            count += (steps - dif) / N;
        }
        return count == steps;
    }
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        long[] A = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        Console.WriteLine(Solve(N, A) ? "YES" : "NO");
    }
}