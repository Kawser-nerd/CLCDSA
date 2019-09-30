using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
    long[] checkNum = new long[2];
    long answer = 0;
    long minDifference = long.MaxValue;
		long n = long.Parse(Console.ReadLine());
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    Array.Sort(nums);//???

    if(nums[n-1] % 2 == 0)
    {
      checkNum[0] = nums[n-1]/2;
      checkNum[1] = nums[n-1]/2;
    }else
    {
    checkNum[0] = nums[n-1]/2;
    checkNum[1] = nums[n-1]/2+1;//???
    }

    for(long num = 0; num < n-1; num++)
    {
      if(Math.Min(Math.Abs(checkNum[0]-nums[num]), Math.Abs(checkNum[1]-nums[num]))
        < minDifference)
      {
        minDifference = Math.Min(Math.Abs(checkNum[0]-nums[num]), Math.Abs(checkNum[1]-nums[num]));
        answer = nums[num];
      }
    }

		Console.WriteLine(nums[n-1] + " " + answer);
	}
}