using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
static long mainVertex;
static long n = long.Parse(Console.ReadLine());
static long[] howlong = new long[n];//??k?????
static List<long>[] nextList = new List<long>[n];//????????????????

	static void Main()
	{
    for(int i = 0; i < n; i++) howlong[i] = -1;
    for(int i = 0; i < n; i++) nextList[i] = new List<long>();
    for(int i = 0; i < n-1; i++)
    {
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
    nextList[nums[0]-1].Add(nums[1]-1);//??????????2??????
    nextList[nums[0]-1].Add(nums[2]);
    nextList[nums[1]-1].Add(nums[0]-1);
    nextList[nums[1]-1].Add(nums[2]);
    }

    string[] inputSub = Console.ReadLine().Split(' ');
	  long q = long.Parse(inputSub[0]);
	  long k = long.Parse(inputSub[1]);
    k--;
    mainVertex = k;
    howlong[k] = 0;
    Length(k,0);//??k????k???????
    for(int i = 0; i < q; i++)
    {
    string[] input = Console.ReadLine().Split(' ');//Split???????????????????
    long xx = long.Parse(input[0]);
    long yy = long.Parse(input[1]);
    Console.WriteLine(howlong[xx-1]+howlong[yy-1]);
    }
	
	}

  static void Length(long vertexNum, long length)//????????k?????
  {
    for(int i = 0; i < nextList[vertexNum].Count(); i+=2)
    {
      long x = howlong[nextList[vertexNum][i]];
      long y = nextList[vertexNum][i+1];
      if(x == -1)
      {
        howlong[nextList[vertexNum][i]] = y + length;
        Length(nextList[vertexNum][i],howlong[nextList[vertexNum][i]]);
      }
    }
  }
  
}