using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using Debug;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var min = str.Length;
        for (var i = 0; i < str.Length - 1; i++)
            if (str[i] != str[i + 1])
                min = Min(min, Max(i + 1, str.Length - 1 - i));
        WriteLine(min);
    }
}