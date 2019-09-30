using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
    long n = long.Parse(Console.ReadLine());
    long[][] nums = new long[n][];//????
    long answer = 0;
    
		for(int i = 0; i < n; i++)
    {
      nums[i] = new long[10];
      nums[i][0] = long.Parse(Console.ReadLine());
      nums[i][1] = i;
    }
    Array.Sort(nums, (a, b) => a[0].CompareTo(b[0]));//???
    for(int i = 0; i < n; i+=2)
    {
      if(nums[i][1] % 2 == 1) answer++;
    }

    Console.WriteLine(answer);
	}
  
}