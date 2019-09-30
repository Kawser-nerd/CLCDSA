using System;
using System.Linq;

namespace AtCoder.ABC121.A
{
    class Program
    {
        public static void Main()
        {
            // Solve(3, 2, 2, 1);
            // Solve(5, 5, 2, 3);
            // Solve(2, 4, 2, 4);

            var a = Console.ReadLine().Split(' ');
            var H = int.Parse(a[0]);
            var W = int.Parse(a[1]);
            var b = Console.ReadLine().Split(' ');
            var h = int.Parse(b[0]);
            var w = int.Parse(b[1]);
            Solve(H, W, h, w);
        }

        static void Solve(int H, int W, int h, int w)
        {
            Console.WriteLine((H * W) - (h * W) - (w * H) + (h * w));
        }
    }
}