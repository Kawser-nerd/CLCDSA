using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC005D_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            int[,] map = new int[N, N];
            for(int i = 0; i < N; i++)
            {
                var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < N; j++) map[i, j] = line[j];
            }
            var Q = int.Parse(Console.ReadLine());
            int[] P = new int[Q];
            for (int i = 0; i < Q; i++) P[i] = int.Parse(Console.ReadLine());

            int[,] dp = new int[N + 1, N + 1];
            dp[N - 1, N - 1] = map[N - 1, N - 1];
            for(int i = N - 1; i >= 0; i--)
            {
                for(int j = N - 1; j >= 0; j--)
                {
                    dp[i, j] = dp[i + 1, j] + dp[i, j + 1] - dp[i + 1, j + 1] + map[i, j];
                }
            }

            int Pmax = P.Max();
            int[] maxs = new int[Pmax + 1];
            for(int p = 1; p < Pmax + 1; p++)
            {
                int max = 0;
                for (int a = 1; a <= N; a++)
                {
                    if (p % a != 0) continue;
                    int b = p / a;

                    for (int i = 0; i <= N - a; i++)
                    {
                        for (int j = 0; j <= N - b; j++)
                        {
                            int s = dp[i, j] - dp[i + a, j] - dp[i, j + b] + dp[i + a, j + b];
                            max = Math.Max(max, s);
                        }
                    }
                }
                maxs[p] = max;
            }
            
            for(int i = 0; i < Pmax; i++)
            {
                if (maxs[i + 1] < maxs[i]) maxs[i + 1] = maxs[i];
            }

            for(int i = 0; i < Q; i++)
            {
                Console.WriteLine(maxs[P[i]]);
            }
            Console.ReadKey();
        }
    }
}