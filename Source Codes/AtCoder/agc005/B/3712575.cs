using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
static long n = long.Parse(Console.ReadLine());//long.Parse?string?long????
static long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
static long[] positions = new long[n];//???????????????
static long[] bits = new long[n+2];
static long middleNum = 0;
static long answer = 0;

	static void Main()
	{
    for(int i = 0; i < n; i++)
    {
      positions[nums[i]-1] = i;
    }

    for(int i = 0; i < n; i++)
    {
      middleNum = positions[i];
      long leftCount = SearchLeft(0,positions[i]);
      long rightCount = SearchRight(0,n-1-positions[i]);
      //Console.WriteLine(leftCount+" "+rightCount +" "+ answer);
      answer += (i+1)*(leftCount+1)*(rightCount+1);//??×??????????????
      BitAdd(positions[i]+1,1);//?????1???
    }
    
		Console.WriteLine(answer);
	}

  static void BitAdd(long i, long x)//BIT?i???x??
  {
    while(i <= n)
    {
      bits[i] += x;
      i += i&-i;
    }
  }

  static long BitSum(long i)//BIT?i????????
  {
    long sum = 0;
    while(i > 0)
    {
      sum += bits[i];
      i -= i&-i;
    }
    return sum;
  }

  static long SearchLeft(long min, long max)//?????????????
  {
    while (true)
    {
      long mid = min + (max - min) / 2;
      if(CheckLeft(mid)) min = mid;//??????????????
      else max = mid;

      if(max - min <= 1)
      {
        if(CheckLeft(max)) 
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

  static long SearchRight(long min, long max)//?????????????
  {
    while (true)
    {
      long mid = min + (max - min) / 2;
      if(CheckRight(mid)) min = mid;//??????????????
      else max = mid;

      if(max - min <= 1)
      {
        if(CheckRight(max)) 
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

  static bool CheckLeft(long testNum)
  {
    if(BitSum(middleNum) - BitSum(middleNum-testNum) == 0) return true;
    return false;
  }

  static bool CheckRight(long testNum)
  {
    if(BitSum(middleNum+1+testNum) - BitSum(middleNum+1) == 0) return true;
    return false;
  }
  
}