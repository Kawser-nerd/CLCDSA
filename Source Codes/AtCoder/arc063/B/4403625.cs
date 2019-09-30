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
        var nt = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var min = ar[0];
        var dif = new int[nt[0]];
        for(var i = 1; i < nt[0]; i++)
        {
            if (min > ar[i])
            {
                min = ar[i];
                dif[i] = 0;
            }
            else
                dif[i] = ar[i] - min;
        }
        var max = dif.Max();
        WriteLine(dif.Count(v => v == max));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}