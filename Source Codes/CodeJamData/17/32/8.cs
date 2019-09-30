using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parenting
{
  class Program
  {
    class Span
    {
      public Span(int w, int s, int e)
      {
        Who = w;
        Start = s;
        End = e;
      }
      public int Who;
      public int Start;
      public int End;

      public int Time { get { return End - Start; } }

      public override string ToString()
      {
        return String.Format("{0} - {1}: {2}", Start, End, Who);
      }
    }

    static void Main(string[] args)
    {
      string inputFile = (args.Length > 0) ? args[0] : @"..\..\test.in";
      using (var f = new StreamReader(inputFile))
      {
        int nncases = Int32.Parse(f.ReadLine());
        for (int ncase = 1; ncase <= nncases; ++ncase)
        {
          var line = f.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();

          // Coalesce adjacent activities from same
          // Start considering from first activity, since it has a guaranteed babysitter
          // Special case no activities = 2
          // c = 0, j = 1

          var day = new List<Span>();

          for (int i = 0; i < line.Length; ++i)
          {
            for (int j = 0; j < line[i]; ++j)
            {
              var line2 = f.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();
              day.Add(new Span(i, line2[0], line2[1]));
            }
          }

          // Day is trivially solved if at most one activity each
          if ((day.Count(sp => sp.Who == 0) <= 1) && (day.Count(sp => sp.Who == 1) <= 1))
          {
            // Special case: no or one activity
            Console.WriteLine("Case #{0}: {1}", ncase, 2);
            continue;
          }

          // Rescale day to start at first activity
          int fa = day.Min(s => s.Start);
          foreach (var sp in day)
          {
            sp.Start -= fa;
            sp.End -= fa;
          }

          // Coalesce
          day.Sort(StartCompare);
          bool changed;
          do
          {
            changed = false;
            for (int i = 1; i < day.Count; ++i)
            {
              if ((day[i - 1].End == day[i].Start) && (day[i - 1].Who == day[i].Who))
              {
                day[i - 1].End = day[i].End;
                day.RemoveAt(i);
                changed = true;
                break;
              }
            }
          } while (changed);

          if ((day.Count(sp => sp.Who == 0) <= 1) && (day.Count(sp => sp.Who == 1) <= 1))
          {
            // Special case: no or one activity, coalesced down
            Console.WriteLine("Case #{0}: {1}", ncase, 2);
            continue;
          }

          // Fill in rest of day
          day.Sort(StartCompare);
          var extra = new List<Span>();
          var left = new[] { 720, 720 };
          for (int i = 0; i < day.Count; ++i)
          {
            left[day[i].Who] -= day[i].Time;
            int end = day[i].End;
            int next = ((i + 1) < day.Count) ? day[i + 1].Start : 1440;
            if (next > end) extra.Add(new Span(-1, end, next));
          }
          foreach(var sp in extra) day.Add(sp);
          day.Sort(StartCompare);

          repeat:
          // If one partner has no time left, allocate all to other
          for (int i = 0; i < 2; ++i)
          {
            if (left[i] == 0)
            {
              foreach (var sp in day.Where(xxx => xxx.Who == -1))
              {
                sp.Who = 1 - i;
              }
              goto complete;
            }
          }

          // Find gaps between adjacent activities of same partner
          // Coalesce smallest gap
          int smallestGap = 1440;
          int smallestI = -1;

          for (int i = 0; i < day.Count; ++i)
          {
            var prev = (i > 0) ? day[i - 1] : day.Last();
            var t = day[i];
            var next = ((i + 1) < day.Count) ? day[i + 1] : day[0];

            if (t.Who == -1)
            {
              if ((prev.Who == next.Who) && (left[prev.Who] >= t.Time))
              {
                if (smallestGap > t.Time)
                {
                  smallestGap = t.Time;
                  smallestI = i;
                }
              }
            }
          }

          if (smallestI >= 0)
          {
            int i = smallestI;
            var prev = (i > 0) ? day[i - 1] : day.Last();
            var t = day[i];
            var next = ((i + 1) < day.Count) ? day[i + 1] : day[0];
            left[prev.Who] -= t.Time;
            if (next.End > prev.End)
            {
              prev.End = next.End;
              day.Remove(t);
              day.Remove(next);
            }
            else
            {
              // Wrapping around the end :-(
              prev.End = next.End + 1440;
              day.Remove(t);
              day.Remove(next);
            }
            goto repeat;
          }

          //qq might work? Console.WriteLine("Case #{0}: MORE LOGIC", ncase);
          // continue;

          // Done as much as we can. If gap is C-gap-C, two swaps; if C-gap-J one swap.
          // So make C-gap-J = C, then can count
          for (int i = 0; i < day.Count; ++i)
          {
            var prev = (i > 0) ? day[i - 1] : day.Last();
            var t = day[i];
            var next = ((i + 1) < day.Count) ? day[i + 1] : day[0];

            if (t.Who == -1)
            {
              if (prev.Who == next.Who)
              {
                t.Who = 1 - prev.Who;
              }
              else
              {
                t.Who = prev.Who;
              }
            }
          }

          complete:
          int swaps = 0;

          // This should now just be the number of items (maybe excluding roll-over) but count anyway
          int on = day.Last().Who;
          foreach (var sp in day)
          {
            if (sp.Who != on)
            {
              ++swaps;
              on = sp.Who;
            }
          }

          Console.WriteLine("Case #{0}: {1}", ncase, swaps);
        }
      }
    }

    private static int StartCompare(Span a, Span b)
    {
      return a.Start - b.Start;
    }
  }
}
