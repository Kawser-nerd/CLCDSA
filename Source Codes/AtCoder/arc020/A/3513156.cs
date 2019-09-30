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
        var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        WriteLine(Abs(input[0]) == Abs(input[1]) ? "Draw" :
            Abs(input[0]) < Abs(input[1]) ? "Ant" : "Bug");
    }
}