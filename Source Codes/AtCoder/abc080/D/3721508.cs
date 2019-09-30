using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');
		int n = int.Parse(input[0]);
		int c = int.Parse(input[1]);
    int[][] vertexes = new int[n][];//???????
    int[] times = new int[100000];
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
      int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
      vertexes[i] = new int[3];
      vertexes[i][0] = nums[0]-1;
      vertexes[i][1] = nums[1]-1;
      vertexes[i][2] = nums[2];
    }
    var sorted = vertexes.OrderBy(a => a[2]).ThenBy(a => a[0]).ToList();

    int tvMemo = sorted[0][2];
    for(int i = sorted[0][0]; i <= sorted[0][1]; i++)
    {
      times[i]++;
    }
    
    for(int i = 1; i < n; i++)
    {
      if(tvMemo == sorted[i][2] && sorted[i-1][1] == sorted[i][0])
      {
        for(int j = sorted[i][0]+1; j <= sorted[i][1]; j++)
        {
          times[j]++;
        }
      }else
      {
        for(int j = sorted[i][0]; j <= sorted[i][1]; j++)
        {
          times[j]++;
        }
      }
      tvMemo = sorted[i][2];
    }

    for(int i = 0; i < 100000; i++)
    {
      answer = Math.Max(answer, times[i]);
    }

		Console.WriteLine(answer);
	}
}