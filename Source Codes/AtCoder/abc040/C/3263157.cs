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
        var num = ToInt32(ReadLine());
        var costs = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var c = new int[num];
        c[0] = 0;
        c[1] = Abs(costs[1] - costs[0]);
        for(var i=2;i<num;i++)
        {
            c[i] = Min(c[i - 2] + Abs(costs[i] - costs[i - 2]), c[i - 1] + Abs(costs[i] - costs[i - 1]));
        }
        WriteLine(c[num-1]);
    }
}