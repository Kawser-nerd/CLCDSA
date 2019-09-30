using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static long n = long.Parse(Console.ReadLine());
static long[] nums = new long[n];
static long[][] numsSub = new long[n][];
static long[] rightMin = new long[n];//???i+1??????????
static long answer = 1;
static long compareMemo = 0;

	static void Main()
	{
    for(long i = 0; i < n; i++)
    {
      numsSub[i] = new long[2];
      string[] input = Console.ReadLine().Split(' ');
  		numsSub[i][0] = long.Parse(input[0]);
  		numsSub[i][1] = long.Parse(input[1]);
    }
    var sorted = numsSub.OrderBy(a => a[0]).ThenByDescending(a => a[1]).ToList();
    
    for(long i = 0; i < n; i++)
    {
      nums[i] = sorted[(int)i][1];
    }
    
    rightMin[0] = nums[0];

    for(long i = 1; i < n; i++)
    {
      if(nums[i] > rightMin[answer-1])
      {
        rightMin[answer] = nums[i];
        answer++;
      }else
      {
        compareMemo = nums[i];
        rightMin[Search(0, answer-1)] = nums[i];//???????????
      }
    }
    //Console.WriteLine(nums[0]+" "+nums[1]+" "+nums[2]+" "+nums[3]+" "+nums[4]+" ");
		Console.WriteLine(answer);
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
    if(rightMin[testNum] >= compareMemo) return true;//??????????????????????
    return false;
  }

}