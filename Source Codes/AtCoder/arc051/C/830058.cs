using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            UInt64 mod = 1000000007;

            var str = Console.ReadLine().Split();
            var N = Int32.Parse(str[0]);
            var A = UInt64.Parse(str[1]);
            var B = UInt64.Parse(str[2]);
            str = Console.ReadLine().Split();
            var a = new List<UInt64>();
            for (int i = 0; i < N; i++) a.Add(UInt64.Parse(str[i]));

            a.Sort();
            if (A > 1)
            {
                while (a[0] * A < a[N - 1] && B > 0)
                {
                    a[0] *= A;
                    a.Sort();
                    B--;
                }
            }

            var num = B % (UInt64)N;
            for (UInt64 i = 0; i < num; i++)
            {
                a[0] *= A;
                a.Sort();
                B--;
            }

            //remaining
            var pow = B / (UInt64)N;
            for (int i = 0; i < N; i++)
            {
                a[i] %= mod;
                a[i] *= ModPow(A, pow, mod);
            }

            Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
            foreach (var ai in a) Console.WriteLine(ai % mod);
            Console.Out.Flush();
        }

        static public UInt64 ModPow(UInt64 x, UInt64 n, UInt64 mod)
        {
            UInt64 ret = 1;
            while (n > 0)
            {
                if ((n & 1) == 1) ret = ret * x % mod;
                x = x * x % mod;
                n >>= 1;
            }
            return ret;
        }
    }
}