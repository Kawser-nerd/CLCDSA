using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    int Solve(long P, long Q)
    {
        while (true)
        {
            var gcd = Gcd(P, Q);
            if (gcd == 1) break;

            P /= gcd;
            Q /= gcd;
            continue;
        }  
        
        while (Q < (1L << 40))
        {
            Q *= 2;
            P *= 2;
        }
        if (Q > (1L << 40)) return 0;

        return Enumerable.Range(1, 40).First(i => P >= (1L << (40 - i)));
    }

    static long Gcd(long a, long b)
    {
        return b == 0 ? a : Gcd(b, a % b);
    }

    static IEnumerable<string> Output()
    {
        var PQ = Console.ReadLine().Split('/').Select(long.Parse).ToArray();
        var result = new A().Solve(PQ[0], PQ[1]);
        yield return result <= 0 ? "impossible" : result.ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}