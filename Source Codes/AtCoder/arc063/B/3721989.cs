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
		long t = long.Parse(input[1]);
  	long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long answer = 0;
    long minMemo = long.MaxValue;
    long maxGet = 0;

    for(int i = 0; i < n; i++)
    {
      if(nums[i] < minMemo) minMemo = nums[i];
      else
      {
        if(nums[i] - minMemo > maxGet)
        {
          maxGet = nums[i] - minMemo;
          answer = 1;
        }else if(nums[i] - minMemo == maxGet) answer++;
      }
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}