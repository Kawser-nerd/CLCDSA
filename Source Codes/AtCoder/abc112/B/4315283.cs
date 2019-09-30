using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
	static void Main(string[] args)
	{
		// ??????
        string[] input = Console.ReadLine().Split(' ');
				int N = int.Parse(input[0]);
        int T = int.Parse(input[1]);
				int min = 1001;
        for(int i=0; i<N; i++)
        {
					 	input = Console.ReadLine().Split(' ');
	 					int cost = int.Parse(input[0]);
	         int time = int.Parse(input[1]);

					 if(time <= T)
					 {
						 if(cost < min)
						 	 min = cost;
					 }
        }
				if(min == 1001)
					Console.WriteLine("TLE");
        else
					Console.WriteLine(min);
    }
}