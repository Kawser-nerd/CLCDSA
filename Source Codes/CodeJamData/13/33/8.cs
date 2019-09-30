using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Collections;
using System.Drawing;

namespace Google1
{
  class Program
  {
    static System.Numerics.BigInteger Cost(System.Numerics.BigInteger radius, System.Numerics.BigInteger rings)
    {
      return 2 * radius * rings + 2 * rings * rings - rings;
    }

    static int FindLayer(int number)
    {
      int layer = 1;
      int total = 1;
      while (total < number)
      {
        total += LayerSize(layer + 1);
        layer++;
      }
      return layer;
    }

    static int LayerSize(int layer)
    {
      return 1 + 4*(layer-1);
    }

    static int LayerTotalSize(int layer)
    {
      if (layer <= 0) return 0;
      return LayerSize(layer) + LayerTotalSize(layer - 1);
    }

    static int Factorial(int x)
    {
      if (x <= 1) return 1;
      return x * Factorial(x - 1);
    }

    static int Choose(int x, int y)
    {
      return Factorial(x) / Factorial(y) / Factorial(x - y);
    }

    class Tribe
    {
      public int nextAttackDay;
      public int remainingAttacks;
      public int west;
      public int east;
      public int strength;
      public int deltaDays;
      public int deltaDistance;
      public int deltaStrength;
    }

    class Range : IComparable<Range>
    {
      public int start;
      public int end;
      public int height;

      public int CompareTo(Range other)
      {
        return start.CompareTo(end);
      }
    }

    static bool CheckAttack(int[] heights, int west, int east, int strength)
    {
      for (int i = 2*west + 2000000; i <= 2*east + 2000000; i++)
      {
        if (heights[i] < strength)
        {
          return true;
        }
      }
      return false;
    }

    static void ApplyAttack(int[] heights, int west, int east, int strength)
    {
      for (int i = 2 * west + 2000000; i <= 2 * east + 2000000; i++)
      {
        if (heights[i] < strength)
        {
          heights[i] = strength;
        }
      }
    }

    static void Main(string[] args)
    {
      using( StreamWriter writer = File.CreateText("result.txt") )
      using (StreamReader reader = File.OpenText("C-small-attempt0.in"))
      {
        string line = reader.ReadLine();
        int testCount = Int32.Parse(line);

        for (int test = 0; test < testCount; test++)
        {
          string[] values = reader.ReadLine().Split(new char[] { ' ' });
          int tribeCount = System.Int32.Parse(values[0]);
          List<Tribe> tribes = new List<Tribe>();
          for (int i = 0; i < tribeCount; i++)
          {
            Tribe t = new Tribe();
            values = reader.ReadLine().Split(new char[] { ' ' });
            t.nextAttackDay = System.Int32.Parse(values[0]);
            t.remainingAttacks = System.Int32.Parse(values[1]);
            t.west = System.Int32.Parse(values[2]);
            t.east = System.Int32.Parse(values[3]);
            t.strength = System.Int32.Parse(values[4]);
            t.deltaDays = System.Int32.Parse(values[5]);
            t.deltaDistance = System.Int32.Parse(values[6]);
            t.deltaStrength = System.Int32.Parse(values[7]);
            tribes.Add(t);
          }

          int[] heights = new int[4*1000000+50];
          int result = 0;

          while (tribes.Count > 0)
          {
            int minDay = int.MaxValue;
            List<Tribe> attackingTribes = new List<Tribe>();
            foreach (Tribe t in tribes)
            {
              if (t.nextAttackDay < minDay)
              {
                minDay = t.nextAttackDay;
                attackingTribes = new List<Tribe>();
                attackingTribes.Add(t);
              }
              else if (t.nextAttackDay == minDay)
              {
                attackingTribes.Add(t);
              }
            }

            // Perform attack
            foreach (Tribe t in attackingTribes)
            {
              if (CheckAttack(heights, t.west, t.east, t.strength))
              {
                result++;
              }
            }
            foreach (Tribe t in attackingTribes)
            {
              ApplyAttack(heights, t.west, t.east, t.strength);
              t.remainingAttacks--;
              t.nextAttackDay += t.deltaDays;
              t.east += t.deltaDistance;
              t.west += t.deltaDistance;
              t.strength += t.deltaStrength;

              if (t.remainingAttacks <= 0)
              {
                tribes.Remove(t);
              }
            }

          }

          Console.Out.WriteLine(string.Format("Case #{0}: {1}", test + 1, result));
          writer.WriteLine(string.Format("Case #{0}: {1}", test + 1, result));
        }

        writer.Close();
        reader.Close();
      }
    }
  }
}
