using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
static string[] input = Console.ReadLine().Split(' ');//Split???????????????????
static long xa = long.Parse(input[0]);
static long ya = long.Parse(input[1]);
static long xb = long.Parse(input[2]);
static long yb = long.Parse(input[3]);
static long n = long.Parse(Console.ReadLine());
static long[][] vertexes = new long[n][];//???????
static long[] LISnums;//x????y?????
static long[] rightMin;//???i+1??????????
static long LISnum = 1;//LIS??
static long compareMemo = 0;
static long LIScount = 0;//???????
static long riverseNum = 9999999999;

	static void Main()
	{
    for(long i = 0; i < n; i++)
    {
      vertexes[i] = new long[2];
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      vertexes[i][0] = nums[0];
      vertexes[i][1] = nums[1];
      if(Math.Min(xa,xb)<=nums[0] && nums[0]<=Math.Max(xa,xb)
        && Math.Min(ya,yb)<=nums[1] && nums[1]<=Math.Max(ya,yb)) LIScount++;
    }
    LISnums = new long[LIScount];
    rightMin = new long[LIScount];

    if((xb-xa)*(yb-ya) < 0)
    {
      ya = riverseNum - ya;
      yb = riverseNum - yb;
      for(long i = 0; i < n; i++) vertexes[i][1] = riverseNum - vertexes[i][1];
    }
    
    Array.Sort(vertexes, (a, b) => a[0].CompareTo(b[0]));
    double answer = (Math.Abs(xa-xb) + Math.Abs(ya-yb))*100;

    long memo = 0;
    for(long i = 0; i < n; i++)
    {
      if(Math.Min(xa,xb)<=vertexes[i][0] && vertexes[i][0]<=Math.Max(xa,xb)
        && Math.Min(ya,yb)<=vertexes[i][1] && vertexes[i][1]<=Math.Max(ya,yb))
      {
        LISnums[memo] = vertexes[i][1];
        memo++;
      }
    }
    
    if(LIScount >= 2) 
    {
      rightMin[0] = LISnums[0];

      for(long i = 1; i < LIScount; i++)
      {
        if(LISnums[i] > rightMin[LISnum-1])
        {
          rightMin[LISnum] = LISnums[i];
          LISnum++;
        }else
        {
          compareMemo = LISnums[i];
          rightMin[Search(0, LISnum-1)] = LISnums[i];//???????????
        }
      }
    }else LISnum = LIScount;

    if(LISnum < Math.Min(Math.Abs(xa-xb), Math.Abs(ya-yb))+1)
    {
      answer += (-20+5*Math.PI)*LISnum;
    }else
    {
      if(LISnum >= 1) answer += (-20+5*Math.PI)*(LISnum-1);
      answer += 10*Math.PI - 20;
    }
  
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