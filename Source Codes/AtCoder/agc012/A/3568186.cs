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
    long memo = 0;
    Array.Sort(nums);
    while(true)
    {
      answer += nums[3*n-2-2*memo];
      memo++;
      if(memo == n) break;
    }
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}