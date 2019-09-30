using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        WriteLine(Math.Pow(ToDouble(ReadLine()), (double)1 / 4));
    }
}