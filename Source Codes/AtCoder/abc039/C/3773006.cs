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
        var str = ReadLine();
        var s = new[] { "Mi", "Re", "Do", "Si", "La", "So" ,"Fa"};
        var sa = str.IndexOf("WW");
        var si = str.IndexOf("WW", sa + 1);
        if (si - sa == 7) WriteLine(s[sa / 2]);
        else WriteLine(s[(sa / 2 + 3) % 7]);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}