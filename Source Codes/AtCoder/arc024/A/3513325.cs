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
        var left = ToInt32(input[0]);
        var right = ToInt32(input[1]);
        var lefts = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var rights = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var list = new List<int>();
        for (var i = 0; i < left; i++)
            if(!list.Contains(lefts[i])) list.Add(lefts[i]);
        var result = 0;
        for(var i = 0; i < list.Count(); i++)
        {
            var s = list[i];
            result += Min(lefts.Count(v => v == s), rights.Count(v => v == s));
        }
        WriteLine(result);
    }
}