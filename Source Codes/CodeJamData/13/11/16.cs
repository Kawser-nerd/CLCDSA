using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bullseye
{
  class Program
  {
    static void Main(string[] args)
    {
      var lines = File.ReadAllLines(args[0]);
      int T = int.Parse(lines[0]);
      for (int i = 1; i <= T; ++i)
      {
        var rt = lines[i].Split(' ');
        var r = long.Parse(rt[0]);
        var t = long.Parse(rt[1]);

        var N = Math.Floor((Math.Sqrt(4 * r * r - 4 * r + 8 * t + 1) - 2 * r + 1) / 4);
        var fullArea = (2 * N + r - 1) * (2 * N + r - 1);
        //var sumWhite = (2 * N - 3) * (2 * N + 2 * r - 1);
        Console.WriteLine("Case #{0}: {1}", i, N);
      }
    }
  }
}
