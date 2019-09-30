using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var xy = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 0;

        if (xy[0] < xy[1])
        {
            if (Abs(xy[0]) >= Abs(xy[1])) result += xy[1]<=0?xy[1]-xy[0]:1-xy[1] - xy[0];
            else result += xy[0]>=0?xy[1]-xy[0]:1+xy[1] - Abs(xy[0]);
        }
        else
        {
            if (Abs(xy[0]) <= Abs(xy[1])) result += xy[0] < 0 ? 2 - xy[1] + xy[0] : -xy[1] - xy[0] + 1;
            else result += xy[1] <= 0 ? 1 + xy[1] + xy[0] : 2 + xy[0] - xy[1];
        }
        WriteLine(result);
    }
}