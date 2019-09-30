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

        static bool Solve(string S)
        {
            int N = S.Length;
            int i = 0;
            while (i < N)
            {
                if (i + 6 <= N && S.Substring(i, 6) == "eraser")
                {
                    i += 6;
                }
                else if (i + 5 <= N && S.Substring(i, 5) == "erase")
                {
                    i += 5;
                }
                else if (i + 7 <= N && S.Substring(i, 7) == "dreamer")
                {
                    if (i + 7 < N && S[i + 7] == 'a')
                    {
                        i += 5;
                    }
                    else
                    {
                        i += 7;
                    }
                }
                else if (i + 5 <= N && S.Substring(i, 5) == "dream")
                {
                    i += 5;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve(Read()) ? "YES" : "NO");
        }
    }
}