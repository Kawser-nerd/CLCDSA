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
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var pp = new int[num];
        for(var i = 0; i < num; i++)
            if (ar[i] % 4 == 0)
                pp[i] = 2;
            else if (ar[i] % 2 == 0)
                pp[i] = 1;
        var ct4 = pp.Count(v => v == 2);
        var ct2 = pp.Count(v => v == 1);
        var res = num - 2 * ct4 - ct2 - (ct2 == 0 ? 1 : 0);
        WriteLine(res <= 0 ? "Yes" : "No");
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}