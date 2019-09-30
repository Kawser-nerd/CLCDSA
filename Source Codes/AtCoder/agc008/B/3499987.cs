using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long k = long.Parse(input[1]);
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] sums = new long[n];//???
    long[] sumsPlus = new long[n];//???????
    long answer = 0;

    sums[0] = nums[0];
    if(nums[0] > 0) sumsPlus[0] = nums[0];
    for(long i = 1; i < n; i++)//??????
    {
      sums[i] = sums[i-1] + nums[i];
      if(nums[i] > 0) sumsPlus[i] = sumsPlus[i-1] + nums[i];
      else sumsPlus[i] = sumsPlus[i-1];
    }

    for(long i = 0; i < n-k+1; i++)
    {
      long memo = 0;
      if(i > 0) memo = sumsPlus[i-1];//?????
      memo += sumsPlus[n-1] - sumsPlus[k+i-1];//?????
      if(i > 0)
      {
        if(sums[k+i-1] - sums[i-1] > 0) memo += sums[k+i-1] - sums[i-1];
      }else
      {
        if(sums[k+i-1] > 0) memo += sums[k+i-1];
      }
      answer = Math.Max(answer, memo);
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}