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
		long l = long.Parse(input[1]);
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long maxSum = 0;//???2?
    long maxPoint = 0;//??2????

    for(long i = 0; i < n-1; i++)
    {
      if(nums[i]+nums[i+1] > maxSum)
      {
        maxSum = nums[i]+nums[i+1];
        maxPoint = i;
      }
    }

    if(maxSum < l) Console.WriteLine("Impossible");
		else
    {
      Console.WriteLine("Possible");
      for(long i = 1; i < maxPoint+1; i++) Console.WriteLine(i);
      for(long i = n-1; i > maxPoint+1; i--) Console.WriteLine(i);
      Console.WriteLine(maxPoint+1);
    }
	}
}