using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;
using static System.Math;

class Program
{
    struct Position : IComparable<Position>
    {
        public int X;
        public int Y;

        public static int H;
        public static int W;

        public int CompareTo(Position other)
        {
            if (X != other.X) return X - other.X;
            return Y - other.Y;
        }

        public bool IsValid => 0 <= X && X < W && 0 <= Y && Y < H;
    }

    static void Main(string[] args)
    {
        label:
        var sp = ReadLine().Split();
        int h = Position.H = Parse(sp[0]);
        int w = Position.W = Parse(sp[1]);
        var array = new string[h];
        for (int i = 0; i < h; ++i)
        {
            array[i] = ReadLine();
        }
        var watching = new SortedSet<Position>();
        var pos = new Position();
        watching.Add(pos);
        var hosu = new int[h, w];
        hosu[0, 0] = 1;
        while (0 < watching.Count)
        {
            var min = pos = watching.Min;
            Action Check = () =>
              {
                  if (pos.IsValid && array[pos.Y][pos.X] == '.')
                  {
                      int nei = hosu[pos.Y, pos.X];
                      if (nei == 0 || hosu[min.Y, min.X] + 1 < nei)
                      {
                          hosu[pos.Y, pos.X] = hosu[min.Y, min.X] + 1;
                          watching.Add(pos);
                      }
                  }
              };
            --pos.X;
            Check();
            pos.X += 2;
            Check();
            --pos.X;
            --pos.Y;
            Check();
            pos.Y += 2;
            Check();
            watching.Remove(min);
        }
        if (hosu[h - 1, w - 1] == 0) WriteLine(-1);
        else
        {
            int result = 0;
            foreach(var line in array)
            {
                result += line.Count(c => c == '.');
            }
            WriteLine(result - hosu[h - 1, w - 1]);
        }
    }
}