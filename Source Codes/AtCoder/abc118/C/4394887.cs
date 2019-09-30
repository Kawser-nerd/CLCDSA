using System;
using System.Linq;
using System.Collections.Generic;

namespace ABC118
{
    public class C
    {
        public void Solve()
        {
            int N = int.Parse(Console.ReadLine());
            int[] A = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int res = A[0];
            for (int i = 1; i < N; i++)
            {
                res = Gcd(res, A[i]);
            }
            Console.WriteLine(res);
        }
        public int Gcd(int a, int b)
        {
            return (b < 0) ? Gcd(a, -b)
                 : (a < b) ? Gcd(b, a)
                 : (b > 0) ? Gcd(b, a % b)
                           : a;
        }
    }
}

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new ABC118.C().Solve();
        }
    }
}