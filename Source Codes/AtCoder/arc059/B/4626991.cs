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
        for(var j=2;j<4;j++)
            for(var i = 0; i < str.Length - j + 1; i++)
            {
                var s = str.Substring(i, j);
                if (j == 2 && s[0] == s[1])
                {
                    WriteLine($"{i + 1} {i + j}");
                    return;
                }
                if (j == 3 && s[0] == s[2])
                {
                    WriteLine($"{i + 1} {i + j}");
                    return;
                }
            }
        WriteLine("-1 -1");
    }
}