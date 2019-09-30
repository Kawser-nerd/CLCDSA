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
		long m = long.Parse(input[1]);
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] sums = new long[n+1];
    long answer = 0;

    for(int i = 0; i < n; i++)
    {
      sums[i+1] += sums[i] + nums[i];
      sums[i+1] %= m;
    }
    Array.Sort(sums);//???
    long memo = 1;

    for(int i = 1; i <= n; i++)
    {
      if(sums[i] == sums[i-1])
      {
        answer += memo;
        memo++;
      }
      else memo = 1;
    }
    
		Console.WriteLine(answer);
	}
}