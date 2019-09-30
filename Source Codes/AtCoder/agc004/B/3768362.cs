using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');
		long n = long.Parse(input[0]);
		long x = long.Parse(input[1]);
    long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long answer = long.MaxValue;
    long[] minTimes = new long[n];
    long timeMemo = 0;

    for(int i = 0; i < n; i++)
    {
      minTimes[i] = long.MaxValue;
    }

    for(int magicCount = 0; magicCount < n; magicCount++)
    {
      timeMemo = 0;

      for(int i = 0; i < n; i++)
      {
        if(i-magicCount >= 0)
          minTimes[i] = Math.Min(minTimes[i], nums[i-magicCount]);
        else
          minTimes[i] = Math.Min(minTimes[i], nums[i-magicCount+n]);
        timeMemo += minTimes[i];
      }
      timeMemo += x*magicCount;
      answer = Math.Min(answer, timeMemo);
    }
    
		Console.WriteLine(answer);
	}
}