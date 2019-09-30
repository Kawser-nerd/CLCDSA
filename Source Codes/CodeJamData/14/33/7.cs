using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    int Solve(int N, int M, int K)
    {
        if (N > M)
        {
            var temp = N;
            N = M;
            M = temp;
        }
        if (N <= 2) return K;
        if (N == 3 && M == 3) return K <= 4 ? K : K - 1;
        if (N == 3 && M == 4) return K <= 4 ? K : K <= 7 ? K - 1 : K - 2;
        if (N == 3 && M == 5) return K <= 4 ? K : K <= 7 ? K - 1 : K <= 10 ? K - 2 : K - 3;
        if (N == 3 && M == 6) return K <= 4 ? K : K <= 7 ? K - 1 : K <= 10 ? K - 2 : K <= 13 ? K - 3 : K - 4;
        if (N == 4 && M == 4) return K <= 4 ? K : K <= 7 ? K - 1 : K <= 9 ? K - 2 : K <= 11 ? K - 3 : K - 4;
        if (N == 4 && M == 5) return K <= 4 ? K : K <= 7 ? K - 1 : K <= 9 ? K - 2 : K <= 11 ? K - 3 : K <= 13 ? K - 4 : K <= 15 ? K - 5 : K - 6;
        throw new ArgumentException();
    }

    static IEnumerable<string> Output()
    {
        var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new C().Solve(line[0], line[1], line[2]).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}