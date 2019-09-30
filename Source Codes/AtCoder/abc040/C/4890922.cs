using System;
using System.Linq;

namespace test
{
    class MainClass
    {
        public static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());
            var h = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var dp = new int[n];
            for (var i = 0; i < n; i++) dp[i] = int.MaxValue;

            dp[0] = 0;

            for(var i = 1; i< dp.Length; i++)
            {
                dp[i] = dp[i - 1] + Math.Abs(h[i] - h[i - 1]);

                if (i == 1) continue;

                dp[i] = Math.Min(dp[i], dp[i - 2] + Math.Abs(h[i] - h[i - 2]));

            }

            Console.WriteLine(dp[n - 1]); 
        }
    }
}