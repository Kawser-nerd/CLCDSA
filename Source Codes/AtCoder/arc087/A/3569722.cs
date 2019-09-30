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
    long memo = nums[0];
    long count = 1;
    long answer = 0;

    for(int i = 1; i < n; i++)
    {
      if(memo == nums[i]) count++;
      else
      {
        if(count >= memo) answer += count - memo;
        else answer += count;
        
        count = 1;
        memo = nums[i];
      }
    }
    if(count >= memo) answer += count - memo;
    else answer += count;
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}