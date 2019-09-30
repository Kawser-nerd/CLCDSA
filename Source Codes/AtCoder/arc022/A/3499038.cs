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
        if ((str.Contains("i")||str.Contains("I"))&& (str.Contains("t")||str.Contains("T")))
        {
            var i = str.IndexOf("I",0,str.Length,StringComparison.OrdinalIgnoreCase);
            var t = str.LastIndexOf("T",str.Length-1,str.Length,StringComparison.OrdinalIgnoreCase);
            for (var j = i; j < t; j++) if (str[j] == 'C'||str[j]=='c') { WriteLine("YES"); return; }
            WriteLine("NO");
        }
        else WriteLine("NO");
    }
    
}