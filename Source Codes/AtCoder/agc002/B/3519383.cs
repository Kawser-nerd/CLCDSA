using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		int n = int.Parse(input[0]);
		int m = int.Parse(input[1]);
    int[,] vertexes = new int[m,2];//???????
    int answer = 0;
    for(int i = 0; i < m; i++)
    {
      int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);//?????????
      vertexes[i,0] = nums[0]-1;
      vertexes[i,1] = nums[1]-1;
    }

    int[] counts = new int[n];//??????
    bool[] reds = new bool[n];//??????????????
    reds[0] = true;
    for(int i = 0; i < n; i++)
    {
      counts[i] = 1;
    }

    for(int i = 0; i < m; i++)
    {
      counts[vertexes[i,0]]--;
      counts[vertexes[i,1]]++;
      if(reds[vertexes[i,0]]) reds[vertexes[i,1]] = true;
      if(counts[vertexes[i,0]] == 0) reds[vertexes[i,0]] = false;
    }

    for(int i = 0; i < n; i++)
    {
      if(reds[i]) answer++;
    }
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}