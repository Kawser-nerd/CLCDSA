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
        var ord = input[1];
        var dy = input[2];
        WriteLine(num <= 5 ? dy * num : dy * 5 + ord * (num - 5));
    }
}