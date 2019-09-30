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
        ReadLine();
        var str = ReadLine();
        var res = "";
        var le = 0;
        var ri = 0;
        for(var i = 0; i < str.Length; i++)
        {
            var s = str.Substring(i, 1);
            res += s;
            if (s == "(") le++;
            else ri++;
            if (le < ri)
            {
                res = "(" + res;
                le=ri;
            }
        }
        for (var i = 0; i < le-ri; i++)
            res += ")";
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}