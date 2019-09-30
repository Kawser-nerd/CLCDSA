using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
static string[] input = Console.ReadLine().Split(' ');//Split???????????????????
static long n = long.Parse(input[0]);
static long m = long.Parse(input[1]);
static List<long[]>[] nextList = new List<long[]>[n];//??????????????????????
static long[] colors = new long[n];//???????????0????2
static long[] distances = new long[n];//?????????
static long[] distanceMemos = new long[2];//?????????????????
static long answer = 0;

	static void Main()
	{

  
    for(long i = 0; i < n; i++) nextList[i] = new List<long[]>();//?????????
    for(long j = 0; j < m; j++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    
      long[] nextMemo = new long[2];
      nextMemo[1] = nums[1]-1;//??????
      nextMemo[0] = nums[2];//??
      nextList[nums[0]-1].Add(nextMemo);//????????

      long[] nextMemoSub = new long[2];
      nextMemoSub[1] = nums[0]-1;//??????
      nextMemoSub[0] = nums[2];//??
      nextList[nums[1]-1].Add(nextMemoSub);
    }
    
    for(int i = 0; i < n; i++) Dijkstra(i);

    answer /= 2;
    Console.WriteLine(answer);
	}

  static void Dijkstra(int startVertexNum)//O((|???|+|??|)log???)??????????????
  {
    //Console.WriteLine(startVertexNum);
    List<long[]> distanceList = new List<long[]>();//????????
    for(long i = 0; i < n; i++)
    {
      distances[i] = long.MaxValue;//??????????
      colors[i] = 0;
    }

    long[] newDistance = new long[2];

    //??????????
    newDistance[1] = startVertexNum;//????????
    distances[startVertexNum] = 0;
    colors[startVertexNum] = 1;

    newDistance[0] = 0;//???????????????0
    distanceList.Add(newDistance);
    distanceMemos[0] = 0;

    //Console.WriteLine(distanceList.Count());
    while(distanceList.Count() != 0)
    {
      distanceList = PopHeap(distanceList);
      long minVertex = distanceMemos[1];//???????
      colors[minVertex] = 2;
      //Console.WriteLine(distances[minVertex] +"&"+ distanceMemos[0]);
      if(distances[minVertex] < distanceMemos[0]) continue;//?????????????
      //Console.WriteLine(nextList[minVertex].Count()+"a");
      for(long i = 0; i < nextList[minVertex].Count(); i++)
      {
        long v = nextList[minVertex][(int)i][1];
        if(colors[v] == 2) continue;
        if(distances[v] > distances[minVertex] + nextList[minVertex][(int)i][0])
        {
          distances[v] = distances[minVertex] + nextList[minVertex][(int)i][0];
          long[] newDistanceSub = new long[2];
          newDistanceSub[0] = distances[v];
          newDistanceSub[1] = v;
          distanceList = PushHeap(distanceList, newDistanceSub);
          colors[v] = 1;
        }
      }
    }

    for(int i = 0; i < nextList[startVertexNum].Count(); i++)
    {
      if(distances[nextList[startVertexNum][i][1]] < nextList[startVertexNum][i][0]) answer++;
      //Console.WriteLine(distances[nextList[startVertexNum][i][1]] +" "+ nextList[startVertexNum][i][0]);
    }
    
  }

  //????????????????
  static List<long[]> PushHeap(List<long[]> nums, long[] addNums)//??????nums?addNum???
  {
    int n = nums.Count;
    nums.Add(addNums);

    while (n > 0)
    {
      int i = (n-1)/2;
      if (nums[n][0] < nums[i][0])//???????????????
      {
        long tmp = nums[n][0];
        long tmpSub = nums[n][1];
        nums[n][0] = nums[i][0];
        nums[n][1] = nums[i][1];
        nums[i][0] = tmp;
        nums[i][1] = tmpSub;
      }
      n = i;
    }
    return nums;
  }

  static List<long[]> PopHeap(List<long[]> nums)//???nums?????
  {
    int n = nums.Count - 1;
    distanceMemos[0] = nums[0][0];//???????
    distanceMemos[1] = nums[0][1];
    nums[0][0] = nums[n][0];//????????????????????????
    nums[0][1] = nums[n][1];
    nums.RemoveAt(n);

    for (int i = 0, j; (j = 2*i+1) < n;)
    {
      if ((j != n-1) && (nums[j][0] > nums[j+1][0]))// ?????????????????
        j++;
      if (nums[i][0] > nums[j][0])//??????????????
      {
        long tmp = nums[j][0];
        long tmpSub = nums[j][1];
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