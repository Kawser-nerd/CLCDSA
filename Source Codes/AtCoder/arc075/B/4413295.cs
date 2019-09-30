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
        var nab = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        var hs = new int[nab[0]];
        for (var i = 0; i < nab[0]; i++)
            hs[i] = ToInt32(ReadLine());
        var left = 0L;
        var right = (hs.Max() + nab[2] - 1) / nab[2];
        while (right - left > 0)
        {
            var mid = (left + right) / 2;
            var ct = 0L;
            for (var i = 0; i < nab[0]; i++)
                if (mid * nab[2] < hs[i])
                    ct += (hs[i] - mid * nab[2] + nab[1] - nab[2] - 1) / (nab[1] - nab[2]);
            if (ct <= mid) right = mid;
            else left = mid+1;
        }
        WriteLine(left);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}