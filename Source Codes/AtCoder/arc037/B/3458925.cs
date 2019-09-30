using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static string[] input = Console.ReadLine().Split(' ');
static long n = long.Parse(input[0]);
static long m = long.Parse(input[1]);
static long[,] nextMatrix = new long[n,n];//????
static long[] startTime = new long[n];//???????????
static long[] goalTime = new long[n];//???????????
static long[] colors = new long[n];//????????????2
static long timeMemo = 0;
static long[] nextVertexes = new long[n];
static long answer = 0;
static bool answerPlus = true;

	static void Main()
	{
    for(long i = 0; i < m; i++)
    {
		  long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      nextMatrix[nums[0]-1,nums[1]-1] = 1;//???????
      nextMatrix[nums[1]-1,nums[0]-1] = 1;
    }
    DFS();
    Console.WriteLine(answer);
	}

  static void DFS()//???????O(V^2)
  {
    for(long i = 0; i < n; i++)
    {
      colors[i] = 0;//???
      nextVertexes[i] = 0;
    }
    timeMemo = 0;

    for(long i = 0; i < n; i++)
    {
      if(colors[i] == 0) 
      {
        answerPlus = true;
        DFSvisit(i);
        if(answerPlus) answer++;
      }
    }

    for(long i = 0; i < n; i++)
    {
      //Console.WriteLine((i+1) + " " + startTime[i] + " " + goalTime[i]);
    }
  }

  static void DFSvisit(long startVertex)//??????
  {
    for(long i = 0; i < n; i++)
    {
      nextVertexes[i] = 0;
    }

    var stack = new Stack<long>();//????
    stack.Push(startVertex);
    colors[startVertex] = 1;
    timeMemo++;
    startTime[startVertex] = timeMemo;

    while(stack.Count > 0)
    {
      long topMemo = stack.Peek();
      long v = NextVertex(topMemo);
      if(v != -1)
      {
        if(colors[v] == 0)
        {
          colors[v] = 1;
          timeMemo++;
          startTime[v] = timeMemo;
          stack.Push(v);
        }else if(colors[v] == 2 && v != topMemo) answerPlus = false;
      }else
      {
        stack.Pop();
        colors[topMemo] = 2;
        timeMemo++;
        goalTime[topMemo] = timeMemo;
      }
    }
  }

  static long NextVertex(long vertexMemo)
  {
    for(long i = nextVertexes[vertexMemo]; i < n; i++)
    {
      nextVertexes[vertexMemo] = i+1;
      if(nextMatrix[vertexMemo, i] == 1) return i;
    }
    return -1;
  }
  
}