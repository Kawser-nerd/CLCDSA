using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long a = long.Parse(input[0]);
		long b = long.Parse(input[1]);
    Console.WriteLine("100 100");
    a--;
    b--;
    for(long i = 0; i < 50; i++)//??
    {
      string answer = "";
      for(long j = 0; j < 100; j++)
      {
        if(i % 2 == 0 && j % 2 == 0 && a > 0)
        {
          answer += ".";
          a--;
        }else
        {
          answer += "#";
        }
      }
      Console.WriteLine(answer);
    }

    for(long i = 50; i < 100; i++)//??
    {
      string answer = "";
      for(long j = 0; j < 100; j++)
      {
        if(i % 2 == 1 && j % 2 == 0 && b > 0)
        {
          answer += "#";
          b--;
        }else
        {
          answer += ".";
        }
      }
      Console.WriteLine(answer);
    }
    
	}
}