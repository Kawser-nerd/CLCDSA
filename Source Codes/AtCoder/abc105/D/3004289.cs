using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace AtCoder.ABC105.D
{
    class Program
    {
        static void Main()
        {
            var sc = new Scanner();
            var n = sc.Nextint();
            var m = sc.Nextint();
            var A = sc.Arrayint(n);

            var comulativeSumMod = CalculateComulativeSumMod(A, m, 0);
            Console.Error.WriteLine(string.Join(" ", comulativeSumMod));
            var counter = new Dictionary<long, int>();
            var result = 0L;
            foreach (var item in comulativeSumMod)
            {
                if (!counter.ContainsKey(item)) counter.Add(item, 0);
                result += counter[item];
                counter[item]++;
            }
            Console.WriteLine(result);
        }

        static IEnumerable<int> CalculateComulativeSumMod(IEnumerable<int> source, int mod, int seed)
        {
            var accumulate = seed;
            yield return accumulate;
            foreach (var item in source)
            {
                yield return accumulate = (accumulate + item) % mod;
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
}