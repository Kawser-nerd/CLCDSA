using System;
using System.Linq;

class Program
{
    static readonly long MOD = 1000000007L;
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        long ans = s.GroupBy(c => c)
                    .Select(g => g.Count())
                    .Aggregate(1L, (accum, cnt) => (accum * (cnt + 1)) % MOD);
        ans = (ans - 1 + MOD) % MOD;
        Console.WriteLine(ans);
    }
}