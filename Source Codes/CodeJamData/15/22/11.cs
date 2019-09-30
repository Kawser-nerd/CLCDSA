using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_BB
{
  class Program
  {
    static void Main(string[] args)
    {
      int tests = ReadInt();
      for (int test = 1; test <= tests; ++test)
      {
        var tc = ReadInts(3);
        int r = tc[0];
        int c = tc[1];
        int n = tc[2];

        int g = r * c;
        int best = g * 2;
        int m = 1 << g;
        for(int i = 0; i < m; ++i)
        {
          int o = 0;
          int u = 0;
          for (int j = 0; j < g; ++j)
          {
            if ((i & (1 << j)) != 0)
            {
              ++o;
              int x = j % r;
              if ((x > 0) && ((i & (1 << (j - 1))) != 0)) ++u;
              int y = j / r;
              if ((y > 0) && ((i & (1 << (j - r))) != 0)) ++u;
            }
          }
          if ((o == n) && (u < best)) best = u;
        }

        Console.WriteLine("Case #{0}: {1}", test, best);
      }
    }


    static int ReadInt()
    {
      return Convert.ToInt32(Console.ReadLine());
    }

    static IEnumerable<String> ReadStrings()
    {
      string line = Console.ReadLine();
      return line.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
    }

    static IEnumerable<int> ReadInts()
    {
      return ReadStrings().Select(s => Convert.ToInt32(s));
    }

    static IEnumerable<long> ReadLongs()
    {
      return ReadStrings().Select(s => Convert.ToInt64(s));
    }

    static int[] ReadInts(int count)
    {
      return ReadInts().Take(count).ToArray();
    }
  }
}
