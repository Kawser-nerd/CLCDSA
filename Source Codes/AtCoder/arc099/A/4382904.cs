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
        var nk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        WriteLine(Ceiling((double)(nk[0] - 1) / (nk[1] - 1)));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}