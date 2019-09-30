using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());


        DateTime[] dts = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split('/').Select(x => int.Parse(x)).ToArray()).Select(x => new DateTime(2012, x[0], x[1])).ToArray();
        int max = 0;
        int curstr = 0;
        int furikae = 0;
        DateTime dt = new DateTime(2012, 1, 1);
        for (int i = 0; i < 366; i++)
        {
            if (dt.DayOfWeek == DayOfWeek.Saturday || dt.DayOfWeek == DayOfWeek.Sunday)
            {
                if (dts.Contains(dt)) furikae++;
                curstr++;
            }
            else if (dts.Contains(dt))
            {
                curstr++;
            }
            else if(furikae >= 1)
            {
                furikae--;
                curstr++;
            }
            else
            {
                max = Max(max, curstr);
                curstr = 0;
            }
            dt = dt.AddDays(1);
        }
        max = Max(max, curstr);
        Console.WriteLine(max);
    }
}