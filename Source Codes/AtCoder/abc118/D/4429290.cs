using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc118d
{
    class Program
    {
        static void Main(string[] args)
        {
            var nm = ReadIntList();
            var N = nm[0];
            var M = nm[1];
            var honsuu = new int[10] { int.MaxValue, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; // ?????
            var A = ReadIntList().OrderBy(n => honsuu[n]).ThenByDescending(n => n).ToList();


            var dp = new int[N + 1]; // dp[i] : i ???????????????

            dp[0] = 0;
            for (int i = 1; i <= N; i++)
            {
                dp[i] = int.MinValue;
                foreach (var a in A)
                {
                    if (i < honsuu[a])
                        break;
                    dp[i] = Math.Max(dp[i - honsuu[a]] + 1, dp[i]);
                }
            }
            var output = new int[dp[N]];
            
            for(int i = 0; i < output.Length; i++)
            {
                foreach (var a in A.OrderByDescending(n=>n))
                {
                    if (honsuu[a] <= N && dp[N - honsuu[a]] == dp[N] - 1)
                    {
                        output[i] = a;
                        N -= honsuu[a];
                        break;
                    }
                }
            }
            Console.WriteLine(String.Join("", output));
#if DEBUG
            Console.ReadKey();
#endif
        }

        private static bool IsRange(int a, int from, int to) => (from <= a && a <= to);
        private static int ReadInt() => int.Parse(Console.ReadLine());
        private static List<int> ReadIntList() => Console.ReadLine().Split().Select(int.Parse).ToList();
        private static List<int> Int2Digits(int a) => a.ToString().ToCharArray().Select(_ => int.Parse(_.ToString())).ToList();
    }
}