using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
  static string[] input = Console.ReadLine().Split(' ');//Split???????????????????
  static long n = long.Parse(input[0]);
  static long a = long.Parse(input[1]);
  static long b = long.Parse(input[2]);
  static long[] nums = new long[n];

	static void Main()
	{
    for(long i = 0; i < n; i++)
    {
      nums[i] = long.Parse(Console.ReadLine());
    }
    //Array.Sort(nums);
    Console.WriteLine(Search(1, 1000000000));  
	}

  static long Search(long min, long max)//?????????????
  {
    while (true)
    {
      long mid = min + (max - min) / 2;
      if(Check(mid)) max = mid;//??????????????
      else min = mid;

      if(max - min <= 1)
      {
        if(Check(min)) 
        {
          return min;//???????????????
        }
        else
        {
          return max;
        }
      break;
      }  
    }
  }

  static bool Check(long testNum)
  {
    long attackCount = 0;
    long[] testNums = new long[n];
    for(long i = 0; i < n; i++)
    {
      testNums[i] = nums[i] - b*testNum;
    }
    for(long i = 0; i < n; i++)
    {
      if(testNums[i] > 0)
      {
        attackCount += (testNums[i]+a-b-1)/(a-b);
      }
    }
    //Console.WriteLine(attackCount+" "+ testNum);
    if(attackCount <= testNum) return true;
    return false;
  }
  
}