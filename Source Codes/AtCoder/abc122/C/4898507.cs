using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace AtCoder.ABC122.C
{
    class Program
    {
        public static void Main()
        {
            // Solve(8, 3, "ACACTACG", new Tuple<int, int>[] {
            //     new Tuple<int, int>(3, 7),
            //     new Tuple<int, int>(2, 3),
            //     new Tuple<int, int>(1, 8)
            // });
            // Solve(10, 5, "ACACTACGAC", new Tuple<int, int>[] {
            //     new Tuple<int, int>(1, 9),
            //     new Tuple<int, int>(2, 9),
            //     new Tuple<int, int>(3, 9),
            //     new Tuple<int, int>(2, 10),
            //     new Tuple<int, int>(1, 10)
            // });

            var a = Console.ReadLine().Split(' ');
            var N = int.Parse(a[0]);
            var Q = int.Parse(a[1]);
            var S = Console.ReadLine();
            var pairs = new Tuple<int, int>[Q];
            for (int i = 0; i < Q; ++i)
            {
                var b = Console.ReadLine().Split(' ');
                pairs[i] = new Tuple<int, int>(int.Parse(b[0]), int.Parse(b[1]));
            }
            Solve(N, Q, S, pairs);
        }
        static void Solve(int N, int Q, string S, Tuple<int, int>[] pairs)
        {
            string searchWord = "AC";
            var t = new int[N + 1];
            //????????
            int foundIndex = S.IndexOf(searchWord);
            for (int i = 0; i < N - 1; ++i)
            {
                t[i + 1] = t[i] + ((S[i] == 'A' && S[i + 1] == 'C') ? 1 : 0);
            }
            for (int i = 0; i < Q; ++i)
            {
                Console.WriteLine(t[pairs[i].Item2 - 1] - t[pairs[i].Item1 - 1]);
            }
        }
        Dictionary<int, int> cache = new Dictionary<int, int>();
        static int Count(string S, int begin, int end)
        {
            return CountChar(S.Substring(begin, end - begin + 1), "AC");
        }
        public static int CountChar(string s, string c)
        {
            return (s.Length - (s.Replace(c, "").Length)) / c.Length;
        }
    }
}