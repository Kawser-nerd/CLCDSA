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
        var input = ReadLine().Split(' ');
        var x = ToInt32(input[0])-1;
        var y = ToInt32(input[1])-1;
        var w = input[2];
        var cs = new string[9];
        for (var i = 0; i < 9; i++)
            cs[i] = ReadLine();
        var result = "";

        for (var i = 0; i < 4; i++)
        {
            result += cs[y][x];
            var isr = false;
            var isu = false;
            if (w.Contains("R"))
            {
                if (x == 8) { isr = true; w = w.Replace("R", "L"); }
                x = x == 8 ? 7 : x + 1;
            }
            if (w.Contains("U"))
            {
                if (y == 0) { isu = true; w = w.Replace("U", "D"); }
                y = y == 0 ? 1 : y - 1;
            }
            if (!isr&&w.Contains("L"))
            {
                if (x == 0) w = w.Replace("L", "R");
                x = x == 0 ? 1 : x - 1;
            }
            if (!isu&&w.Contains("D"))
            {
                if (y == 8) w = w.Replace("D", "U");
                y = y == 8 ? 7 : y + 1;
            }
        }
        WriteLine(result);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}