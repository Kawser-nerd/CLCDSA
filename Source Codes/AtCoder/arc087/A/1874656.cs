using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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

        private static int Solve(int N, int[] A)
        {
            var dic = new Dictionary<int, int>();
            foreach (int a in A)
            {
                if (!dic.ContainsKey(a)) { dic[a] = 0; }
                ++dic[a];
            }
            int sum = 0;
            foreach (var pair in dic)
            {
                if (pair.Value > pair.Key) { sum += pair.Value - pair.Key; }
                if (pair.Value < pair.Key) { sum += pair.Value; }
            }
            return sum;
        }
        
        static void Main(string[] args)
        {
            int N = ReadInt();
            int[] a = ReadInts();
            Console.WriteLine(Solve(N, a));
        }
    }
}