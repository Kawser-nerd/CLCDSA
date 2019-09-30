using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var p = double.Parse(ReadLine());
        var x = 1.5 * Math.Log(p*Math.Log(2.0, Math.E)/1.5, 2.0);
        if (x<0)
            WriteLine(p);
        else
            WriteLine(x + 1.5*Math.Log(Math.E, 2.0));
    }
}