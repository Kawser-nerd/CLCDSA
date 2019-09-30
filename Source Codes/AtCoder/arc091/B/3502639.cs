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
		long answer = 0;

    for(long i = 1; i <= n; i++)
    {
      if(i <= k) continue;
      else
      {
        answer += (n+1)/i * (i-k);
        answer += Math.Max(0, ((n+1)%i)-k);
      }
    }
    
		if(k != 0) Console.WriteLine(answer);
    else Console.WriteLine(n*n);
	}
}