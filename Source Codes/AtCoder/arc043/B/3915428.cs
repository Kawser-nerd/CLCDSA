using System;
using System.Linq;

namespace arc043_b
{
    class Program
    {
        static int[] arr;
        static bool IsOK(int index, int key)
        {
            if (arr[index] <= key) return true;
            else return false;
        }
        static int Binary_search(int key)
        {
            int ok = -1;
            int ng = arr.Count();

            while (Math.Abs(ok - ng) > 1)
            {
                int mid = ng + (ok - ng) / 2;

                if (IsOK(mid, key)) ok = mid;
                else ng = mid;
            }

            return ok;
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine()); int mod = 1000000007;
            arr = new int[n]; for (int i = 0; i < n; i++) arr[i] = int.Parse(Console.ReadLine());
            Array.Sort(arr);
            long[,] dp = new long[n, 4];
            for (int i = 0; i < n; i++) dp[i, 0] = 1;
            long[,] sum = new long[n + 1, 4];
            for (int i = 0; i < n; i++)
            {
                int half = Binary_search(arr[i] / 2);
                if (half >= 0)
                {
                    for (int j = 1; j < 4; j++)
                    { dp[i, j] += sum[half + 1, j - 1]; dp[i, j] %= mod; }
                }
                for (int j = 0; j < 4; j++)
                {
                    sum[i + 1, j] = sum[i, j] + dp[i, j]; sum[i + 1, j] %= mod;
                }
            }
            long ret = 0;
            for (int i = 0; i < n; i++)
            { ret += dp[i, 3]; ret %= mod; }
            Console.WriteLine(ret);
        }
    }
}