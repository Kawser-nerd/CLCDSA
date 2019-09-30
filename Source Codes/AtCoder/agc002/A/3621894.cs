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
        var ab = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        if (ab[0] > 0) WriteLine("Positive");
        else if (ab[0] == 0 || ab[1] >= 0) WriteLine("Zero");
        else if ((ab[1] - ab[0] + 1) % 2 == 0) WriteLine("Positive");
        else WriteLine("Negative");
    }
}