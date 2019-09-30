using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] numsUnder = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long answer = 0;
    long sumMemo = 0;
    for(long i = 0; i < n; i++)
    {
      sumMemo = 0;
      for(long j = 0; j <= i; j++) sumMemo += nums[j];
      for(long j = i; j < n; j++) sumMemo += numsUnder[j];
      answer = Math.Max(answer, sumMemo);
    }
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}