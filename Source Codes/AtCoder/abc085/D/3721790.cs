using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long h = long.Parse(input[1]);
    long[] attacks = new long[n];
    long maxAttack = 0;
    long answer = 0;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      maxAttack = Math.Max(nums[0],maxAttack);
      attacks[i] = nums[1];
    }

    Array.Sort(attacks);
    Array.Reverse(attacks);

    for(int i = 0; i < n; i++)
    {
      if(attacks[i] > maxAttack)
      {
        h -= attacks[i];
        answer++;
        if(h <= 0) break;
      }else break;
    }

    if(h > 0)
    {
      answer += (h+maxAttack-1)/maxAttack;
    }
    
		Console.WriteLine(answer);
	}
}