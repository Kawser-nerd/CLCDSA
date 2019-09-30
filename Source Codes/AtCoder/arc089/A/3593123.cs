using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//long.Parse?string?long????
    long[,] vertexes = new long[n,3];//???????
    bool answer = true;
    long distance = 0;
    long time = 0;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
      vertexes[i,2] = nums[2];
    }

    for(int i = 0; i < n; i++)
    {
      if(i>=1)
      {
        distance = Math.Abs(vertexes[i,1]-vertexes[i-1,1])
          + Math.Abs(vertexes[i,2]-vertexes[i-1,2]);
        time = vertexes[i,0] - vertexes[i-1,0];
      }else
      {
        distance = Math.Abs(vertexes[i,1])
          + Math.Abs(vertexes[i,2]);
        time = vertexes[i,0];
      }
      
      if(time < distance) answer = false;
      if(time%2 != distance%2) answer = false;
    }
    
		Console.WriteLine((answer) ? "Yes" : "No");
	}
}