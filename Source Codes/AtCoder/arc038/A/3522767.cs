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
        var car = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        WriteLine(car.OrderByDescending(b=>b).
            Where((name, index) => index % 2 == 0).ToArray().Sum());

    }
}