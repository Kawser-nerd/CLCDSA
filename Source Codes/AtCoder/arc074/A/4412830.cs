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
        var hw = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        var res = long.MaxValue;
        for (var j = 0; j < 2; j++)
            for (var i = 1; i < hw[j]; i++)
            {
                var ar = new[] { i * hw[(j + 1) % 2], (hw[j] - i) * (hw[(j + 1) % 2] / 2), (hw[j] - i) * ((hw[(j + 1) % 2] + 1) / 2) };
                var ar2 = new[] { i * hw[(j + 1) % 2], hw[(j + 1) % 2] * ((hw[j] - i + 1) / 2), hw[(j + 1) % 2] * ((hw[j] - i) / 2) };
                res = Min(res, ar.Max() - ar.Min());
                res = Min(res, ar2.Max() - ar2.Min());
            }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}