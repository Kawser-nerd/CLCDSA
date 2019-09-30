using System;
using System.Collections.Generic;
using System.Linq;

namespace _041D
{
    internal class Program
    {
        public static int length(int S)
        {
            var ans = 0;
            for (var i = 0; i < 32; i++)
            {
                if (S%2 == 1)
                {
                    ans++;
                }
                S >>= 1;
            }
            return ans;
        }

        public static bool[] SetToBools(int Set, int n)
        {
            var res = new bool[n];
            for (var i = 0; i < n; i++)
            {
                if (Set%2 == 1)
                {
                    res[i] = true;
                }
                Set >>= 1;
            }
            return res;
        }

        private static void Main(string[] args)
        {
            var buffer = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var N = buffer[0];
            var M = buffer[1];
            var lists = new List<int>[N];
            var table = new bool[N, N];

            for (var i = 0; i < N; i++)
            {
                lists[i] = new List<int>();
            }
            for (var i = 0; i < M; i++)
            {
                buffer = Console.ReadLine().Split(' ').Select(int.Parse).Select(x => x - 1).ToArray();
                lists[buffer[1]].Add(buffer[0]);
                table[buffer[0], buffer[1]] = true;
            }
            var dp = new long[1 << N + 1];
            dp[0] = 1;
            var s = 1;
            for (s = 1; s <= 1 << N; s++)
            {
                var xs = 0;
                var set = SetToBools(s, N);
                for (var j = 0; j < N; j++)
                {
                    if (!set[j]) continue;
                    var flag = true;
                    for (var k = 0; k < N; k++)
                    {
                        if (j == k || !set[k])
                        {
                        }
                        else if (table[j, k]) // j => k ???????
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        xs += 1 << j;
                    }
                }
                var xss = SetToBools(xs, N);
                var sum = 0L;
                for (var i = 0; i < N; i++)
                {
                    if (!xss[i]) continue;
                    sum += dp[s - (1 << i)];
                }
                dp[s] = sum;
            }
            Console.WriteLine(dp[(1 << N) - 1]);
        }
    }
}