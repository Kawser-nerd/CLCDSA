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
        var abc = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        if (abc[0] % 2 == 1 || abc[1] % 2 == 1 || abc[2] % 2 == 1) { WriteLine(0);return; }
        if (abc[0] == abc[1] && abc[0] == abc[2]) { WriteLine(-1);return; }
        var result = 0L;
        while (abc[0] % 2 == 0 && abc[1] % 2 == 0 && abc[2] % 2 == 0)
        {
            var a = abc[0];
            var b = abc[1];
            var c = abc[2];
            abc[0] = b / 2 + c / 2;
            abc[1] = a / 2 + c / 2;
            abc[2] = a / 2 + b / 2;
            result++;
        }
        WriteLine(result);
    }
}