//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;

public class Test
{
    public class Pair
    {
        public long Red;
        public long Blue;

        public Pair(long x, long y)
        {
            Red = x;
            Blue = y;
        }

        public void Swap()
        {
            var temp = Red;
            Red = Blue;
            Blue = temp;
        }
    }

    public static void Main()
    {
        var N = int.Parse(Console.ReadLine());
        var xy = new Pair[N];

        for (int i = 0; i < N; i++)
        {
            var line2 = Console.ReadLine().Split(' ').Select(z => long.Parse(z)).ToArray();
            xy[i] = new Pair(
                Math.Max(line2[0], line2[1]),
                Math.Min(line2[0], line2[1]));
        }

        xy = xy.OrderBy(z => z.Blue).ToArray();
        
        var Rmax = xy.Select(x => x.Red).Max();
        var Rmin = xy.Select(x => x.Red).Min();
        var Bmax = xy[N - 1].Blue;
        var Bmin = xy[0].Blue;

        var MAX = Rmax;
        var MIN = Bmin;

        var Pmin = (Rmax - Rmin) * (Bmax - Bmin);

        var SwappedBlueMin = long.MaxValue;
        var SwappedBlueMax = long.MinValue;

        for (int i = 0; i <= N - 2; i++)
        {
            xy[i].Swap();
            SwappedBlueMin = Math.Min(SwappedBlueMin, xy[i].Blue);
            SwappedBlueMax = Math.Max(SwappedBlueMax, xy[i].Blue);

            Rmin = MIN;
            Bmin = Math.Min(SwappedBlueMin, xy[i + 1].Blue);
            Bmax = Math.Max(SwappedBlueMax, xy[N - 1].Blue);

            var P = (Rmax - Rmin) * (Bmax - Bmin);

            Pmin = Math.Min(Pmin, P);
        }

        Console.WriteLine(Pmin);
    }
}