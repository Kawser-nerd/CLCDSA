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
  long[] nums = new long[n];
  long upNum = 0;
  long answer = 0;
  
	   for(long i = 0; i < n; i++)
     {
        nums[i] = long.Parse(Console.ReadLine());
     }

     for(long i = 0; i < n - 1; i++)
     {
        if(nums[i] < nums[i + 1])
        {
          upNum ++;
          if(upNum + 1 >= k) answer++;
        }else upNum = 0;
     }

     
     if(k == 1) answer = n;
	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}