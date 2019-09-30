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
    long[] usedCount = new long[n];
    bool answer = true;

    long[,] vertexes = new long[n,2];//???????
    for(long i = 0; i < m; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      usedCount[nums[0]-1]++;
      usedCount[nums[1]-1]++;
    }

    for(int i = 0; i < n; i++)
    {
      if(usedCount[i] % 2 == 1) answer = false;
    }

		Console.WriteLine((answer) ? "YES" : "NO");
	}
}