using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var n = ReadLine().Split().Select(int.Parse).ToList();
        var count = 0;
        for (int i = 0; i < n[0]; i++)
        {
            var s = ReadLine().Split().ToList();
            if (s[0] == "West")
            {
                if (int.Parse(s[1]) < n[1]) count -= n[1];
                else if (int.Parse(s[1]) > n[2]) count -= n[2];
                else count -= int.Parse(s[1]);
            }
            else
            {
                if (int.Parse(s[1]) < n[1]) count += n[1];
                else if (int.Parse(s[1]) > n[2]) count += n[2];
                else count += int.Parse(s[1]);
            }
        }
        var c = count < 0 ? "West" : "East";
        if (count == 0) WriteLine(0);
        else WriteLine($"{c} {Abs(count)}");
    }
}