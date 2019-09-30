using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
		long answer = 0;

    for(long i = 0; i < n; i++)
    {
      if(nums[i] < 80) answer += 80 - nums[i];
    }

    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}