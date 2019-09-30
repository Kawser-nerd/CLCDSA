using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		int n = int.Parse(Console.ReadLine());//long.Parse?string?long????
    long[,] vertexes = new long[n,2];//???????
    long answer = 0;
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      vertexes[i,0] = nums[0];
      vertexes[i,1] = nums[1];
    }

    for(int i = n-1; i >= 0; i--)
    {
      if((vertexes[i,0]+answer) % vertexes[i,1] != 0)
        answer += vertexes[i,1] - ((vertexes[i,0]+answer) % vertexes[i,1]);
    }
    
		Console.WriteLine(answer);
	}
}