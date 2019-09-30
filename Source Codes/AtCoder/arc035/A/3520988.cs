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
        var le = str.Substring(0, str.Length / 2);
        var ri = str.Substring((int)Ceiling((double)str.Length / 2));
        for(var i = 0; i < le.Length; i++)
            if(le[i]!='*'&&
                ri[le.Length-i-1]!='*'&&
                le[i] != ri[le.Length - i - 1]) { WriteLine("NO");return; }
        
        WriteLine("YES");
    }
}