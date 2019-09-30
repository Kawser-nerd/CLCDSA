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
        var nab = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        ar = ar.OrderByDescending(v => v).ToArray();
        var max = ar.Take(nab[1]).Average(v => (double)v);
        WriteLine(max.ToString("0.#######"));
        var ct = ar.Count(v => v == ar[nab[1] - 1]);
        var ctf = ar.Take(nab[1]).Count(v => v == ar[nab[1] - 1]);
        if (ctf != nab[1])
        {
            var res = (long)ct;
            for(var i = 0; i < ctf-1; i++)
            {
                res *= ct - (i + 1);
                res /= (i + 2);
            }
            WriteLine(res);
            return;
        }
        var r = 0L;
        for(var i = ctf; i <= Min(nab[2], ct); i++)
        {
            var pro = (long)ct;
            for(var j = 1; j < i; j++)
            {
                pro *= ct - j;
                pro /= (j + 1);
            }
            r += pro;
        }
        WriteLine(r);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}