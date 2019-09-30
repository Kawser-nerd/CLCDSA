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
		long a = long.Parse(input[1]);
  	long b = long.Parse(input[2]);
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long answer = 0;

    for(int i = 1; i < n; i++)
    {
      if((nums[i] - nums[i-1])*a < b) answer += (nums[i] - nums[i-1])*a;
      else answer += b;
    }
    
		Console.WriteLine(answer);
	}
}