using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_B
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
        var split = line.Split(' ');
        var c = int.Parse(split[0]);
        var j = int.Parse(split[1]);

        var cs = Enumerable.Range(0, c).SelectMany(i => Console.ReadLine().Split(' ').Select(int.Parse)).ToArray();
        var js = Enumerable.Range(0, j).SelectMany(i => Console.ReadLine().Split(' ').Select(int.Parse)).ToArray();


        var res = Solve(c, j, cs, js);
        Console.WriteLine($"Case #{caseNo++}: {res}");
      }

    }

    private static string Solve(int c, int j, int[] cs, int[] js)
    {
      if (c + j == 1 || c == j) return "2";

      var events = c == 0 ? js : cs;

      var a = events[3] - events[0] < 0 ? events[3] - events[0] + 24*60 : events[3] - events[0];
      var b = events[1] - events[2] < 0 ? events[1] - events[2] + 24*60 : events[1] - events[2];

      if (a <= 720 || b <= 720) return "2";

      return "4";
    }
  }
}
