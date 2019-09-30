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
        int K = int.Parse(input[0]);
        int S = int.Parse(input[1]);

        long pattern = 0;
        for(int x=0; x<=Math.Min(S,K); x++)
        {
          // x = ?????Y+Z=S-x
          if(S-x-K > K) continue; // ??????

          // x = ?????Y+Z=T?????????min(T,K)??0?????...
          int T = S-x;
          if(T <= K)
          {
            // T?????
            pattern += T + 1;
          }
          else
          {
            // (T-K) + K ? T-2K + 0?????????? <= K??????
            pattern += Math.Max(2*K - T + 1, 0); // ?????????
          }
        }

    // ??
        Console.WriteLine(pattern);
    }
		class myClass{ //?????
			public int ID {set; get;}
			public long Point {set; get;}
		}

}