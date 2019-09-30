using System;
using System.Collections.Generic;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var colors = Array.ConvertAll(ReadLine().Split(' '), string.Concat);
        var kind = new HashSet<string>();
        for(var i = 0; i < num; i++)
        {
            kind.Add(colors[i]);
        }
        WriteLine(kind.Count == 3 ? "Three" : "Four");
    }
}