using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());
    long maxDistance = 0;
    long maxVertex = 0;
    long answer = 0;
    for(int i = 1; i < n; i++)
    {
      Console.WriteLine("? 1 "+ (i+1));
      long memo = long.Parse(Console.ReadLine());
      if(memo > maxDistance)
      {
        maxDistance = memo;
        maxVertex = i;
      }
    }
    for(int i = 0; i < n; i++)
    {
      if(i != maxVertex)
      {
        Console.WriteLine("? "+(maxVertex+1)+" "+(i+1));
        long memo = long.Parse(Console.ReadLine());
        answer = Math.Max(answer, memo);
      }
    }

		Console.WriteLine("! "+answer);
	}
}