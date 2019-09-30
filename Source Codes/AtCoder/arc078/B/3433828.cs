using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());
		List<long>[] nextList = new List<long>[n];//????????????
    long[] unionVertexes = new long[n];//???????
    long scoreFirst = 0;//???????????
    long scoreSecond = 0;//?????

    for(long i = 0; i < n; i++)
    {
      nextList[i] = new List<long>();
    }

    for(long i = 0; i < n-1; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      nextList[nums[0]-1].Add(nums[1]-1);
      nextList[nums[1]-1].Add(nums[0]-1);//????
    }

    while(true)
    {
      bool isChanged = false;
      for(long i = 1; i < n-1; i++)
      {
        if(nextList[i].Count() == 1)
        {
          unionVertexes[nextList[i][0]] += unionVertexes[i] + 1;//????????
          nextList[nextList[i][0]].Remove(i);
          nextList[i].RemoveAt(0);
          isChanged = true; 
        }
      }
      if(!(isChanged)) break;
    }

    scoreFirst = unionVertexes[0];
    scoreSecond = unionVertexes[n-1];

    while(true)
    {
      if(nextList[0][0] == n-1) break;
      else
      {
        scoreFirst += unionVertexes[nextList[0][0]] + 1;//????????
        nextList[nextList[0][0]].Remove(0);//0????0???
        long memo = nextList[nextList[0][0]][0];//0?????
        nextList[nextList[nextList[0][0]][0]].Remove(nextList[0][0]);//0???????????
        nextList[nextList[0][0]].RemoveAt(0);
        nextList[0].RemoveAt(0);
        nextList[0].Add(memo);
        nextList[memo].Add(0);
      }

      if(nextList[n-1][0] == 0) break;
      else
      {
        scoreSecond += unionVertexes[nextList[n-1][0]] + 1;
        nextList[nextList[n-1][0]].Remove(n-1);
        long memo = nextList[nextList[n-1][0]][0];
        nextList[nextList[nextList[n-1][0]][0]].Remove(nextList[n-1][0]);
        nextList[nextList[n-1][0]].RemoveAt(0);
        nextList[n-1].RemoveAt(0);
        nextList[n-1].Add(memo);
        nextList[memo].Add(n-1);
      }
    }
    
    Console.WriteLine((scoreFirst > scoreSecond) ? "Fennec" : "Snuke");
	}
}