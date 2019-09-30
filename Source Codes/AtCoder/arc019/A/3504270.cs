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
        var result = "";
        for(var i = 0;i<str.Length;i++)
        {
            var s = str.Substring(i, 1);
            var r = 0;
            if (int.TryParse(s, out r))
            {
                result += s;
            }
            else
            {
                switch (s)
                {
                    case "O":
                        result += 0;
                        break;
                    case "D":
                        result += 0;
                        break;
                    case "I":
                        result += 1;
                        break;
                    case "Z":
                        result += 2;
                        break;
                    case "S":
                        result += 5;
                        break;
                    case "B":
                        result += 8;
                        break;
                }
            }
        }
        WriteLine(result);
    }
}