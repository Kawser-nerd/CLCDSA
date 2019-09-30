using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());//int.Parse???????????
  long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
  long answer = 0;
  long memo = 0;

  answer += n;
  for(long i = 0; i < n-1; i++)
  {
    if(nums[i] < nums[i+1])
    {
      memo++;
      answer += memo;
    }else memo = 0;
  }

	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}