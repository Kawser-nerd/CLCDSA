using System;

namespace abc006_4
{
    class Program
    {
        static int LowerBound(int[] arr, int value)
        {
            int low = 0;
            int high = arr.Length;
            int mid;
            while (low < high)
            {
                mid = ((high - low) / 2) + low;
                if (arr[mid] <= value)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] dp = new int[n + 1]; dp[0] = -1;
            for (int i = 1; i <= n; i++) dp[i] = 10000000;
            for (int i = 0; i < n; i++)
            {
                int x = int.Parse(Console.ReadLine());
                dp[LowerBound(dp, x)] = x;
            }
            Console.WriteLine(n + 1 - LowerBound(dp, 1000000));
        }
    }
}