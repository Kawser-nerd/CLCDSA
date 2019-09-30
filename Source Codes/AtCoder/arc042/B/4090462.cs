using System;
using System.Web;
using System.IO;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using static System.Math;
 

class P
{
    static void Main()
    {
        int[] xy = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        double minLength = double.MaxValue;
        int[] firstxy = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] lastxy = firstxy;
        for (int i = 0; i < n; i++)
        {
            double x1 = lastxy[0];
            double y1 = lastxy[1];
            lastxy = i == n - 1 ? firstxy : Console.ReadLine().Split().Select(int.Parse).ToArray();
            double x2 = lastxy[0];
            double y2 = lastxy[1];
            double x0 = xy[0];
            double y0 = xy[1];
            var a = x2 - x1;
            var b = y2 - y1;
            var a2 = a * a;
            var b2 = b * b;
            var r2 = a2 + b2;
            var tt = -(a * (x1 - x0) + b * (y1 - y0));
            double dist = 0;
            if (tt < 0)
            {
                dist = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
            }
            else if (tt > r2)
            {
                dist = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);
            }
            else
            {
                var f1 = a * (y1 - y0) - b * (x1 - x0);
                dist = (f1 * f1) / r2;
            }
            minLength = Min(minLength, dist);
        }
        Console.WriteLine(Sqrt(minLength));
    }
}