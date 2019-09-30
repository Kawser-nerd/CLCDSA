using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] abc = Console.ReadLine().Split().Select(int.Parse).ToArray();
        double freq = (1d / abc[2]);
        double min = Math.Floor((100d / abc[0]) / freq) * freq;
        while (takBall(abc,min) <= 99.999999)
        {
            min += 0.00000001;
        }
        while (takBall(abc, min) >= 100.000001)
        {
            min -= 0.000000001;
        }
        while (takBall(abc, min) <= 99.999999)
        {
            min += 0.0000000001;
        }
        while (takBall(abc, min) >= 100.000001)
        {
            min -= 0.00000000001;
        }
        Debug.WriteLine(takBall(abc, min));
        Console.WriteLine(min);
    }
    static double takBall(int[] abc, double t) => abc[0] * t + abc[1] * Math.Sin(abc[2] * t * Math.PI);
}