using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] memos = new long[n];
    long min = 0;
    long max = 0;

    for(long i = 0; i < n; i++)
    {
      memos[i] = nums[i];
    }

    Array.Sort(memos);
    min = memos[n/2 - 1];
    max = memos[n/2];
    
    for(long i = 0; i < n; i++)
    {
		Console.WriteLine((nums[i] <= min) ? max : min);
    }
	}
}