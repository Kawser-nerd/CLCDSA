using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long c = long.Parse(input[1]);
    long k = long.Parse(input[2]);
    long[] nums = new long[n];
    long answer = 1;
    long startTime = 0;
    long playerNum = 1;

    for(int i = 0; i < n; i++)
    {
      nums[i] = long.Parse(Console.ReadLine());
    }
    Array.Sort(nums);

    startTime = nums[0];
    for(int i = 1; i < n; i++)
    {
      if(nums[i] > startTime+k || playerNum >= c)
      {
        answer++;
        playerNum = 1;
        startTime = nums[i];
      }else playerNum++;
    }

		Console.WriteLine(answer);
	}
}