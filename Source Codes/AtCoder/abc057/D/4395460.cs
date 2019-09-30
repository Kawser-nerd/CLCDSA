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
        var max = ar.Take(nab[1]).Average(v=>(double)v);
        WriteLine(max.ToString("0.#######"));
        var ct = ar.Count(v => v == ar[nab[1]-1]);
        var ctf = ar.Take(nab[1]).Count(v => v == ar[nab[1] - 1]);
        if (ctf != nab[1])
        {
            var r = ct;
            for(var i = 0; i < ctf-1; i++)
            {
                r *= ct - (i + 1);
                r /= (i + 2);
            }
            WriteLine(r);
            return;
        }
        var res = 0L;
        for(var i = nab[1]; i <= Min(ct,nab[2]); i++)
        {
            var pro = (long)ct;
            for(var j = 0; j < i-1; j++)
            {
                pro *= ct - (j + 1);
                pro /= (j + 2);
            }
            res += pro;
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}