using System;

namespace app
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] array = new int[N];
            int[] dp = new int[N];
            dp[0] = 1;

            for (int i = 0; i < N; i++)
            {
                array[i] = int.Parse(Console.ReadLine());
            }

            for (int i = 1; i < N; i++)
            {
                int m = 0;
                for (int j = 0; j < i; j++)
                {
                    if (array[j] < array[i])
                    {
                        m = Math.Max(m, dp[j]);
                    }
                }
                dp[i] = m + 1;
            }
            
            int t = 0;
            for (int i = 0; i < N; i++)
                t = Math.Max(t, dp[i]);
            int ans = N - t;
            
            Console.WriteLine(ans);
        }
    }
}