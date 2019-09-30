using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayInt();
            var N = input[0];
            var M = input[1];
            var A = ReadArrayInt();
            Array.Sort(A);
            Array.Reverse(A);
            var matNum = new int[] { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
            var dp = new int[N + 1];
            for (int i = 1; i <= N; i++)
            {
                dp[i] = int.MinValue;
                for (int j = 0; j < M; j++)
                {
                    if (matNum[A[j]] <= i)
                    {
                        dp[i] = Math.Max(dp[i - matNum[A[j]]] + 1, dp[i]);
                    }
                }
            }
            var rem = N;
            var ans = new int[dp[N]];
            for (int i = 0; i < dp[N]; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (matNum[A[j]] <= rem && dp[rem - matNum[A[j]]] == dp[rem] - 1)
                    {
                        ans[i] = A[j];
                        rem -= matNum[A[j]];
                        break;
                    }
                }
            }

            Console.WriteLine(string.Join("", ans));
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}