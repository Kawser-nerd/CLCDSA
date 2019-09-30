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
        var input = Array.ConvertAll(ReadLine().Split(), long.Parse);
        var x = input[0];
        var y = input[1];
        var select = ToInt64(ReadLine());
        WriteLine(select < y ? x + select : x+y - (select-y));
    }
    
}