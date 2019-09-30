using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var num = ToInt32(input[0]);
        var colorFig = ToInt32(input[1]);
        WriteLine(colorFig * Math.Pow(colorFig - 1, num - 1));

    }
}