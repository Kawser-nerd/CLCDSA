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
        long X = long.Parse(input[1]);

        long ret = fullEat(N,X);


    // ??
        Console.WriteLine(ret);
    }
		class layer{ //?????
			public long total {set; get;} // ?????
			public long paty {set; get;}  // ?????
      public long banz {set; get;}  // ?????
		}
    static private long fullEat(int N, long X)
    {
      // ???1????? BPPPB????????????
      if(N == 1)
      {
        long ret = 0;
        if(X == 5) ret = X - 2;
        else ret = X - 1;
        return ret;
      }
      // ?????????????
      if(X <= 1)
      {
        // ???????????????
        return 0;
      }
      layer burger = getLayerNum(N);
      if(burger.total == X)
      {
        //???N??????????????
        return burger.paty;
      }

      if(X == (burger.total-3)/2 + 1)
      {
        // ???N-1??????????????????
        return getLayerNum(N-1).paty;
      }else if(X == (burger.total-3)/2 + 2)
      {
        // ???????N-1????????????
        return getLayerNum(N-1).paty + 1;
      }else if(X > (burger.total-3)/2 + 2)
      {
        // ???????N-1????????????????N-1???????????
        layer burger_s = getLayerNum(N-1);
        long eated = burger_s.paty + 1;
        long rest = X - (burger_s.total + 2);
        return eated + fullEat(N-1, rest);
      }else
      {
        // ???N-1????????????????????????????????N-1???????????
        return fullEat(N-1, X-1);
      }
    }

    static private layer getLayerNum(int N)
    {
      layer ret = new layer();
      // ??? 2^(N+2)-3??????2^(N+1)-1, ????2^(N+1)-2
      long power = (long)Math.Pow(2, N+1);
      ret.total = power*2 - 3;
      ret.paty = power -1;
      ret.banz = power -2;
      return ret;
    }


}