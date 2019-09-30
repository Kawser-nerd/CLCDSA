using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        private static bool Solve(int N, int[] A)
        {
            var dic = new Dictionary<int, int>();
            foreach (var a in A)
            {
                if (!dic.ContainsKey(a)) { dic[a] = 0; }
                ++dic[a];
            }
            switch (dic.Count)
            {
            case 1:
                return A[0] == N - 1 || A[0] <= N / 2;
            case 2:
                int min = dic.Keys.Min();
                int max = dic.Keys.Max();
                if (max - min > 1) { return false; }
                int n = max - dic[min];
                return 1 <= n && n <= dic[max] / 2;
            default:
                return false;
            }
        }
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] A = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            Console.WriteLine(Solve(N, A) ? "Yes" : "No");
        }
    }
}