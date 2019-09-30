using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());
	long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
  long answer = 0;
  long memo = 0;

  for(long i = 1; i < n; i++)
  {
    if(nums[i] == nums[i-1]) memo++;
    else memo = 0;
    if(memo % 2 == 1) answer++;
  }

	Console.WriteLine(answer);
	}
}