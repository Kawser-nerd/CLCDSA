using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static int[] numsa = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
static int n = numsa[0];
static int k = numsa[1];
static List<int[]>[] nextList = new List<int[]>[n];//??????????????????????
static int[] colors = new int[n];//???????????0????2
static int[] distances = new int[n];//?????????
static int[] distanceMemos = new int[2];//?????????????????
static int[] diameters = new int[n];
static int[,] nextmemos = new int[n-1,2];
static int answer = int.MaxValue;

	static void Main()
	{
    for(int i = 0; i < n; i++)nextList[i] = new List<int[]>();//?????????
    for(int i = 0; i < n-1; i++)
    {
      int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);

        nextmemos[i,0] = nums[0]-1;
        nextmemos[i,1] = nums[1]-1;

        int[] nextMemo = new int[2];
        nextMemo[1] = nums[1]-1;//??????
        nextMemo[0] = 1;//??
        nextList[nums[0]-1].Add(nextMemo);//????????
        
        int[] nextMemoSub = new int[2];
        nextMemoSub[1] = nums[0]-1;//??????
        nextMemoSub[0] = 1;//??
        nextList[nums[1]-1].Add(nextMemoSub);//????????
    }
    for(int i = 0; i < n; i++)
    {
      if(k % 2 == 0)//?????
      {
        Dijkstra(i);
        int memo = 0;
        for(int j = 0; j < n; j++)
        {
          if(distances[j] > k/2) memo++;
        }
        //Console.WriteLine(memo);
        answer = Math.Min(answer, memo);//?????????????
      }
    }

    if(k % 2 == 1)//?????
    {
      int[,] distanceMemosa = new int[n,n];//???????
      for(int i = 0; i < n; i++)
      {
        Dijkstra(i);
        for(int j = 0; j < n; j++) distanceMemosa[i,j] = distances[j];
      }
      for(int i = 0; i < n-1; i++)
      {
        int memo = 0;
        for(int j = 0; j < n; j++)
        {
          if(Math.Min(distanceMemosa[nextmemos[i,0],j], distanceMemosa[nextmemos[i,1],j]) > k/2) memo++;
        }
        //Console.WriteLine(memo+" "+nextmemos[i,0]+" "+nextmemos[i,1]);
        answer = Math.Min(answer, memo);//?????????????
      }
    }

    Console.WriteLine(answer);
	}

  static void Dijkstra(int startVertex)//O((|???|+|??|)log???)??????????????
  {
    List<int[]> distanceList = new List<int[]>();//????????
    for(int i = 0; i < n; i++)
    {
      distances[i] = int.MaxValue;//??????????
      colors[i] = 0;
    }

    int[] newDistance = new int[2];

    //??????????
    newDistance[1] = startVertex;//????????
    distances[startVertex] = 0;
    colors[startVertex] = 1;

    newDistance[0] = 0;//???????????????0
    distanceList.Add(newDistance);

    while(distanceList.Count() != 0)
    {
      distanceList = PopHeap(distanceList);
      int minVertex = distanceMemos[1];//???????
      colors[minVertex] = 2;
      if(distances[minVertex] < distanceMemos[0]) continue;//?????????????

      for(int i = 0; i < nextList[minVertex].Count(); i++)
      {
        int v = nextList[minVertex][(int)i][1];
        if(colors[v] == 2) continue;
        if(distances[v] > distances[minVertex] + nextList[minVertex][(int)i][0])
        {
          distances[v] = distances[minVertex] + nextList[minVertex][(int)i][0];
          int[] newDistanceSub = new int[2];
          newDistanceSub[0] = distances[v];
          newDistanceSub[1] = v;
          distanceList = PushHeap(distanceList, newDistanceSub);
          colors[v] = 1;
        }
      }
    }
    
  }

  //????????????????
  static List<int[]> PushHeap(List<int[]> nums, int[] addNums)//??????nums?addNum???
  {
    int n = nums.Count;
    nums.Add(addNums);

    while (n > 0)
    {
      int i = (n-1)/2;
      if (nums[n][0] < nums[i][0])//???????????????
      {
        int tmp = nums[n][0];
        int tmpSub = nums[n][1];
        nums[n][0] = nums[i][0];
        nums[n][1] = nums[i][1];
        nums[i][0] = tmp;
        nums[i][1] = tmpSub;
      }
      n = i;
    }
    return nums;
  }

  static List<int[]> PopHeap(List<int[]> nums)//???nums?????
  {
    int n = nums.Count - 1;
    distanceMemos[0] = nums[0][0];//???????
    distanceMemos[1] = nums[0][1];
    nums[0][0] = nums[n][0];//????????????????????????
    nums[0][1] = nums[n][1];
    nums.RemoveAt(n);

    for (int i = 0, j; (j = 2*i+1) < n; )
    {
      if ((j != n-1) && (nums[j][0] > nums[j+1][0]))// ?????????????????
        j++;
      if (nums[i][0] > nums[j][0])//??????????????
      {
        int tmp = nums[j][0];
        int tmpSub = nums[j][1];
        nums[j][0] = nums[i][0];
        nums[j][1] = nums[i][1];
        nums[i][0] = tmp;
        nums[i][1] = tmpSub;
      }
      i = j;
    }
    return nums;
  }
  
}