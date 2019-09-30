using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] defaultPass = new long[n+1];
    long[] skipPass = new long[n];
    long sumMemo = 0;
    long answer = 0;
    
    for(long i = 1; i < n-1; i++)
    {
      defaultPass[i] = Math.Abs(nums[i] - nums[i-1]);
      skipPass[i] = Math.Abs(nums[i+1] - nums[i-1]);
    }
    defaultPass[0] = Math.Abs(nums[0]);
    skipPass[0] = Math.Abs(nums[1]);
    defaultPass[n-1] = Math.Abs(nums[n-1] - nums[n-2]);
    defaultPass[n] = Math.Abs(nums[n-1]);
    skipPass[n-1] = Math.Abs(nums[n-2]);

    for(long i = 0; i <= n; i++)
    {
      sumMemo += defaultPass[i];
      //Console.WriteLine(sumMemo);
    }

    for(long i = 0; i < n; i++)
    {
      answer = sumMemo;
      //Console.WriteLine(answer);
      answer -= defaultPass[i] + defaultPass[i+1];
      //Console.WriteLine(answer);
      answer += skipPass[i];
      Console.WriteLine(answer);
    }
	}
}