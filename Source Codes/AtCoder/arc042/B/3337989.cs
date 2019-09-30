using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');
		long x = long.Parse(input[0]);
		long y = long.Parse(input[1]);
		long n = long.Parse(Console.ReadLine());
    double answer = double.MaxValue;

    long[,] vertexes = new long[n+1,2];
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
    }
    vertexes[n,0] = vertexes[0,0];
    vertexes[n,1] = vertexes[0,1];

    for(long i = 0; i < n; i++)
    {
      double a = vertexes[i,0]-x;
      double b = vertexes[i,1]-y;
      double c = vertexes[i+1,0]-x;
      double d = vertexes[i+1,1]-y;
      double distanceVert = Math.Sqrt(Math.Pow(a-c,2)+Math.Pow(b-d,2));//?????
      double triArea = Math.Abs(a*d-b*c);//??????
      double distanceMemo = triArea / distanceVert;//???????????????
      answer = Math.Min(answer, distanceMemo);
      //Console.WriteLine(distanceMemo);
    }
    
		Console.WriteLine(answer);
	}
}