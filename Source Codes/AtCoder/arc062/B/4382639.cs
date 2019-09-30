using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var g = 0;
        var p = 0;
        var resv = 0;
        var resl = 0;
        for(var i = 0; i < str.Length; i++)
        {
            if (str[i] == 'g')
            {
                if (g > p)
                {
                    p++;
                    resv++;
                }
                else g++;
            }
            else
            {
                if (g > p)
                    p++;
                else
                {
                    g++;
                    resl++;
                }
            }
        }
        WriteLine(resv - resl);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}