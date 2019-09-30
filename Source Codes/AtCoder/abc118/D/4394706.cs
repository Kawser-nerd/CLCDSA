using System;
using System.Linq;
using System.Collections.Generic;

namespace ABC118
{
    public class D
    {
        int INF = 1000000000;
        public void Solve()
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            int[] A = new int[M];
            string[] As = Console.ReadLine().Split(' ');
            for (int i = 0; i < M; i++) { A[i] = int.Parse(As[i]); }
            A = A.OrderByDescending(x => x).ToArray();

            int[] dp = new int[N + 1];
            dp[0] = 0;
            int[] num = new int[9] {2, 5, 5, 4, 5, 6, 3, 7, 6};

            for (int i = 1; i < N + 1; i++)
            {
                int max = -INF;
                for (int j = 0; j < A.Length; j++)
                {
                    if (i - num[A[j] - 1] >= 0)
                    {
                        max = Max<int>(max, dp[i - num[A[j] - 1]] + 1);
                    }
                }
                dp[i] = max;
            }
            int Nc = N;
            for (int i = 0; i < dp[N]; i++)
            {
                for (int j = 0; j < A.Length; j++)
                {
                    if (Nc - num[A[j] - 1] >= 0 && dp[Nc - num[A[j] - 1]] == dp[Nc] - 1)
                    {
                        Console.Write("{0}", A[j]);
                        Nc -= num[A[j] - 1];
                        break;
                    }
                }
            }
            Console.Write("\n");
        }

        T Min<T>(params T[] nums) where T : IComparable
        {
            if (nums.Length == 0) { return default(T); }

            T min = nums[0];
            for (int i = 0; i < nums.Length; i++) { min = (min.CompareTo(nums[i]) < 0) ? min : nums[i]; }

            return min;
        }

        T Max<T>(params T[] nums) where T : IComparable
        {
            if (nums.Length == 0) { return default(T); }

            T max = nums[0];
            for (int i = 0; i < nums.Length; i++) { max = (max.CompareTo(nums[i]) > 0) ? max : nums[i]; }

            return max;
        }
    }
}

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new ABC118.D().Solve();
        }
    }
}