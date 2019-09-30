using System;
using System.IO;
using System.Linq;

namespace CompetitiveProgramming
{

  class Solve
  {
    private void main() 
    {
      int[] t = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int H = t[0], W = t[1];

      bool[,] field = new bool[H + 2, W + 2];

      for (int y = 1; y < H + 1; y++)
      {
        string input = Console.ReadLine();
        for (int x = 1; x < W + 1; x++)
        {
          if (input[x - 1] == '#')
          {
            field[y, x] = true;
          }
        }
      }

      bool[,] cand = new bool[H + 2, W + 2];

      for (int y = 1; y < H + 1; y++)
      {
        for (int x = 1; x < W + 1; x++)
        {
          if (!field[y, x])
          {
            cand[y, x] = cand[y - 1, x] = cand[y - 1, x + 1] = cand[y, x + 1] = cand[y + 1, x + 1] =
              cand[y + 1, x] = cand[y + 1, x - 1] = cand[y, x - 1] = cand[y - 1, x - 1] = true;
          }
        }
      }

      bool[,] temp = new bool[H + 2, W + 2];

      for (int y = 1; y < H + 1; y++)
      {
        for (int x = 1; x < W + 1; x++)
        {
          if (!cand[y, x])
          {
            temp[y, x] = temp[y - 1, x] = temp[y - 1, x + 1] = temp[y, x + 1] = temp[y + 1, x + 1] =
            temp[y + 1, x] = temp[y + 1, x - 1] = temp[y, x - 1] = temp[y - 1, x - 1] = true;
          }
        }
      }

      bool isSolved = true;
      for (int y = 1; y < H + 1 && isSolved; y++)
      {
        for (int x = 1; x < W && isSolved; x++)
        {
          if (temp[y, x] != field[y, x])
          {
            isSolved = false;
            Console.WriteLine("impossible");
          }
        }
      }

      if (isSolved)
      {
        Console.WriteLine("possible");
        for (int y = 1; y < H + 1; y++)
        {
          for (int x = 1; x < W + 1; x++)
          {
            if (cand[y, x])
            {
              Console.Write('.');
            }
            else
            {
              Console.Write('#');
            }
          }
          Console.WriteLine("");
        }
      }
    }

    public Solve()
    {
      Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
      main();
      Console.Out.Flush();
    }
  }

  class Program
  {
    static void Main(string[] args)
    {
      new Solve();
    }
  }

}