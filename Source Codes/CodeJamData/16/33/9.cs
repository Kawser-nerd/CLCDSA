using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fashion
{
  class Program
  {
    static void Main(string[] args)
    {
      string inputFile = (args.Length > 0) ? args[0] : @"..\..\test.in";
      var input = File.ReadAllLines(inputFile);
      int ncase = 1;

      foreach (string scoresLine in input.Skip(1))
      {
        if (String.IsNullOrWhiteSpace(scoresLine)) continue;

        /* Simple - all permutations, strip ones that don't work */
        var s = scoresLine.Split().Select(Int32.Parse).ToArray();
        int k = s[3];

        var wornab = new int[s[0] + 1, s[1] + 1];
        var wornac = new int[s[0] + 1, s[2] + 1];
        var wornbc = new int[s[1] + 1, s[2] + 1];

        var outfits = new StringBuilder();
        int noutfits = 0;

        /* Scan
        for (int a = 1; a <= s[0]; ++a)
        {
          for (int b = 1; b <= s[1]; ++b)
          {
            for (int c = 1; c <= s[2]; ++c)
            {
              if ((wornab[a, b] < k) && (wornac[a, c] < k) && (wornbc[b, c] < k))
              {
                ++wornab[a, b];
                ++wornac[a, c];
                ++wornbc[b, c];
                outfits.AppendFormat("{0} {1} {2}", a, b, c);
                outfits.AppendLine();
                ++noutfits;
              }
            }
          }
        }
        */

        var all = new HashSet<Tuple<int, int, int>>();
        for (int a = 1; a <= s[0]; ++a)
        {
          for (int b = 1; b <= s[1]; ++b)
          {
            for (int c = 1; c <= s[2]; ++c)
            {
              all.Add(new Tuple<int, int, int>(a, b, c));
            }
          }
        }

        /* Least worn sum?
        for(;;)
        {
          int best = k*3;
          Tuple<int, int, int> t = null;

          foreach (var candidate in all)
          {
            int a = candidate.Item1;
            int b = candidate.Item2;
            int c = candidate.Item3;
            if (wornab[a, b] >= k) continue;
            if (wornbc[b, c] >= k) continue;
            if (wornac[a, c] >= k) continue;

            int wsum = wornab[a, b] + wornac[a, c] + wornbc[b, c];
            if (wsum < best)
            {
              best = wsum;
              t = candidate;
            }
          }

          if (t == null) break;
          outfits.AppendFormat("{0} {1} {2}", t.Item1, t.Item2, t.Item3);
          outfits.AppendLine();
          ++noutfits;
          ++wornab[t.Item1, t.Item2];
          ++wornac[t.Item1, t.Item3];
          ++wornbc[t.Item2, t.Item3];
          all.Remove(t);
        }
        */

        // All permutations
        var best = new List<Tuple<int, int, int>>();
        int max = s[0]*s[1]*s[2];
        AllPerms(all.ToList(), 0, wornab, wornac, wornbc, k, max, new List<Tuple<int, int, int>>(), ref best);

        noutfits = best.Count;
        foreach (var t in best)
        {
          outfits.AppendFormat("{0} {1} {2}", t.Item1, t.Item2, t.Item3);
          outfits.AppendLine();
        }

        Console.WriteLine("Case #{0}: {1}", ncase, noutfits);
        Console.Write(outfits);
        ++ncase;
      }
    }

    static void AllPerms(List<Tuple<int, int, int>> all, int n, int[,] wornab, int[,] wornac, int[,] wornbc, int k, int max, List<Tuple<int, int, int>> sofar, ref List<Tuple<int, int, int>> best)
    {
      if (best.Count == max) return;

      if (n >= all.Count)
      {
        if (sofar.Count > best.Count) best = new List<Tuple<int, int, int>>(sofar);
        return;
      }

      var t = all[n];
      int a = t.Item1;
      int b = t.Item2;
      int c = t.Item3;

      bool ok = (wornab[a, b] < k) && (wornac[a, c] < k) && (wornbc[b, c] < k);
      if (ok)
      {
        ++wornab[a, b];
        ++wornac[a, c];
        ++wornbc[b, c];
        sofar.Add(t);
        AllPerms(all, n + 1, wornab, wornac, wornbc, k, max, sofar, ref best);
        sofar.Remove(t);
        --wornab[a, b];
        --wornac[a, c];
        --wornbc[b, c];
      }

      AllPerms(all, n + 1, wornab, wornac, wornbc, k, max, sofar, ref best);
    }
  }
}
