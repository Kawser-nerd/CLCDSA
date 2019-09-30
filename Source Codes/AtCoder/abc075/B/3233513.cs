using System;
using System.Collections.Generic;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var height = ToInt32(input[0]);
        var width = ToInt32(input[1]);
        var bombs = new List<string>();
        for (var i = 0; i < height; i++)
        {
            var str = ReadLine();
            for (var j = 0; j < width; j++)
            {
                if (str.Substring(j, 1) == "#") bombs.Add($"{i} {j}");
            }
        }

        for (var i = 0; i < height; i++)
        {
            for (var j = 0; j < width; j++)
            {
                var counter = 0;
                var isbomb = false;
                for (var h = 0; h < bombs.Count; h++)
                {
                    var bomb = bombs[h].Split(' ');
                    var hei = ToInt32(bomb[0]);
                    var wid = ToInt32(bomb[1]);
                    if (i == hei && wid == j) { isbomb = true; break; }
                    if (Math.Abs(i - hei) <= 1 && Math.Abs(j - wid) <= 1) counter++;
                }
                if (!isbomb) Write(counter);
                else Write("#");
            }
            WriteLine();
        }
    }
}