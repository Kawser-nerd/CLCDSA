using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
		long answer = 0;

    if(nums[0] % 2 == 1 && nums[3] % 2 == 1 && nums[4] >= 1 ||
      nums[3] % 2 == 1 && nums[4] % 2 == 1 && nums[0] >= 1 ||
      nums[4] % 2 == 1 && nums[0] % 2 == 1 && nums[3] >= 1)
    {
      answer += 3;
      nums[0]--;
      nums[3]--;
      nums[4]--;
    }
    answer += (nums[0]/2)*2;
    answer += nums[1];
    answer += (nums[3]/2)*2;
    answer += (nums[4]/2)*2;

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}