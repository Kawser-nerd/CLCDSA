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
        var num = ToInt32(ReadLine());
        var wo = new string[num];
        for (var i = 0; i < num; i++)
            wo[i] = ReadLine();
        var set = new HashSet<string> { wo[0] };
        for(var i = 1; i < num; i++)
        {
            var c = wo[i-1].Substring(wo[i-1].Length - 1);
            if (c != wo[i].Substring(0, 1))
            {
                WriteLine(i % 2 == 0 ? "LOSE" : "WIN");
                return;
            }
            if (set.Contains(wo[i]))
            {
                WriteLine(i % 2 == 0 ? "LOSE" : "WIN");
                return;
            }
            
            set.Add(wo[i]);
        }
        WriteLine("DRAW");
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}