using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace energy
{
  class Program
  {
    static void Main(string[] args)
    {
      var lines = File.ReadAllLines(args[0]);
      int T = int.Parse(lines[0]);
      for (int i = 1; i <= T; ++i)
      {
        var ERN = lines[i * 2 - 1].Split(' ');
        int E = int.Parse(ERN[0]);
        int R = int.Parse(ERN[1]);
        int N = int.Parse(ERN[2]);

        var v = lines[i * 2].Split(' ').Select(int.Parse).ToArray();

        int max = Search(0, E, E, R, v);
        
        Console.WriteLine("Case #{0}: {1}", i, max);
      }
    }

    private static int Search(int i, int curE, int maxE, int R, int[] v)
    {
      int max = 0;

      for (int spend = 0; spend <= curE; ++spend)
      {
        int gain = v[i] * spend;
        if (i < v.Length - 1)
          gain += Search(i + 1, Math.Min(maxE, curE - spend + R), maxE, R, v);

        max = Math.Max(max, gain);
      }

      return max;
    }
  }
}
