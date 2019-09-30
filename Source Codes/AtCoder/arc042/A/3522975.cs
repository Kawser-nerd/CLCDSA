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
        var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var num = input[0];
        var res = input[1];
        var sta = new Stack<int>();
        var ha = new HashSet<int>();
        for (var i = 0; i < res; i++)
            sta.Push(ToInt32(ReadLine()));
        while (sta.Count != 0)
        {
            var s = sta.Pop();
            if (!ha.Contains(s))
                WriteLine(s);
            ha.Add(s);
        }
        for (var i = 1; i <= num; i++)
            if (!ha.Contains(i))
                WriteLine(i);
    }
}