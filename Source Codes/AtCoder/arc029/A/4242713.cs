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
//Console.WriteLine("????");
        // ??????????
        int min = 101;
        for(int i=0; i<Math.Pow(2,N); i++)
        {
          //Console.WriteLine((i/8)%2 + " " + (i/4)%2 + " " + (i/2)%2 + " " + i%2);
          int a = 0, b = 0;
          int bit = i;
          for(int j=0; j<N; j++)
          {
            if(bit%2 == 0)
            {
              a += t[j];
            }else
            {
              b += t[j];
            }
            bit /= 2;
          }
          //Console.WriteLine(a + " " + b);
          if(min > Math.Max(a,b))
            min = Math.Max(a,b);
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