using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_A
{
  class Program
  {
    static void Main(string[] args)
    {

      Console.ReadLine();

      string line;
      int caseNo = 1;
      while ((line = Console.ReadLine()) != null)
      {
        int n, k;

        var split = line.Split(' ');
        n = int.Parse(split[0]);
        k = int.Parse(split[1]);

        var cakes = Enumerable.Range(1, n).Select(i => Console.ReadLine()).ToList();
        cakes.Sort((a, b) => int.Parse(b.Split(' ')[0]).CompareTo(int.Parse(a.Split(' ')[0])));

        var height = cakes.Select(s => int.Parse(s.Split(' ')[1])).ToArray();
        var radius = cakes.Select(s => int.Parse(s.Split(' ')[0])).ToArray();


        var res = Solve(n, k, radius, height);
        Console.WriteLine($"Case #{caseNo++}: {res}");
      }
    }

    private static string Solve(int n, int k, int[] radius, int[] height)
    {
      var sides = height.Select((h, index) => Math.PI*2.0*h*radius[index]).Select((d, i) => new {idx = i, side = d}).ToList();
      sides.Sort((a, b)=> b.side.CompareTo(a.side));


      double max = 0;
      for (int i = 0; i <= n-k; i++)
      {
        var others = sides.Where(arg => arg.idx > i).Take(k - 1).Sum(arg => arg.side);
        var bottom = Math.PI*radius[i]*radius[i] + Math.PI*2.0*height[i]*radius[i];
        var sum = others + bottom;

        max = Math.Max(max, sum);
      }

      return max.ToString(CultureInfo.InvariantCulture);
    }
  }
}
