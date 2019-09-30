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
        var res = 0L;
        for (var i = 0; i < str.Length; i++)
        {
            if (str[i] == 'U')
                res += str.Length - i - 1 + 2 * i;
            else
                res += i + 2 * (str.Length - i - 1);
        }
        WriteLine(res);
    }
}