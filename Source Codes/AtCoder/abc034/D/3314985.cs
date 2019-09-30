using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static string[] input = Console.ReadLine().Split(' ');
static long n = long.Parse(input[0]);
static long k = long.Parse(input[1]);
static long[,] vertexes = new long[n,2];

	static void Main()
	{
    for(int i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
    }

  Console.WriteLine((double)Search(0, 1000000000000000000)/10000000000000000d);
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

  static bool Check(long testNum)
  {
    double[] checkArray = new double[n];
    for(int i = 0; i < n; i++)//???n???
    {
      checkArray[i] = (vertexes[i,0] * 0.01d * vertexes[i,1]) - 
        (testNum / 1000000000000000000d * vertexes[i,0]);
    }
    Array.Sort(checkArray);
    Array.Reverse(checkArray);
    
    double memo = 0d;
    for(int i = 0; i < k; i++)//?????k???
    {
      memo += checkArray[i];
    }
    if(memo >= 0) return true;
    return false;
  }
  
}