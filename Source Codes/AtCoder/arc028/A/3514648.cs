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
        var num = input[0];
        var an = input[1];
        var bu = input[2];
        var i = 0;
        while (num > 0) {
            num = i % 2 == 0 ? num - an : num - bu;
            i++;
        }
        WriteLine(i % 2 == 1 ? "Ant" : "Bug");
    }
}