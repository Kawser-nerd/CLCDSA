using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long w = long.Parse(input[1]);
    long[,] vertexes = new long[n,2];//???????
    long[,,] dp = new long[n+1,n+1,3*n+1];//dp[??????????????] = ??????
    long answer = 0;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
    }

    for(int i = 1; i <= n; i++)
    {
      for(int j = 0; j <= n; j++)
      {
        for(int k = 0; k <= 3*n; k++)
        {
          dp[i,j,k] = dp[i-1,j,k];//??????
          if(j-1 >= 0 && k-(vertexes[i-1,0]-vertexes[0,0]) >= 0)
          {
            dp[i,j,k] = 
              Math.Max(dp[i,j,k],dp[i-1,j-1,k-(vertexes[i-1,0]-vertexes[0,0])] + vertexes[i-1,1]);
          }
        }
      }
    }
    
    for(int i = 0; i <= n; i++)
    {
      for(int j = 0; j <= n; j++)
      {
        for(int k = 0; k <= 3*n; k++)
        {
          if(vertexes[0,0]*j + k <= w)
            answer = Math.Max(dp[i,j,k], answer);
        }
      }
    }
    
		Console.WriteLine(answer);
	}
}