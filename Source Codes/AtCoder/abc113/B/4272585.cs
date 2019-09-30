using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
  //static List<string> list;
  //static List<int> primes = new List<int>{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,
  //                              59,61,67,71,73,79,83,89,97};
	static void Main(string[] args)
	{
		// ??????
        int N = int.Parse(Console.ReadLine());
        string[] input = Console.ReadLine().Split(' ');
        int T = int.Parse(input[0]);
        int A = int.Parse(input[1]);
        // N????????????
        string[] height = Console.ReadLine().Split(' ');
        int[] H = new int[N];
        for(int i=0; i<N; i++)
        {
          H[i] = int.Parse(height[i]);
        }

        // ???????A????min???
        decimal min = 0;
        int strct = 0; //????
        for(int i=0; i<N; i++)
        {
          decimal atom = (decimal)(T - H[i]*0.006);
          if(i == 0 || Math.Abs(A - atom) < min)
          {
            min = Math.Abs(A - atom);
            strct = i;
          }
        }


    // ??
        Console.WriteLine(strct + 1);
    }
		class layer{ //?????
			public long total {set; get;} // ?????
			public long paty {set; get;}  // ?????
      public long banz {set; get;}  // ?????
		}
}