using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class D
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Write("Case #" + CASE + ": ");
            int N = int.Parse(Console.ReadLine());
            if (N == 1)
            {
                string[] parts = Console.ReadLine().Split();
                Console.WriteLine(parts[2]);
            }
            else if (N == 2)
            {
                string[] p1 = Console.ReadLine().Split();
                string[] p2 = Console.ReadLine().Split();
                Console.WriteLine(Math.Max(int.Parse(p1[2]), int.Parse(p2[2])));
            }
            else if (N == 3)
            {
                string[] p1 = Console.ReadLine().Split();
                string[] p2 = Console.ReadLine().Split();
                string[] p3 = Console.ReadLine().Split();
                int x1 = int.Parse(p1[0]);
                int y1 = int.Parse(p1[1]);
                int r1 = int.Parse(p1[2]);
                int x2 = int.Parse(p2[0]);
                int y2 = int.Parse(p2[1]);
                int r2 = int.Parse(p2[2]);
                int x3 = int.Parse(p3[0]);
                int y3 = int.Parse(p3[1]);
                int r3 = int.Parse(p3[2]);

                double ret = Math.Max(min2(x1, y1, r1, x2, y2, r2), r3);
                ret = Math.Min(ret, Math.Max(min2(x1, y1, r1, x3, y3, r3), r2));
                ret = Math.Min(ret, Math.Max(min2(x2, y2, r2, x3, y3, r3), r1));
                Console.WriteLine(ret.ToString("0.0000000"));
            }
            else
            {
                throw new Exception();
            }
        }
    }

    public static double min2(int x1, int y1, int r1, int x2, int y2, int r2)
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return (r1 + r2 + Math.Sqrt(dx * dx + dy * dy)) / 2d;
    }
}
