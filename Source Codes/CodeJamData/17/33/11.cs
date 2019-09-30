using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_C
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
        var work = double.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
        var cores = Console.ReadLine().Split(' ').Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToList();

        var res = Solve(n, k, work, cores);
        Console.WriteLine($"Case #{caseNo++}: {res}");
      }

    }

    private static string Solve(int n, int k, double work, List<double> cores)
    {
      cores.Sort((d, d1) => d.CompareTo(d1));

      for (int i = 1; i <= n; i++)
      {
        var imp = (cores.Take(i).Sum() + work) / i;

        if (i == n)
        {
          return Math.Pow(imp, n).ToString(CultureInfo.InvariantCulture);
        }

        if (imp > cores[i])
        {
          continue;
        }

        return (Math.Pow(imp, i)*cores.Skip(i).Aggregate((d, d1) => d*d1)).ToString(CultureInfo.InvariantCulture);
      }
      return
      "UNEXP";
    }
  }
}

