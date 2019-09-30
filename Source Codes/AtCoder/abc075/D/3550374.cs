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
		long k = long.Parse(input[1]);
    long answer = long.MaxValue;

    long[,] vertexes = new long[n,2];//???????
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
    }

    for(int xa = 0; xa < n; xa++)
    {
      for(int xb = xa+1; xb < n; xb++)
      {
        for(int ya = 0; ya < n; ya++)
        {
          for(int yb = ya+1; yb < n; yb++)
          {
            int memo = 0;
            for(int i = 0; i < n; i++)
            {
              if((vertexes[xa,0]-vertexes[i,0])*(vertexes[xb,0]-vertexes[i,0])<=0 &&
                (vertexes[ya,1]-vertexes[i,1])*(vertexes[yb,1]-vertexes[i,1])<=0) memo++;
            }
            if(memo >= k) answer = Math.Min(answer, 
              Math.Abs((vertexes[xb,0]-vertexes[xa,0])*(vertexes[yb,1]-vertexes[ya,1])));
          }
        }
      }
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}