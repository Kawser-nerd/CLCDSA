using System;
using System.Linq;

namespace AGC018A
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] NK = Console.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
            long[] A = Console.ReadLine().Split(' ').Select(b => long.Parse(b)).ToArray();
            Console.WriteLine(solve(NK[1], A) ? "POSSIBLE" : "IMPOSSIBLE");
        }

        static bool solve(long K, long[] A)
        {
            if (K > A.Max())
            {
                return false;
            }

            long Gcd = A[0];

            for (int i = 0; i < A.Length; i++)
            {
                Gcd = gcd(A[0], A[i]);
            }

            if (K % Gcd == 0)
            {
                return true;
            }

            return false;
        }

        static long gcd(long a, long b)
        {
            long mod;
            while (b != 0)
            {
                mod = a % b;
                a = b;
                b = mod;
            }

            return a;
        }
    }
}