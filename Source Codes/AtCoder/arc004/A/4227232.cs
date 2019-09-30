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
        int[,] point = new int[2,N];
        point = getCoordinate(N);

        // 2???????????
        double maxDistance = 0;
        for(int i = 0; i<N; i++)
        {
          int x1 = point[0, i];
          int y1 = point[1, i];
          for(int j=i+1; j<N; j++)
          {
              // ?i??j?????????
              int x2 = point[0, j];
              int y2 = point[1, j];
              double dis = Math.Sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
              if(maxDistance < dis) maxDistance = dis;
          }
        }
    // ??
        Console.WriteLine(maxDistance);
    }
		class myClass{ //?????
			public int ID {set; get;}
			public long Point {set; get;}
		}

		static private int[,] getCoordinate(int N)
		{
      // N?????????
      int[,] ret = new int[2,N];
      for(int i=0; i<N; i++)
      {
        string[] xy = Console.ReadLine().Split(' ');
        ret[0,i] = int.Parse(xy[0]);
        ret[1,i] = int.Parse(xy[1]);
      }
			return ret;
		}

}