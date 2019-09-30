using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());//int.Parse???????????
	long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
  long up = -1;//???1????2
  long answer = 1;

    for(long i = 0; i < n; i++)
    {
      if(up == -1) up = 0;
      else if(up == 0)
      {
        if(nums[i] > nums[i-1]) up = 2;
        if(nums[i] < nums[i-1]) up = 1;
      }
      else
      {
        if((nums[i] > nums[i-1] && up == 1) || (nums[i] < nums[i-1] && up == 2))
        {
          up = 0;
          answer++;
        }
      }
    }
  

  
	Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}