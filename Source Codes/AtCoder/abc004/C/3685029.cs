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
        var num = ToInt32(ReadLine());
        var dif = num / 5;
        var r = "";
        for(var i = 0; i < 6; i++)
        {
            if (dif % 6 + i + 1 > 6) r += (dif % 6 + i + 1) % 6;
            else r += dif % 6 + i + 1;
        }
        for(var i = 0; i < num % 5; i++)
        {
            r = i != 0 ? r.Substring(0, i) + r.Substring(i + 1, 1) + r.Substring(i, 1) + r.Substring(i + 2) :
                r.Substring(i + 1, 1) + r.Substring(i, 1) + r.Substring(i + 2);
        }
        WriteLine(r);
    }
    
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}