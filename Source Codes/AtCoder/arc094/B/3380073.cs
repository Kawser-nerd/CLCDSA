using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static long q = long.Parse(Console.ReadLine());//int.Parse???????????
static long[,] vertexes = new long[q,2];//???????
static long[] checkNum = new long[2];
	static void Main()
	{
    for(long i = 0; i < q; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
    }
    
		for(long i = 0; i < q; i++)
    {
      checkNum[0] = vertexes[i,0];
      checkNum[1] = vertexes[i,1];
      if(checkNum[0]!=checkNum[1]) Console.WriteLine(Search(0, checkNum[0]*checkNum[1]));
      else Console.WriteLine(2*checkNum[0]-2);
    }
	}

  static long Search(long min, long max)//?????????????
  {
  while (true)
    {
    //Console.WriteLine(min+" "+max);
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
  try
    {
      checked
      {
        long test = ((testNum+2)/2)*((testNum+3)/2);
      }
    }
    catch(OverflowException ex)//????????????
    {
      return false;
    }
  
  if(((testNum+2)/2)*((testNum+3)/2) < checkNum[0]*checkNum[1]) return true;
  return false;
  }
  
}