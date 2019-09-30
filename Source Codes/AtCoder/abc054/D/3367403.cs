using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long ma = long.Parse(input[1]);
    long mb = long.Parse(input[2]);
    long[,] vertexes = new long[n,3];
    long answer = long.MaxValue-99999;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
      vertexes[i,2] = nums[2];
    }

    long[][][] dp = new long[n+1][][];
    for(long i = 0; i <= n; i++)
    {
      dp[i] = new long[ma*n+1][];
      for(long j = 0; j <= ma*n; j++)
      {
        dp[i][j] = new long[mb*n+1];
      }
    }

    for(long nL = 0; nL <= n; nL++)
    {
      for(long maL = 0; maL <= ma*n; maL++)
      {
        for(long mbL = 0; mbL <= mb*n; mbL++)
        {
          if(nL + maL + mbL > 0) dp[nL][maL][mbL] = long.MaxValue-99999;
          if(nL-1>=0 && maL-vertexes[nL-1,0] >= 0 && mbL-vertexes[nL-1,1] >= 0)
          {
            dp[nL][maL][mbL] = Math.Min
              (dp[nL][maL][mbL], dp[nL-1][maL-vertexes[nL-1,0]][mbL-vertexes[nL-1,1]]+vertexes[nL-1,2]);
          }
          if(nL-1>=0)
          {
            dp[nL][maL][mbL] = Math.Min(dp[nL][maL][mbL], dp[nL-1][maL][mbL]);
          }
          if(ma*mbL == mb*maL && maL != 0) answer = Math.Min(answer, dp[nL][maL][mbL]);
          //Console.WriteLine(nL+" "+maL+" "+mbL+" "+dp[nL][maL][mbL]);
        }
      }
    }
    if(answer == long.MaxValue-99999) answer = -1;
		Console.WriteLine(answer);
	}
}