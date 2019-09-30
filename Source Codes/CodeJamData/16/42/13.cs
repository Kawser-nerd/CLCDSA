using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    double Solve(int N, int K, List<double> P)
    {
        return Enumerable.Range(0, 1 << N).Max(mask =>
        {
            var p = new List<double>(N);
            for (var m = 0; m < N; m++)
            {
                if ((mask & (1 << m)) == 0) p.Add(P[m]);
            }
            if (p.Count != K) return 0;

            var proba = new double[K + 1];
            proba[1] = p[0];
            proba[0] = 1 - p[0];
            foreach (var pp in p.Skip(1))
            {
                var next = new double[K + 1];
                for (int i = 0; i < K; i++)
                {
                    next[i] += proba[i] * (1 - pp);
                    next[i + 1] += proba[i] * pp;
                }
                proba = next;
            }
            return proba[K / 2];
        });
    }

    static void Output()
    {
        var NK = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        Console.WriteLine(new B().Solve(NK[0], NK[1], Console.ReadLine().Split(' ').Select(double.Parse).ToList()));
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) { Console.Write("Case #{0}: ", i); Output(); } }
}