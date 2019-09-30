using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace AtCoder.AGC026.B
{
    class Program
    {
        static void Main()
        {
            var sc = new Scanner();
            var T = sc.Nextint();
            var queries = Enumerable.Range(0, T).Select(i => new { A = sc.NextLong(), B = sc.NextLong(), C = sc.NextLong(), D = sc.NextLong() });
            foreach (var query in queries)
            {
                var A = query.A;
                var B = query.B;
                var C = query.C;
                var D = query.D;
                if (B > A)
                {
                    Console.WriteLine("No");
                    continue;
                }
                else if (B > D)
                {
                    Console.WriteLine("No");
                    continue;
                }
                else if (C >= B)
                {
                    Console.WriteLine("Yes");
                    continue;
                }
                else
                {
                    var g = MathExtensions.Gcd(B, D);
                    if (B - g + A % g > C)
                    {
                        Console.WriteLine("No");
                        continue;
                    }
                    else
                    {
                        Console.WriteLine("Yes");
                        continue;
                    }
                }
            }
        }
    }
    class Scanner
    {
        string[] s;
        long i;

        char[] cs = new char[] { ' ' };

        public Scanner()
        {
            s = new string[0];
            i = 0;
        }

        public string Next()
        {
            if (i < s.Length) return s[i++];
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            if (s.Length == 0) return Next();
            i = 0;
            return s[i++];
        }

        public int Nextint()
        {
            return int.Parse(Next());
        }
        public int[] Arrayint(int N, int add = 0)
        {
            int[] Array = new int[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Nextint() + add;
            }
            return Array;
        }

        public long NextLong()
        {
            return long.Parse(Next());
        }

        public long[] ArrayLong(int N, long add = 0)
        {
            long[] Array = new long[N];
            for (long i = 0; i < N; i++)
            {
                Array[i] = NextLong() + add;
            }
            return Array;
        }

        public double NextDouble()
        {
            return double.Parse(Next());
        }

        public double[] ArrayDouble(long N, double add = 0)
        {
            double[] Array = new double[N];
            for (long i = 0; i < N; i++)
            {
                Array[i] = NextDouble() + add;
            }
            return Array;
        }

        public decimal NextDecimal()
        {
            return decimal.Parse(Next());
        }

        public decimal[] ArrayDecimal(long N, decimal add = 0)
        {
            decimal[] Array = new decimal[N];
            for (long i = 0; i < N; i++)
            {
                Array[i] = NextDecimal();
            }
            return Array;
        }
    }

    static class MathExtensions
    {
        public static long Gcd(long a, long b)
        {
            var r = Math.Min(a, b);
            while (a != b && r != 0)
            {
                if (a > b) r = a %= b;
                else r = b %= a;
            }
            return Math.Max(a, b);
        }
    }
}