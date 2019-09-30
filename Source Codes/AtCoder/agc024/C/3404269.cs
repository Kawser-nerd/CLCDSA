using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
		long[] nums = new long[n];
    for(long i = 0; i < n; i++)
    {
      nums[i] = long.Parse(Console.ReadLine());
    }
		long answer = 0;
    long numMemo = 0;
    bool isPossible = true;

    if(nums[0] != 0) isPossible = false;
    else
    {
      for(long i = 1; i < n; i++)
      {
      //Console.WriteLine(answer);
        if(nums[i] > numMemo+1)
        {
          isPossible = false;
          break;
        }
        else if(nums[i] == numMemo+1)
        {
          answer++;
          numMemo = nums[i];
        }
        else if(nums[i] < numMemo+1)
        {
          answer += nums[i];
          numMemo = nums[i];
        }
      }
    }
    
		Console.WriteLine((isPossible) ? answer : -1);
	}
}