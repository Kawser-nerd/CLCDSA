using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//long.Parse?string?long????
		long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
    long[] a = new long[n];
    long[] b = new long[n];
    string answer = "";

    for(long i = 0; i < n; i++)
    {
      a[i] += 20000*i+1;
      b[n-1-i] += 20000*i+1;
      a[nums[i]-1] += i;
    }
/*
    answer = a[0].ToString();
    for(long i = 1; i < n; i++)
    {
      answer += " "+a[i].ToString();
    }
    Console.WriteLine(answer);

    Console.WriteLine(string.Join(" ", a));

    answer = b[0].ToString();
    for(long i = 1; i < n; i++)
    {
      answer += " "+b[i].ToString();
    }
    Console.WriteLine(answer);
    */
    Console.WriteLine(string.Join(" ", a));
    Console.WriteLine(string.Join(" ", b));
	}
}