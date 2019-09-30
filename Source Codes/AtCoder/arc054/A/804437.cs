using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            int l, x, y, s, d;

            l = Int32.Parse(str[0]);
            x = Int32.Parse(str[1]);
            y = Int32.Parse(str[2]);
            s = Int32.Parse(str[3]);
            d = Int32.Parse(str[4]);

            var solver = new Solver();
            Console.WriteLine(solver.Solve(l, x, y, s, d));
        }
    }

    public class Solver
    {
        public double Solve(int l, int x, int y, int s, int d)
        {
            double leftDist = s > d ? Math.Abs(s - d) : l - Math.Abs(s - d);
            double rightDist = d > s ? Math.Abs(s - d) : l - Math.Abs(s - d);

            return s == d ? 0.0 : Math.Min(
                rightDist / (double)(y + x), y - x <= 0 ? double.MaxValue : leftDist / (double)(y - x)
                );
        }
    }
}