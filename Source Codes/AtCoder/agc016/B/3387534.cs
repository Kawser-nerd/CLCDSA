using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long maxNum = nums.Max();
    long minNum = nums.Min();
    long minCount = 0;//????????
    long maxCount = 0;

    for(long i = 0; i < n; i++)
    {
      if(nums[i] == minNum) minCount++;
    }
    maxCount = n - minCount;

    if(maxNum - minNum >= 2) Console.WriteLine("No");
    else if(maxNum - minNum == 0)
    {
      if(maxNum <= n/2 || maxNum == n-1) Console.WriteLine("Yes");
      else Console.WriteLine("No");
    }else if(maxNum - minNum == 1)
    {
      if(maxCount == 1) Console.WriteLine("No");
      else if(minCount+1 <= maxNum && maxNum <= minCount + (maxCount/2)) Console.WriteLine("Yes");
      else Console.WriteLine("No");
    }

	}
}