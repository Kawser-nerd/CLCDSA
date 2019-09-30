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
        var weights = new int[num];
        for (var i = 0; i < num; i++) weights[i] = ToInt32(ReadLine());
        var list = new List<int>() { weights[0]};
        for(var i = 1; i < num; i++)
        {
            var min = int.MaxValue;
            var f = -1;
            for(var j = 0; j < list.Count; j++)
            {
                if (list[j] >= weights[i]&&min>Abs(list[j]-weights[i]))
                {
                    min =Abs(list[j] - weights[i]);
                    f = j;
                }
            }
            if (f != -1) list[f] = weights[i];
            else list.Add(weights[i]);
        }
        WriteLine(list.Count);
    }
}