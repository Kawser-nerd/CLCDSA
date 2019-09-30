using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//long.Parse?string?long????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
		long answer = 0;

    for(long i = 0; i < n; i++)
    {
      if(nums[i] == i+1)
      {
        answer++;
        i++;
      }
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}