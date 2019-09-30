using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static long r = 10;//??
static long c = 10;//??
static long[] startPosition = new long[2];//??????
static long[,] distances = new long[r,c];//????
static Queue<long[]> que = new Queue<long[]>();//??????????
static long[,] wallPositions = new long[r+2,c+2];//??1
static long[] VectorArrow = new long[8]{0,1,0,-1,1,0,-1,0};//?????????????
static bool answer = false;

	static void Main()
	{  
  
		for(long i = 0; i < r; i++)
    {
      string inputc = Console.ReadLine();
      for(long j = 0; j < c; j++)
      {
        if(inputc[(int)j] == 'x') wallPositions[i+1,j+1] = 1;//????
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

    for(long i = 0; i < 10; i++)
    {
      for(long j = 0; j < 10; j++)
      {
        bool wallChanged = false;
        if(wallPositions[i+1,j+1] == 1) 
        {
          wallPositions[i+1,j+1] = 0;
          wallChanged = true;
        }
        for(long x = 0; x < 10; x++)
        {
          for(long y = 0; y < 10; y++)
          {
            startPosition[0] = x;
            startPosition[1] = y;
            if(wallPositions[x+1,y+1] == 0) BFS(startPosition);//?????
          }
        }
        if(wallChanged) wallPositions[i+1,j+1] = 1;
      }
    }
    Console.WriteLine((answer) ? "YES" : "NO");
	}

  static void BFS(long[] startPosition)//?????????????????
  {
    que.Enqueue(startPosition);
    for(long i = 0; i < r; i++)
    {
      for(long j = 0; j < c; j++)
      {
        distances[i,j] = long.MaxValue;//????????
      }
    }
    
    distances[startPosition[0], startPosition[1]] = 0;//????????????0
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

    bool answerMemo = true;
    for(long i = 0; i < r; i++)
    {
      for(long j = 0; j < c; j++)
      {
        if(wallPositions[i+1,j+1] == 0 && distances[i,j] == long.MaxValue) answerMemo = false;
      }
    }
    if(answerMemo) answer = true;
  }
}