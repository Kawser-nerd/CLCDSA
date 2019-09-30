using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var d = new Dictionary<int, int[]>();
        var n = int.Parse(Console.ReadLine().Trim());
        var a = new int[n, 2];
        var rmax = 0;
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            var r = int.Parse(line[0]);
            rmax = Math.Max(rmax, r);
            var h = int.Parse(line[1]);
            a[i, 0] = r;
            a[i, 1] = h;
            if (d.ContainsKey(r)) d[r][h]++;
            else
            {
                d[r] = new int[4];
                d[r][h]++;
            }
            d[r][0]++;
        }
        var rk = 0; var rsum = 0;
        for (int i = 1; i <= rmax; i++)
            if (d.ContainsKey(i)) { rsum += d[i][0]; d[i][0] = rk; rk = rsum; }
        printAns(d, a, n);
    }
    public static void printAns(Dictionary<int, int[]> d, int[,] a, int n)
    {
        int p1; int p2;
        for (int i = 0; i < n; i++)
        {
            var r = a[i, 0];
            var h = a[i, 1];
            if (h == 1)
            {
                p1 = d[r][0] + d[r][2];
                p2 = d[r][1] - 1;
            }
            else if (h == 2)
            {
                p1 = d[r][0] + d[r][3];
                p2 = d[r][2] - 1;
            }
            else
            {
                p1 = d[r][0] + d[r][1];
                p2 = d[r][3] - 1;
            }
            Console.WriteLine("{0} {1} {2}", p1, n - 1 - p1 - p2, p2);
        }
    }
}