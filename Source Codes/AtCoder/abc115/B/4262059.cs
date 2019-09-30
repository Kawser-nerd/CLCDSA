using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
  //static List<string> list;
	static void Main(string[] args)
	{
		// ??????
        int N = int.Parse(Console.ReadLine());
        int[] t = new int[N];

        for(int i=0; i<N; i++)
        {
          t[i] = int.Parse(Console.ReadLine());
        }

        // ??????????
        int max = 0, sum = 0;
        for(int i=0; i<N; i++)
        {
          if(max < t[i])
            max = t[i];

          sum += t[i];
        }

        int ret = sum - max/2;
        
    // ??
        Console.WriteLine(ret);
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