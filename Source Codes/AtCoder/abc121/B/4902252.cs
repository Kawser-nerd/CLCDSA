using System;
using System.Linq;

namespace AtCoder.ABC121.B
{
    class Program
    {
        static void Rep(int n, Action<int> action) { for (var i = 0; i < n; ++i) { action(i); } }
        static void Rep(int n, int s, Action<int> action) { for (var i = s; i < n; ++i) { action(i); } }

        public static void Main()
        {
            // Solve(3, 2, 2, 1);
            // Solve(5, 5, 2, 3);
            // Solve(2, 4, 2, 4);

            // Solve(2, 3, -10, new int[] { 1, 2, 3 }, new int[,] { { 3, 2, 1 }, { 1, 2, 2 } });

            // return;

            var str1 = Console.ReadLine().Split(' ');
            var N = int.Parse(str1[0]);
            var M = int.Parse(str1[1]);
            var C = int.Parse(str1[2]);
            var str2 = Console.ReadLine().Split(' ');
            var Bs = new int[M];
            Rep(M, i =>
            {
                Bs[i] = int.Parse(str2[i]);
            });
            var As = new int[N, M];
            Rep(N, i =>
            {
                var str3 = Console.ReadLine().Split(' ');
                Rep(M, j =>
                {
                    As[i, j] = int.Parse(str3[j]);
                });
            });
            Solve(N, M, C, Bs, As);
        }

        static void Solve(int N, int M, int C, int[] Bs, int[,] As)
        {
            int count = 0;
            Rep(N, i =>
            {
                var sum = 0;
                Rep(M, j =>
                {
                    sum += As[i, j] * Bs[j];
                });
                if (sum + C > 0)
                {
                    ++count;
                }
            });
            Console.WriteLine(count);
        }
    }
}