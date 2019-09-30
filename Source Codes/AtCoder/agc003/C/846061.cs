using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static int Solve(int[] A)
    {
        int N = A.Length;
        int[] B = A.OrderBy(a => a).ToArray();
        var rank = new Dictionary<int, int>();
        for (int i = 0; i < N; ++i)
        {
            rank[B[i]] = i;
        }
        int count = 0;
        for (int i = 0; i < N; ++i)
        {
            if (((rank[A[i]] ^ i) & 1) != 0) { ++count; }
        }
        return count / 2;
    }
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int[] A = new int[N];
        for (int i = 0; i < N; ++i)
        {
            A[i] = int.Parse(Console.ReadLine());
        }
        Console.WriteLine(Solve(A));
    }
}