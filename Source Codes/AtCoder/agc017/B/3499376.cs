using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long a = long.Parse(input[1]);
    long b = long.Parse(input[2]);
		long c = long.Parse(input[3]);
    long d = long.Parse(input[4]);
    bool answer = false;

    for(long i = 0; i <= n-1; i++)
    {
      if(a-d*(n-1-i)+c*i <= b && b <= a-c*(n-1-i)+d*i) answer = true;
    }
    
    Console.WriteLine((answer) ? "YES" : "NO");
	}
}