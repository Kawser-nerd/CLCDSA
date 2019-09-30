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
        var str = ReadLine();
        if ((str.Contains('W') &&
            str.Contains('N') &&
            str.Contains('E') &&
            str.Contains('S'))||
            (str.Contains('W')&&
            str.Contains('E')&&
            !str.Contains('N')&&
            !str.Contains('S'))||
            (str.Contains('N')&&
            str.Contains('S')&&
            !str.Contains('W')&&
            !str.Contains('E')))WriteLine("Yes");
        else WriteLine("No");
    }
}