using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

class Program
{
    struct Ratio
    {
        public readonly long T;
        public readonly long A;
        public Ratio(params long[] args)
        {
            T = args[0];
            A = args[1];
        }
    }
    static private long Solve(Ratio[] ratios)
    {
        int N = ratios.Length;
        var ratio1 = ratios[0];
        for (int i = 1; i < N; ++i)
        {
            long k = Math.Max((ratio1.T + ratios[i].T - 1) / (ratios[i].T),
                              (ratio1.A + ratios[i].A - 1) / (ratios[i].A));
            ratio1 = new Ratio(ratios[i].T * k, ratios[i].A * k);
        }
        return ratio1.T + ratio1.A;
    }
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        var ratios = new Ratio[N];
        for (int i = 0; i < N; ++i)
        {
            ratios[i] = new Ratio(Array.ConvertAll(Console.ReadLine().Split(), long.Parse));
        }
        Console.WriteLine(Solve(ratios));
    }
}