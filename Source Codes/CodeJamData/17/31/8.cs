using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QA
{
  class Program
  {
    class Pancake
    {
      public Pancake(long r, long h)
      {
        R = r;
        H = h;
        Top = (double)r * (double)r;
        Side = 2 * (double)r * (double)h;
      }

      public long R;
      public long H;
      public double Side;
      public double Top;

      public override string ToString()
      {
        return String.Format("{0},{1} side={3} top={2}", R, H, Top, Side);
      }
    }



    static void Main(string[] args)
    {
      // Math.PI

      string inputFile = (args.Length > 0) ? args[0] : @"..\..\A-small-attempt0.in";
      using (var f = new StreamReader(inputFile))
      {
        int nncases = Int32.Parse(f.ReadLine());
        for (int ncase = 1; ncase <= nncases; ++ncase)
        {
          var line = f.ReadLine().Split(' ');
          int n = int.Parse(line[0]);
          int k = int.Parse(line[1]);
          var p = new List<Pancake>();
          for (int i = 0; i < n; ++i)
          {
            var line2 = f.ReadLine().Split(' ');
            p.Add(new Pancake(long.Parse(line2[0]), long.Parse(line2[1])));
          }

          // Take K pancakes with largest Side
          // Try substituting any other pancake with a larger top

          p.Sort(SideDesc);

          var topSide = p.Take(k).ToList();
          var rest = p.Skip(k).ToList();
          var maxTop = topSide.Max(x => x.Top);
          var biggerTop = rest.Where(x => x.Top > maxTop);

          var top1 = topSide.Take(k - 1).ToList();
          var topK = topSide.Last();

          double best = topSide.Sum(x => x.Side) + maxTop;
          double best1 = top1.Sum(x => x.Side);

          foreach (var pk in biggerTop)
          {
            double t = best1 + pk.Top + pk.Side;
            if (t > best) best = t;
          }

          var score = ((double) best) * Math.PI;

          var ss = score.ToString("N6").Replace(",", "");
          Console.WriteLine("Case #{0}: {1}", ncase, ss);
        }
      }
    }

    private static int SideDesc(Pancake pancake, Pancake pancake1)
    {
      double s = pancake1.Side - pancake.Side;
      if (s == 0) s = pancake1.Top - pancake.Top;
      return (s > 0) ? 1 : ((s < 0) ? -1 : 0);
    }
  }
}
