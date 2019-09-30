using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{

static long k = long.Parse(Console.ReadLine());//int.Parse???????????
static long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);

	static void Main()
	{
		
    long minAnswer = SearchMin(0, 1000000000000000000);
		long maxAnswer = Search(0, 1000000000000000000); 
    if(minAnswer > maxAnswer) Console.WriteLine(-1);
    else Console.WriteLine(minAnswer + " " + maxAnswer);
	}

  static long Search(long min, long max)//?????????????
  {
    while (true)
    {
      long mid = min + (max - min) / 2;
      if(CheckMin(mid)) min = mid;//??????????????
      else max = mid;

      if(max - min <= 1)
      {
        if(CheckMin(max)) 
        {
          return max;//???????????????
        }
        else
        {
          return min;
        }
      break;
      }  
    }
  }

  static long SearchMin(long min, long max)//?????????????
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
    for(long i = 0; i < k; i++)
    {
      if(testNum < nums[i]) return false;
      long memo = testNum % nums[i];
      testNum -= memo;
    }
    if(testNum < 2) return false;
    return true;
  }

  static bool CheckMin(long testNum)
  {
    for(long i = 0; i < k; i++)
    {
      if(testNum < nums[i]) return true;
      long memo = testNum % nums[i];
      testNum -= memo;
    }
    if(testNum <= 2) return true;
    return false;
  }

  
}