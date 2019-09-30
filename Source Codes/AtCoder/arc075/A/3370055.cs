using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
    long[] nums = new long[n];
		for(long i = 0; i < n; i++)
    {
      nums[i] = long.Parse(Console.ReadLine());
    }
    long[][] dp = new long[n+1][];
		for(long i = 0; i <= n; i++)
    {
      dp[i] = new long[10001];
    }
    dp[0][0] = 1;

    for(long num = 0; num <= n; num++)
    {
      for(long sum = 0; sum <= 10000; sum++)
      {
        if(num>=1)
        {
          if(sum-nums[num-1] >= 0)
          {
            if(dp[num-1][sum-nums[num-1]] == 1) dp[num][sum] = 1;
          }
        }
        if(num>=1)
        {
          if(dp[num-1][sum] == 1) dp[num][sum] = 1;
        }
      }
    }

    long answer = 0;
    for(long i = 0; i < 10000; i++)
    {
      if(dp[n][i] == 1 && i % 10 != 0) answer = i;
    }
		
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}