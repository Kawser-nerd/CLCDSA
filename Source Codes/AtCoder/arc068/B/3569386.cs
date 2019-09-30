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
    long memo = 0;

    for(int i = 1; i < n; i++)
    {
      if(nums[i] == nums[i-1]) memo++;
    }
    if(memo % 2 == 1) memo++;
    
		Console.WriteLine(n-memo);//WriteLine?Write?????????????
	}
}