using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc119c
{
    class Program
    {
        private static int A, B, C, N;
        private static IList<int> L;

        static void Main(string[] args)
        {
            var str = ReadIntList();
            N = str[0];
            //var ABC = str.Skip(1).ToList();
            A = str[1];
            B = str[2];
            C = str[3];
            L = new int[N];
            for (int i = 0; i < N; i++)
            {
                L[i] = ReadInt();
            }
            Console.WriteLine(dfs(0, 0, 0, 0));
            Console.ReadKey();
        }

        private static int dfs(int depth, int a, int b, int c)
        {
            if (depth == N)
            {
                if (a * b * c == 0)
                {
                    return 10000000;
                }
                return Math.Abs(A - a) + Math.Abs(B - b) + Math.Abs(C - c) - 30;
            }
            var ans = new int[4];
            ans[0] = dfs(depth + 1, a, b, c);
            ans[1] = dfs(depth + 1, a + L[depth], b, c) + 10;
            ans[2] = dfs(depth + 1, a, b + L[depth], c) + 10;
            ans[3] = dfs(depth + 1, a, b, c + L[depth]) + 10;
            //Console.WriteLine(String.Join(" ", ans));
            return ans.Min();
        }

        private static bool IsRange(int a, int from, int to) => (from <= a && a <= to);
        private static int ReadInt() => int.Parse(Console.ReadLine());
        private static List<int> ReadIntList() => Console.ReadLine().Split().Select(int.Parse).ToList();
        private static double ReadDouble() => double.Parse(Console.ReadLine());
        private static List<double> ReadDoubleList() => Console.ReadLine().Split().Select(double.Parse).ToList();
        private static List<int> Int2Digits(int a) => a.ToString().ToCharArray().Select(_ => int.Parse(_.ToString())).ToList();
    }
}