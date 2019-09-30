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
		long k = long.Parse(input[1]);
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long memo = nums[0];
    long max = nums[0];

    for(int i = 1; i < n; i++)
    {
      memo = Gcd(memo, nums[i]);
      max = Math.Max(max, nums[i]);
      //Console.WriteLine(memo+" "+max);
    }
		Console.WriteLine((k <= max && (max-k) % memo == 0) ? "POSSIBLE" : "IMPOSSIBLE");
	}

  static long Gcd(long a, long b) 
      {//??a,b?????????
           if (a < b)
               return Gcd(b, a);//????
           while (b != 0) 
           {
               long changeTo = a % b;
               a = b;
               b = changeTo;
           }
           return a;
       }
  
}