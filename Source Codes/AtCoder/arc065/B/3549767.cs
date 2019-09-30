using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{

static string[] input = Console.ReadLine().Split(' ');
static long n = long.Parse(input[0]);
static long k = long.Parse(input[1]);
static long l = long.Parse(input[2]);
static long[][] parents = new long[n][];//??????????
static long[] answers = new long[n];
  
	static void Main()
	{
    for(long i = 0; i < n; i++)
    {
      parents[i] = new long[4];
      parents[i][0] = i;
      parents[i][1] = i;
      parents[i][3] = i;
    }
    
    for(long i = 0; i < k; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      if(whatParentA(nums[0]-1) != whatParentA(nums[1]-1))
        parents[whatParentA(nums[0]-1)][0] = whatParentA(nums[1]-1);//???????????2??????????
    }

    for(long i = 0; i < l; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      if(whatParentB(nums[0]-1) != whatParentB(nums[1]-1))
        parents[whatParentB(nums[0]-1)][1] = whatParentB(nums[1]-1);//???????????2??????????
    }

    for(long i = 0; i < n; i++)
    {
      parents[i][2] = whatParentA(i)*10000000+whatParentB(i);
      //Console.WriteLine(parents[i][2]);
    }

    Array.Sort(parents, (a, b) => a[2].CompareTo(b[2]));
    parents[0][0] = 1;
    long memo = 1;
    for(long i = 1; i < n; i++)
    {
      if(parents[i][2] == parents[i-1][2])
      {
        memo++;
        parents[i][0] = memo;
      }else
      {
        memo = 1;
        parents[i][0] = memo;
      }
      //Console.WriteLine(parents[i][0]);
    }
    parents[n-1][1] = parents[n-1][0];
    for(long i = n-2; i >= 0; i--)
    {
      if(parents[(int)(i+1)][0] != 1) parents[(int)(i)][1] = parents[(int)(i+1)][1];
      else parents[(int)(i)][1] = parents[i][0];
    }

    Array.Sort(parents, (a, b) => a[3].CompareTo(b[3]));//??????
    for(long i = 0; i < n; i++)
    {
      answers[i] = parents[i][1];
    }
    Console.WriteLine(string.Join(" ", answers));
	}

  static long whatParentA(long child)
  {
    if(parents[child][0] == child) return child;
    else return parents[child][0] = whatParentA(parents[child][0]);
  }

  static long whatParentB(long child)
  {
    if(parents[child][1] == child) return child;
    else return parents[child][1] = whatParentB(parents[child][1]);
  }
  
}