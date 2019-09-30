using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cores
{
  class Program
  {
    static void Main(string[] args)
    {
      string inputFile = (args.Length > 0) ? args[0] : @"..\..\C-small-1-attempt0.in";
      using (var f = new StreamReader(inputFile))
      {
        int nncases = Int32.Parse(f.ReadLine());
        for (int ncase = 1; ncase <= nncases; ++ncase)
        {
          var line = f.ReadLine().Split(' ');
          int n = int.Parse(line[0]);
          int k = int.Parse(line[1]);

          var line2 = f.ReadLine();
          var u = decimal.Parse(line2);

          var line3 = f.ReadLine().Split(' ');
          var c = line3.Select(xx => decimal.Parse(xx)).ToList();
          c.Sort();

          // Small only: n = k.
          // Strategy: spend u on the lowest, until tied with the next lowest then add that to set.

          int x = 1; // 1-based for maths
          while (u > 0.0000001m)
          {
            // Find first X all the same
            while ((x < n) && (c[x - 1] == c[x])) ++x;
            decimal s = c[0] * (x);
            // Next value
            decimal v = (x < n) ? c[x] : 1;
            decimal t = v * x;
            decimal tg = t - s;
            decimal a;

            if (tg < u)
            {
              a = v - c[0];
            }
            else
            {
              // Divide what's left
              a = u / x;
            }

            for (int i = 0; i < x; ++i)
            {
              u -= a;
              c[i] += a;
            }
            if (x >= n) break;
          }

          decimal p = 1;
          foreach (decimal cc in c)
          {
            p *= cc;
          }

          var ss = p.ToString("N6").Replace(",", "");
          Console.WriteLine("Case #{0}: {1}", ncase, ss);
        }
      }
    }
  }
}
