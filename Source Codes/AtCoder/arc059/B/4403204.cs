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
        var s = ReadLine();
        for(var k = 0; k < 2; k++)
        {
            for(var i = 0; i < s.Length - k - 1; i++)
            {
                if (k == 0 && s[i] == s[i + 1])
                {
                    WriteLine($"{i + 1} {i + 2}");
                    return;
                }
                if (k == 1 && s[i] == s[i + 2])
                {
                    WriteLine($"{i + 1} {i + 3}");
                    return;
                }
            }
        }
        WriteLine("-1 -1");
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}