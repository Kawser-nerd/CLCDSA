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
        long Y = long.Parse(input[1]);

        for(int x=0; x<=N; x++)
        {
          // 1???x???
          for(int y=0; y<=(N-x); y++)
          {
            // 5???y????z=N-(x+y)
            int z = N - (x+y);
            if(z<0) continue; // z??????????

            long tama = x*10000 + y*5000 + z*1000;
            if(tama == Y)
            {
              Console.WriteLine(x + " " + y + " " + z);
              return;
            }
          }
        }

    // ??
        Console.WriteLine("-1 -1 -1");
    }
		class myClass{ //?????
			public int ID {set; get;}
			public long Point {set; get;}
		}

}