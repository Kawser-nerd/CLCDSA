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
        var qu = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for (var i = 0; i < 4; i++)
        {
            str = str.Insert(qu[i]+i, "\"");
        }
        WriteLine(str);
    }
}