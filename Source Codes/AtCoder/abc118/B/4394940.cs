using System;
using System.Linq;
using System.Collections.Generic;

namespace ABC118
{
    public class B
    {
        public void Solve()
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            int[] c = new int[M];
            for (int i = 0; i < N; i++)
            {
                string[] ss = Console.ReadLine().Split(' ');
                int K = int.Parse(ss[0]);
                for (int j = 0; j < K; j++)
                {
                    int A = int.Parse(ss[j + 1]);
                    c[A - 1]++;
                }
            }
            int res = 0;
            for (int i = 0; i < M; i++)
            {
                if (c[i] == N) { res++; }
            }
            Console.WriteLine(res);
        }
    }
}

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new ABC118.B().Solve();
        }
    }
}