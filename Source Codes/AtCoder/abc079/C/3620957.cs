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
        var number = ReadLine();
        for (var i = 0; i < Pow(2, 3); i++)
        {
            var sum = ToInt32(number.Substring(0, 1));
            var resu = number.Substring(0, 1);
            for (var j = 0; j < 3; j++)
            {
                var n = ToInt32(number.Substring(j + 1, 1));
                if (((i >> j) & 1) == 1) { sum += n; resu += "+" + n; }
                else { sum -= n; resu += "-" + n; }
            }
            if (sum == 7) { WriteLine(resu+"=7"); return; }
        }
    }
}