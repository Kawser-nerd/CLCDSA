using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long x = long.Parse(Console.ReadLine());
		long answer = 0;
    long memo = 0;
    for(int i = 1; i > 0; i++)
    {
      memo += i;
      answer++;
      if(x <= memo) break;
    }
		
		Console.WriteLine(answer);
	}
}