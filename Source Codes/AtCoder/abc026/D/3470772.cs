using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{

static string[] input = Console.ReadLine().Split(' ');//Split???????????????????
static double a = double.Parse(input[0]);
static double b = double.Parse(input[1]);
static double c = double.Parse(input[2]);
static long test = 0;

	static void Main()
	{
		Console.WriteLine(Search(0, 9999d));//WriteLine?Write?????????????
	}

  static double Search(double min, double max)//?????????????
  {
    while (true)
    {
      test++;
      //Console.WriteLine(min+" "+max);
      double mid = min + (max - min) / 2;
      if(Check(mid)) min = mid;//??????????????
      else max = mid;

      if(test > 10000)
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

  static bool Check(double testNum)
  {
    if(100 - a*testNum - b*Math.Sin(c*testNum*Math.PI) >= 0) return true;
    return false;
  }
  
}