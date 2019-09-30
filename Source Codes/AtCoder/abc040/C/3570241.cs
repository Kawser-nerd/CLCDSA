using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var tr = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var costs = new int[num];
        costs[0] = 0;
        costs[1] = Abs(tr[0] - tr[1]);
        for(var i = 2; i < num; i++)
        {
            costs[i] = Min(costs[i - 1] + Abs(tr[i] - tr[i - 1]), costs[i - 2] + Abs(tr[i] - tr[i - 2]));
        }

        WriteLine(costs[num - 1]);
    }
}