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

      long min = 0;
      long max = 1000000000000000000;

      while (true)//2????????????
      {
        long mid = min + (max - min) / 2;
        if(Check(mid)) min = mid;//??????????????
        else max = mid-1;
        //Console.WriteLine(min+" "+max);

        if(max - min <= 1)
        {
          if(Check(max) && (!Check(max+1))) 
          {
            Console.WriteLine(max);//??????
          }
          else if(Check(min) && (!Check(min+1))) 
          {
            Console.WriteLine(min);
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