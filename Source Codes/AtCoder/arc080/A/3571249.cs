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
    long[] remains = new long[3];//4???????0,(1,3),2
    bool answer = false;

    for(int i = 0; i < n; i++)
    {
      if(nums[i] % 4 == 0) remains[0]++;
      else if(nums[i] % 4 == 2) remains[2]++;
      else remains[1]++;
    }

    if(remains[2] >= 1 && remains[0] >= remains[1]) answer = true;
    else if(remains[2] == 0 && remains[0]+1 >= remains[1]) answer = true;
    
		Console.WriteLine((answer) ? "Yes" : "No");
	}
}