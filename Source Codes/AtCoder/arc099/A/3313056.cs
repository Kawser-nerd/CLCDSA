using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	long n = long.Parse(input[0]);
	long k = long.Parse(input[1]);
	long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
  long aim = 0;//1???
  long answer = long.MaxValue;

  for(long i = 0; i < n; i++)
  {
    if(nums[i] == 1) aim = i;
  }

  for(long i = 0; i < n-k+1; i++)
  {
    if(i <= aim && aim <= i+k-1)
    {
      long num = ((i+k-2)/(k-1)) + ((n-i-2)/(k-1)) + 1;
      //Console.WriteLine(((i+k-2)/(k-1)) +" "+ ((n-i-2)/(k-1)));
      answer = Math.Min(num,answer);
    }
  }
  
	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}