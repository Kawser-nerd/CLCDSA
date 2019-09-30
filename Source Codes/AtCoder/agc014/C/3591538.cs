using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static string[] input = Console.ReadLine().Split(' ');
static long r = long.Parse(input[0]);//??
static long c = long.Parse(input[1]);//??
static long k = long.Parse(input[2]);//?????????
static long[,] startPosition = new long[1,2];//??????
static long[,] startPositionsSecond;//2?????????
//static long[] goalPosition = new long[2];//?????
static long[,] distances = new long[r,c];//????
static Queue<long[]> que = new Queue<long[]>();//??????????
static long[,] wallPositions = new long[r+2,c+2];//??1
static long[] VectorArrow = new long[8]{0,1,0,-1,1,0,-1,0};//?????????????

	static void Main()
	{  
		for(long i = 0; i < r; i++)
    {
      string inputc = Console.ReadLine();
      for(long j = 0; j < c; j++)
      {
        if(inputc[(int)j] == 'S')//?????????
        {
          startPosition[0,0] = i;
          startPosition[0,1] = j;
        }
        if(inputc[(int)j] == '#') wallPositions[i+1,j+1] = 1;//????
      }
    }

    for(long i = 0; i < r+2; i++)//????????
    {
      wallPositions[i,0] = 1;
      wallPositions[i,c+1] = 1;
    }
    for(long j = 0; j < c+2; j++)
    {
      wallPositions[0,j] = 1;
      wallPositions[r+1,j] = 1;
    }
    
		BFS(startPosition);//?????

    long startCount = 0;//????????
    for(long i = 0; i < r; i++)
    {
      for(long j = 0; j < c; j++)
      {
        if(distances[i,j] <= k) startCount++;
      }
    }

    startPositionsSecond = new long[startCount,2];//?2???????
    for(long i = 0; i < r; i++)
    {
      for(long j = 0; j < c; j++)
      {
        if(distances[i,j] <= k)
        {
          startPositionsSecond[startCount-1, 0] = i;
          startPositionsSecond[startCount-1, 1] = j;
          startCount--;
        }
      }
    }

    for(long i = 0; i < r; i++)
    {
      for(long j = 0; j < c; j++)
      {
        wallPositions[i+1,j+1] = 0;//???????????
      }
    }

    BFS(startPositionsSecond);//?????

    long answer = long.MaxValue;
    for(long i = 0; i < r; i++)
    {
      answer = Math.Min(answer, (distances[i,0]+(k-1))/k);
      answer = Math.Min(answer, (distances[i,c-1]+(k-1))/k);
    }
    for(long i = 0; i < c; i++)
    {
      answer = Math.Min(answer, (distances[0,i]+(k-1))/k);
      answer = Math.Min(answer, (distances[r-1,i]+(k-1))/k);
    }
    answer++;
    Console.WriteLine(answer);
	}

  static void BFS(long[,] startPositions)//?????????????????
  {
    int n = startPositions.GetLength(0);//?????????
    long[][] startPosition = new long[n][];
    for(int i = 0; i < n; i++)
    {
      startPosition[i] = new long[2];
      startPosition[i][0] = startPositions[i,0];
      startPosition[i][1] = startPositions[i,1];
      que.Enqueue(startPosition[i]);
    }
    
    for(long i = 0; i < r; i++)
    {
      for(long j = 0; j < c; j++)
      {
        distances[i,j] = long.MaxValue;//????????
      }
    }

    for(int i = 0; i < n; i++)
    {
      distances[startPosition[i][0], startPosition[i][1]] = 0;//????????????0
    }
    long poppedMemoX = 0;
    long poppedMemoY = 0;
    while(que.Count > 0)
    {
      poppedMemoX = que.Peek()[0];
      poppedMemoY = que.Peek()[1];
      que.Dequeue();
    
      for(long partnerNum = 0; partnerNum < 4; partnerNum++)//?????????
      {
        long aimX = poppedMemoX+VectorArrow[2*partnerNum];
        long aimY = poppedMemoY+VectorArrow[2*partnerNum+1];
        if(wallPositions[aimX+1, aimY+1] == 1) continue;//?????
        if(distances[aimX, aimY] != long.MaxValue) continue;//???????????
        distances[aimX, aimY] = distances[poppedMemoX, poppedMemoY] + 1;//?????
        que.Enqueue(new long[2]{aimX, aimY});
      }
    }

      /*
      for(long i = 0; i < r; i++)//??????????
      {
        string answer = "";
        for(long j = 0; j < c; j++)
        {
          if(wallPositions[i+1,j+1] == 1) answer += "#";
          else answer += distances[i,j].ToString();
        }
        Console.WriteLine(answer);
      }
      */
      
      //Console.WriteLine(distances[goalPosition[0], goalPosition[1]]);//??????????
  }
}