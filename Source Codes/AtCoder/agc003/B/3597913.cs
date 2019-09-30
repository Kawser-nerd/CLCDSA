using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//long.Parse?string?long????
    long[] nums = new long[n];
    long answer = 0;
    for(int i = 0; i < n; i++) nums[i] = long.Parse(Console.ReadLine());
    
		for(int i = 0; i < n; i++)
    {
      answer += nums[i]/2;//2??????
      nums[i] -= nums[i]/2*2;
      if(nums[i] == 1 && i+1 < n)
      {
        if(nums[i+1] > 0)
        {
          nums[i+1]--;
          answer++;
        }
      }
    }
		Console.WriteLine(answer);
	}
}