using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] adds = new long[n+1];
    adds[0] = 0;
    long memo = 1;
    long answer = 0;

    for(long i = 1; i < n+1; i++)
    {
      adds[i] = adds[i-1] + nums[i-1];
    }

    Array.Sort(adds);

    for(long i = 1; i < n+1; i++)
    {
      if(adds[i] == adds[i-1]) memo++;
      else
      {
        answer += memo*(memo-1)/2;
        memo = 1;
      }
      if(i == n) answer += memo*(memo-1)/2;
    }
      
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}