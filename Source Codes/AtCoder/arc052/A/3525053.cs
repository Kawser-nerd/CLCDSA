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
        for(var i = 0; i < str.Length; i++)
        {
            var d = 0;
            if (int.TryParse(str.Substring(i,1), out d))
            {
                var n = 0;
                if(i!=str.Length-1&&int.TryParse(str.Substring(i+1,1),out n))
                {
                    WriteLine(str.Substring(i, 2));return;
                }
                WriteLine(d);return;
            }
        }
    }
}