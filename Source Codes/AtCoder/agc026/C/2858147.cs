using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace AtCoder
{
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static Dictionary<Tuple<string, string>, long> MakeDictionary(string S)
        {
            int N = S.Length;
            var dict = new Dictionary<Tuple<string, string>, long>();
            for (int i = 0; i < 1 << N; ++i)
            {
                var a = new StringBuilder();
                var b = new StringBuilder();
                for (int j = 0; j < N; ++j)
                {
                    if ((i & (1 << j)) == 0) { a.Append(S[j]); } else { b.Append(S[j]); }
                }
                var key = new Tuple<string, string>(a.ToString(), b.ToString());
                if (!dict.ContainsKey(key)) { dict[key] = 0; }
                ++dict[key];
            }
            return dict;
        }
        static long Solve(int N, string S)
        {
            var T = new string(S.Reverse().ToArray());
            var a = MakeDictionary(S.Substring(0, N));
            var b = MakeDictionary(T.Substring(0, N));
            long sum = 0;
            foreach (var pair in a)
            {
                if (b.ContainsKey(pair.Key)) { sum += pair.Value * b[pair.Key]; }
            }
            return sum;
        }

        static void Main(string[] args)
        {
            int N = ReadInt();
            string S = Read();
            Console.WriteLine(Solve(N, S));
        }
    }
}