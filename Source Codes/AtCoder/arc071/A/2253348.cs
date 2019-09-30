using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private const int MODULO = 1000000007;
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        static string Solve(int n, string[] S)
        {
            int[] mins = Enumerable.Repeat(int.MaxValue, 26).ToArray();
            foreach (string s in S)
            {
                int[] counts = new int[26];
                foreach (char c in s) { ++counts[c - 'a']; }
                for (int i = 0; i < 26; ++i) { mins[i] = Math.Min(counts[i], mins[i]); }
            }
            var sb = new StringBuilder();
            for (int i = 0; i < 26; ++i) { sb.Append(new string((char)('a' + i), mins[i])); }
            return sb.ToString();
        }
        static void Main(string[] args)
        {
            int n = ReadInt();
            var S = new string[n];
            for (int i = 0; i < n; ++i) { S[i] = Read(); }
            Console.WriteLine(Solve(n, S));
        }
    }
}