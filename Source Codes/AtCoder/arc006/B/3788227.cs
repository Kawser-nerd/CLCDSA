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
        var nl = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ami = new string[nl[1]];
        for (var i = 0; i < nl[1]; i++)
            ami[i] = ReadLine();
        var cle = ReadLine().IndexOf("o");
        var now = cle;
        for(var i = nl[1] - 1; i >= 0; i--)
        {
            var ismove = false;
            if (now != 0 && ami[i][now - 1] == '-') { ismove = true; now -= 2; }
            if (!ismove&&now != 2 * (nl[0]-1) && ami[i][now + 1] == '-') now += 2;
        }
        WriteLine(now / 2 + 1);
    }
}