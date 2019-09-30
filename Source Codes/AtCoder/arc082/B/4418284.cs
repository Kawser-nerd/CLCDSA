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
        var num = ToInt32(ReadLine());
        var ps = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var pp = new List<int>();
        for (var i = 0; i < num; i++)
            if (ps[i] == i + 1)
                pp.Add(i);
        var ct = 0;
        for(var i = 0; i < pp.Count-1; i++)
            if (pp[i] == pp[i + 1] - 1)
            {
                ct++;
                i++;
            }
        WriteLine(pp.Count - ct);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}