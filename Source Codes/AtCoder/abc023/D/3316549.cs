using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
  static long n = long.Parse(Console.ReadLine());
  static long[,] vertexes = new long[n,2];

	static void Main()
	{
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
    }
  
    Console.WriteLine(Search(0, long.MaxValue));  
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
    long[] checks = new long[n];
    for(long i = 0; i < n; i++)
    {
      if(testNum - vertexes[i,0] < 0) return false;
      checks[i] = (testNum - vertexes[i,0]) / vertexes[i,1];
    }
    Array.Sort(checks);
    for(long i = 0; i < n; i++)
    {
      if(checks[i] < i) return false;
    }
    return true;
  }
  
}