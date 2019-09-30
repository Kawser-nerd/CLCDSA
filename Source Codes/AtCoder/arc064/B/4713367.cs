using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        WriteLine((str.Length % 2 == 0) ^ (str[0] == str[str.Length - 1]) ? "Second" : "First");
    }
}