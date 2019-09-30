using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());
    long[][] nums = new long[n][];
    long memo = 1;
    long answer = 1;
		for(long i = 0; i < n; i++)
    {
      nums[i] = new long[2];
      nums[i][0] = long.Parse(Console.ReadLine());
      nums[i][1] = i;
    }

    Array.Sort(nums, (a, b) => a[0].CompareTo(b[0]));

    for(long i = 1; i < n; i++)
    {
      if(nums[i][1] > nums[i-1][1]) memo++;
      else memo = 1;
      answer = Math.Max(answer, memo);
    }
    
		Console.WriteLine(n - answer);//WriteLine?Write?????????????
	}
}