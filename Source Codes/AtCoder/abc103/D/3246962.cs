using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
  int answer = 0;
  int lastPosition = -1;
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	int n = int.Parse(input[0]);
	int m = int.Parse(input[1]);
  List<int[]> bridgeList = new List<int[]>();
    for(int i = 0; i < m; i++)
    {
    int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);//?????????
    bridgeList.Add(new int[2]{nums[0]-1,nums[1]-1});
    }

    bridgeList.Sort((a, b) => a[1].CompareTo(b[1]));

    for(int i = 0; i < m; i++)
    {
      if(bridgeList[i][1] > lastPosition + 1 && bridgeList[i][0] > lastPosition)
      {
      answer++;
      lastPosition = bridgeList[i][1] - 1;
      }
    }
    
	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}