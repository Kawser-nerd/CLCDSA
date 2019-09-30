using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
  long answer = 0;
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	long n = long.Parse(input[0]);
	long m = long.Parse(input[1]);
  long[] a = new long[m];
  long[] b = new long[m];
  long[] c = new long[m];
  long[] distance = new long[n];//????
  bool[] negative = new bool[n];//?????

    for(long i = 0; i < n; i++)
    {
      distance[i] = long.MaxValue;
    }
    
    for(long i = 0; i < m; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      a[i] = nums[0]-1;
      b[i] = nums[1]-1;
      c[i] = -nums[2];//???????????????
      //Console.WriteLine( a[i]+" "+b[i]+ " "+c[i]);
    }
    distance[0] = 0;

    for(long i = 0; i < n-1; i++)//???????????????
    {
      for(long j = 0; j < m; j++)
      {
        if(distance[a[j]] == long.MaxValue) continue;

        distance[b[j]] = Math.Min(distance[b[j]], distance[a[j]] + c[j]);
        //Console.WriteLine(a[j] + " "+b[j]+" " +distance[b[j]]);
      }
    }

    answer = distance[n-1];

    for(long i = 0; i < n; i++)
    {
      for(long j = 0; j < m; j++)
      {
        if(distance[a[j]] == long.MaxValue) continue;

        if(distance[b[j]] > distance[a[j]] + c[j])//?????????????????????
        {
          distance[b[j]] = distance[a[j]] + c[j];
          negative[b[j]] = true;
        }

        if(negative[a[j]] == true)//??????????
        {
        negative[b[j]] = true;//???????
        }
        
      }
    }

    if(negative[n-1]) Console.WriteLine("inf");
    else Console.WriteLine(-answer);

	}
}