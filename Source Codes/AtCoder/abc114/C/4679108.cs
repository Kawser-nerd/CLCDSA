using System;
using System.Linq;
using System.Numerics;

    class Program
    {
        static int dfs(string s, BigInteger N)
        {
            if (BigInteger.Parse(s) > N) return 0;
            var ret = 1;
            if (!(s.Contains('7') && s.Contains('5') && s.Contains('3'))) ret = 0;
            foreach (var c in "753")
            {
                ret += dfs(s + c, N);
            }
            return ret;
        }

        static void Main(string[] args)
        {
            var N = BigInteger.Parse(Console.ReadLine());
            Console.WriteLine(dfs("0", N));
        }
    }