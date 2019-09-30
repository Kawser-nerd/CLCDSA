using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    Array.Sort(nums);//???
    long[] sums = new long[n];//i????
    long answer = 1;

    sums[0] = nums[0];
    for(long i = 1; i < n; i++)
    {
      sums[i] = sums[i-1] + nums[i];
    }

    for(long i = n-2; i >= 0; i--)
    {
      if(sums[i]*2 >= nums[i+1]) answer++;
      else break;
    }
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}