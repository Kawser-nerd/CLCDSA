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
    Array.Sort(nums);
    long answer = 0;

    for(int i = 0; i < n; i++)
    {
      answer += nums[2*i];
    }
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}