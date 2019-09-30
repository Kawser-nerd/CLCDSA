using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            int P = int.Parse(Console.ReadLine());
            int[] M = new int[1 << P];
            string[] parts = Console.ReadLine().Split();
            for (int i = 0; i < M.Length; i++)
            {
                M[i] = int.Parse(parts[i]);
            }
            long[,] price = new long[P, 1 << P];
            long[, ,] dp = new long[P, 1 << P, P + 1];
            for (int i = 0; i < P; i++)
            {
                parts = Console.ReadLine().Split();
                int idx = 0;
                for (int j = 0; j < 1 << P; j += (1 << (i + 1)))
                {
                    price[i, j] = long.Parse(parts[idx++]);
                    for (int k = 0; k <= P; k++)
                        dp[i, j, k] = long.MaxValue / 3;
                }
            }
            for (int i = 0; i < P; i++)
            {
                for (int j = 0; j < 1 << P; j += (1 << (i + 1)))
                {
                    for (int k = 0; k <= P; k++)
                    {
                        if (i == 0)
                        {
                            if (k >= P - M[j] && k >= P - M[j + 1])
                            {
                                dp[i, j, k] = 0;
                            }
                            else if (k + 1 >= P - M[j] && k + 1 >= P - M[j + 1])
                            {
                                dp[i, j, k] = price[i, j];
                            }
                        }
                        else
                        {
                            dp[i, j, k] = Math.Min(long.MaxValue / 3, dp[i - 1, j, k] + dp[i - 1, j + (1 << i), k]);
                            if (k < P)
                                dp[i, j, k] = Math.Min(dp[i, j, k], dp[i - 1, j, k + 1] + dp[i - 1, j + (1 << i), k + 1] + price[i, j]);
                        }
                    }
                }
            }
            Console.WriteLine("Case #" + CASE + ": " + dp[P - 1, 0, 0]);
        }
    }
}
