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
    long[] numsSub = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);

    long height = 0;
    long width = 0;
    long mod = 1000000007;
    long answer = 1;

    for(int i = 0; i < n-1; i++)
    {
      height += (i+1)*(n-1-i)*(nums[i+1]-nums[i]);
      height %= mod;
    }

    for(int i = 0; i < m-1; i++)
    {
      width += (i+1)*(m-1-i)*(numsSub[i+1]-numsSub[i]);
      width %= mod;
    }

    answer = height * width;
    answer %= mod;
    
		Console.WriteLine(answer);
	}
}