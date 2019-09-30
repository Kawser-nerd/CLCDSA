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
        var tv = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var num = ToInt32(ReadLine());
        var xy = new int[num][];
        for (var i = 0; i < num; i++)
            xy[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for(var i = 0; i < num; i++)
        {
            var le = Get(tv[0], tv[1], xy[i][0], xy[i][1]) +
                Get(xy[i][0], xy[i][1], tv[2], tv[3]);
            if (le <= tv[4] * tv[5])
            {
                WriteLine("YES");return;
            }
        }
        WriteLine("NO");

    }
    private static double Get(int sx,int sy,int gx,int gy)
    {
        return Sqrt(Pow(sx-gx, 2) + Pow(sy-gy, 2));
    }
}