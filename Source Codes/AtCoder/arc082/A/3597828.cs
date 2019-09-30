using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
    long n = long.Parse(Console.ReadLine());
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
		long[] answers = new long[100002];
    long answer = 0;
    for(int i = 0; i < n; i++)
    {
      answers[nums[i]]++;
      answers[nums[i]+1]++;
      answers[nums[i]+2]++;
    }
    for(int i = 0; i < 100002; i++)
    {
      answer = Math.Max(answer, answers[i]);
    }
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}