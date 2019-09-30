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
		long m = long.Parse(input[1]);
    long oneTime = 1900*m + 100*(n-m);
    long probability = 1;
    for(int i = 0; i < m; i++)
    {
      probability *= 2;
    }
    long answer = oneTime * probability;
		Console.WriteLine(answer);
	}
}