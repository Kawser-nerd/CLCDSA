using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace B
{
    class Program
    {
        static string Solve(int X, int Y)
        {
            int x = 0;
            int y = 0;

            StringBuilder sb = new StringBuilder();
            while (x < X)
            {
                sb.Append("WE");
                x++;
            }
            while (x > X)
            {
                sb.Append("EW");
                x--;
            }
            while (y < Y)
            {
                sb.Append("SN");
                y++;
            }
            while (y > Y)
            {
                sb.Append("NS");
                y--;
            }

            return sb.ToString();
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int X = int.Parse(line[0]);
                int Y = int.Parse(line[1]);
                Console.WriteLine("Case #{0}: {1}", t, Solve(X, Y));
            }
        }
    }
}
