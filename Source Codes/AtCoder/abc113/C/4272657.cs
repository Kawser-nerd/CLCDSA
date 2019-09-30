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
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        List<List<int> > birth = new List<List<int> >(); // ???N????????
        for(int i=0; i<N; i++)
        {
          List<int> list = new List<int>();
          birth.Add(list);
        }
        // ?????  ????? ???
        int[] year = new int[M];
        for(int i=0; i<M; i++)
        {
          string[] py = Console.ReadLine().Split(' ');
          int P = int.Parse(py[0]);
          int Y = int.Parse(py[1]);
          birth[P-1].Add(Y);
          year[i] = Y;
        }

        // [??????]??????????????
        Dictionary<int, string> idList = new Dictionary<int, string>();
        for(int i=0; i<N; i++)
        {
          List<int> list = birth[i];
          list.Sort();
          for(int j=0; j<list.Count; j++)
          {
            // ??? i+1, ???? j+1
            string id = String.Format("{0:000000}", i+1)
                            + String.Format("{0:000000}", j+1);
            idList[list[j]] = id;
          }
        }





    // ??
        //Console.WriteLine(strct + 1);
        for(int i=0; i<M; i++)
        {
          string id = idList[year[i]];
          Console.WriteLine(id);
        }
    }
		class layer{ //?????
			public long total {set; get;} // ?????
			public long paty {set; get;}  // ?????
      public long banz {set; get;}  // ?????
		}
}