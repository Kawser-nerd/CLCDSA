using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
  //static List<string> list;
	static void Main(string[] args)
	{
		// ??????
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int K = int.Parse(input[1]);
        List<int> h = new List<int>();

        for(int i=0; i<N; i++)
        {
          int hh = int.Parse(Console.ReadLine());
          h.Add(hh);
        }
        // ???????????
        h.Sort();

        // ?????K????????????
        int min = -1;
        for(int i=0; i<N-K+1; i++)
        {
          int start = h[i];
          int end = h[i+K-1];

          if(min == -1 || end - start < min)
            min = end - start;
        }

    // ??
        Console.WriteLine(min);
    }
		class myClass{ //?????
			public int ID {set; get;}
			public long Point {set; get;}
		}
    static private int getMaxPoint(int solve, int[,] table)
    {
      int ret = 0;

      return ret;
    }

}