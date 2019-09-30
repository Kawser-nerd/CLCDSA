using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{

  static string[] input = Console.ReadLine().Split(' ');//Split???????????????????
  static long r = long.Parse(input[0]);
  static long b = long.Parse(input[1]);
  static string[] inputSub = Console.ReadLine().Split(' ');//Split???????????????????
  static long x = long.Parse(inputSub[0]);
  static long y = long.Parse(inputSub[1]);

	static void Main()
	{
      Console.WriteLine(Search(0, 1000000000000000000));  
	}

  static long Search(long min, long max)//?????????????
  {
    while (true)
    {
      long mid = min + (max - min) / 2;
      if(Check(mid)) min = mid;//??????????????
      else max = mid;

      if(max - min <= 1)
      {
        if(Check(max)) 
        {
          return max;//??????
        }
        else
        {
          return min;
        }
      break;
      }  
    }
  }

  static bool Check(long testNum)
  {
    if((long)(r-testNum)/(x-1) + (b-testNum)/(y-1) >= testNum
    && r-testNum >= 0 && b - testNum >= 0) return true;//??????
    return false;
  }
  
}