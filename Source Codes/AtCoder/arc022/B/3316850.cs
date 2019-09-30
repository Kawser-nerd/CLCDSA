using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());
  long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
  long[] checks = new long[100000];//?????
  long answer = 0;
  long memo = 0;
  long left = -1;

  for(long i = 0; i < n; i++)
  {
  memo++;
    if(checks[nums[i]-1] == 0)
    {
      checks[nums[i]-1] = 1;
      answer = Math.Max(memo, answer);
    }else
    {
      while(true)
      {
        left++;
        memo--;
        if(nums[i] == nums[left]) break;
        checks[nums[left]-1] = 0;
      }
    }
  }
  
	Console.WriteLine(answer);
	}
}