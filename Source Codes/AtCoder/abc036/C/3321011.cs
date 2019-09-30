using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());
  long[][] vertexes = new long[n][];
	for(long i = 0; i < n; i++)
    {
    vertexes[i] = new long[]{long.Parse(Console.ReadLine()), i,0};
    }

  Array.Sort(vertexes, (a, b) => a[0].CompareTo(b[0]));

  long memo = 0;
  vertexes[0][2] = 0;
  for(long i = 1; i < n; i++)
    {
    if(vertexes[i][0] > vertexes[i-1][0]) memo++;
    vertexes[i][2] = memo;//0????
    }

  Array.Sort(vertexes, (a, b) => a[1].CompareTo(b[1]));

  for(long i = 0; i < n; i++)
    {
	   Console.WriteLine(vertexes[i][2]);
	  }
  }
}