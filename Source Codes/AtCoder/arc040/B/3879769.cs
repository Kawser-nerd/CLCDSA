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
        var nr = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var s = ReadLine();
        if (nr[0] == nr[1]) { WriteLine(s.Contains('.') ? 1 : 0);return; }
        var t = Max(0,s.LastIndexOf('.')+1-nr[1]);
        var i = 0;
        while (i < nr[0])
        {
            if (s[i] == '.') { t++; i += nr[1]; }
            else i++;
        }
        WriteLine(t);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}