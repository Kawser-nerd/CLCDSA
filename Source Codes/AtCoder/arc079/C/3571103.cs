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
    long answer = 0;
    while(true)
    {
      bool finish = true;
      for(int i = 0; i < n; i++)
      {
        if(nums[i] >= n)
        {
          finish = false;
          answer += nums[i]/n;
          for(int j = 0; j < n; j++)
          {
            if(j != i) nums[j] += nums[i]/n;
          }
          nums[i] %= n;
        }
      }
      if(finish) break;
    }
    
		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}