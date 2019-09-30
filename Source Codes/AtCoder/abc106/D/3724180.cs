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
		long m = long.Parse(input[1]);
    long q = long.Parse(input[2]);
    long answer = 0;
    long[,] trains = new long[n+2,n+2];
    for(long i = 0; i < m; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      trains[nums[0],nums[1]]++;
    }

    for(int i = 0; i < n+2; i++)
    {
      for(int j = 1; j < n+2; j++)
      {
        trains[i,j] += trains[i,j-1];
      }
    }
    
    for(int i = 1; i < n+2; i++)
    {
      for(int j = 0; j < n+2; j++)
      {
        trains[i,j] += trains[i-1,j];
      }
    }
    
    for(long i = 0; i < q; i++)
    {
      long[] numsa = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);//?????????
      answer = trains[n+1,numsa[1]] - trains[numsa[0]-1,numsa[1]];
      Console.WriteLine(answer);
    }

	}
}