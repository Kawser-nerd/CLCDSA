using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] answers = new long[n];
    int left = 0;
    int right = 0;

    if(n % 2 == 1)
    {
      answers[n/2] = nums[0];
      right = n/2 + 1;
      left = n/2 - 1;
      for(int i = 1; i < n; i++)
      {
        if(i % 2 == 1)
        {
          answers[right] = nums[i];
          right++;
        }else
        {
          answers[left] = nums[i];
          left--;
        }
      }
    }else
    {
      right = n/2;
      left = n/2 - 1;
      for(int i = 0; i < n; i++)
      {
        if(i % 2 == 0)
        {
          answers[right] = nums[i];
          right++;
        }else
        {
          answers[left] = nums[i];
          left--;
        }
      }
    }

    Console.WriteLine(string.Join(" ", answers));
	}
}